#include "isexpression.h"

#include <cctype>

struct FindResult {
  bool found;
  const char* end;
};

FindResult findExpression(const char* data);

bool isOpenBracket(char ch)
{
  return ch == '(';
}

bool isCloseBracket(char ch)
{
  return ch == ')';
}

bool isMultiplierTermOperator(char ch)
{
  return ch == '/' || ch == '*';
}

bool isTermExpressionOperator(char ch)
{
  return ch == '+' || ch == '-';
}

bool isLetter(char ch)
{
  return (ch >= 'a' && ch <= 'f') || (ch >= 'x' && ch <= 'z');
}

bool isDigit(char ch)
{
  return std::isdigit(ch);
}

bool isEnd(char ch)
{
  return ch == '\0';
}

FindResult findId(const char* data)
{
  if (isLetter(*data)) {
    return {true, data + 1};
  }
  return {false, data};
}

const char* findEndOfUnsignedInteger(const char* data)
{
  if (isDigit(*data)) {
    return findEndOfUnsignedInteger(data + 1);
  }
  return data;
}

FindResult findUnsignedInteger(const char* data)
{
  const char* end = findEndOfUnsignedInteger(data);
  return {data != end, end};
}

FindResult findPairForOpenBracket(const char* data, size_t openedBracketsFound = 0)
{
  if (isEnd(*data)) {
    return {false, data};
  }
  if (isOpenBracket(*data)) {
    ++openedBracketsFound;
  } else if (openedBracketsFound == 0) {
    return {false, data};
  }
  if (isCloseBracket(*data)) {
    --openedBracketsFound;
    if (openedBracketsFound == 0) {
      return {true, data + 1};
    }
  }
  return findPairForOpenBracket(data + 1, openedBracketsFound);
}

FindResult findMultiplier(const char* data)
{
  FindResult result = findUnsignedInteger(data);
  if (!result.found) {
    result = findId(data);
    if (!result.found) {
      result = findPairForOpenBracket(data);
      if (result.found) {
        result = findExpression(data + 1);
        if (result.found && !isEnd(*result.end)) {
          ++result.end;
        }
      }
    }
  }
  return result;
}

FindResult findTerm(const char* data)
{
  FindResult result = findMultiplier(data);
  if (result.found && !isEnd(*result.end)) {
    if (isMultiplierTermOperator(*result.end)) {
      result = findTerm(result.end + 1);
    }
  }
  return result;
}

FindResult findExpression(const char* data)
{
  FindResult result = findTerm(data);
  if (result.found && !isEnd(*result.end)) {
    if (isTermExpressionOperator(*result.end)) {
      result = findExpression(result.end + 1);
    }
  }
  return result;
}

bool isExpression(const char* data)
{
  FindResult result = findExpression(data);
  return result.found && isEnd(*result.end);
}
