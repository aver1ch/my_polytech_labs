#include "expressionevaluator.h"

#include <iostream>

#include "expressionparser.h"
#include "expressionparsercommon.h"
#include "queue.h"
#include "stack.h"

namespace averich
{
  int64_t evaluateExpression(const std::string& expression)
  {
    Queue< std::string > queue = parseExpression(expression);
    if (queue.is_empty())
    {
      throw std::runtime_error("Expression is incorrect: given string is empty");
    }
    Stack< int64_t > computationStack;
    while (!queue.is_empty())
    {
      std::string token = queue.get_front();
      queue.pop_front();
      if (isNumber(token))
      {
        const int64_t number = std::stoll(token.c_str());
        if (token.c_str()[token.size() - 1] - 48 != number % 10)
        {
          throw std::runtime_error("Bad argument");
        }
        computationStack.push(number);
        continue;
      }
      char op = token.front();
      int64_t operand_2 = computationStack.get_top();
      computationStack.pop();
      int64_t operand_1 = computationStack.get_top();
      computationStack.pop();
      switch (op)
      {
      case '+':
        computationStack.push(operatorPlus(operand_1, operand_2));
        break;
      case '-':
        computationStack.push(operatorMinus(operand_1, operand_2));
        break;
      case '*':
        computationStack.push(operatorMultiply(operand_1, operand_2));
        break;
      case '/':
        computationStack.push(operatorDivision(operand_1, operand_2));
        break;
      case '%':
        computationStack.push(operatorModulus(operand_1, operand_2));
        break;
      default:
        throw std::runtime_error("Expression is incorrect: unsupported type of operator");
        break;
      }
    }
    return computationStack.get_top();
  }
}
