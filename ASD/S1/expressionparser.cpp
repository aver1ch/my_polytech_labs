#include "expressionparser.h"

#include "expressionparsercommon.h"
#include "queue.h"
#include "stack.h"

namespace averich
{
  struct TokenRange
  {
    size_t begin, end;
  };
  TokenRange findNextToken(const std::string& str, size_t fromPos)
  {
    constexpr char spaceSymbol = ' ';
    size_t begin = str.find_first_not_of(spaceSymbol, fromPos);
    size_t end = str.find_first_of(spaceSymbol, begin);
    return {begin, end};
  }
  Queue< std::string > parseExpression(const std::string& expression)
  {
    if (expression.empty())
    {
      return {};
    }
    Stack< std::string > stack;
    Queue< std::string > queue;
    TokenRange tokenRange = findNextToken(expression, 0);
    while (tokenRange.begin != std::string::npos)
    {
      size_t tokenSize = tokenRange.end == std::string::npos ? std::string::npos : tokenRange.end - tokenRange.begin;
      std::string token = expression.substr(tokenRange.begin, tokenSize);
      tokenRange = findNextToken(expression, tokenRange.end);
      if (isNumber(token))
      {
        queue.push_back(token);
        continue;
      }
      if (isOperator(token))
      {
        while (!stack.is_empty() && isOperator(stack.get_top()))
        {
          if (operatorPrecendenceGreaterOrEqual(stack.get_top().front(), token.front()))
          {
            queue.push_back(stack.get_top());
            stack.pop();
          }
        }
        stack.push(token);
        continue;
      }
      if (isLeftParenthesis(token))
      {
        stack.push(token);
        continue;
      }
      if (isRightParenthesis(token))
      {
        bool foundLeftParenthesis = false;
        while (!stack.is_empty())
        {
          if (isLeftParenthesis(stack.get_top()))
          {
            foundLeftParenthesis = true;
            stack.pop();
            break;
          }
          queue.push_back(stack.get_top());
          stack.pop();
        }
        if (!foundLeftParenthesis)
        {
          throw std::runtime_error("Expression is invalid: unpaired right parenthesis found");
        }
        continue;
      }
      throw std::runtime_error("Expression is invalid: unsupported token found");
    }
    while (!stack.is_empty())
    {
      if (isLeftParenthesis(stack.get_top()))
      {
        throw std::runtime_error("Expression is invalid: unpaired left parenthesis found");
      }
      queue.push_back(stack.get_top());
      stack.pop();
    }
    return queue;
  }
}
