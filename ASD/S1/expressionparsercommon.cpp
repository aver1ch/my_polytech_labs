#include "expressionparsercommon.h"

#include <stdexcept>

namespace averich
{
  bool isNumber(const std::string& s)
  {
    if (s.size() < 1)
    {
      return false;
    }
    for (char ch : s)
    {
      if (!isdigit(ch))
      {
        return false;
      }
    }
    return true;
  }
  bool isOperator(const std::string& s)
  {
    if (s.size() != 1)
    {
      return false;
    }
    char ch = s.front();
    return ch == '*' || ch == '-' || ch == '/' || ch == '%' || ch == '+';
  }
  size_t operatorPrecendence(char op)
  {
    size_t precendence = 0;
    switch (op)
    {
    case '*':
    case '/':
    case '%':
      precendence = 2;
      break;
    case '+':
    case '-':
      precendence = 1;
      break;
    default:
      throw std::runtime_error("Unknown operator");
    };
    return precendence;
  }
  bool operatorPrecendenceGreaterOrEqual(char op1, char op2)
  {
    return operatorPrecendence(op1) >= operatorPrecendence(op2);
  }
  bool isLeftParenthesis(const std::string& s)
  {
    if (s.size() != 1)
    {
      return false;
    }
    char ch = s.front();
    return ch == '(';
  }
  bool isRightParenthesis(const std::string& s)
  {
    if (s.size() != 1)
    {
      return false;
    }
    char ch = s.front();
    return ch == ')';
  }
  int64_t operatorPlus(int64_t a, int64_t b)
  {
    if (b < 0)
    {
      return operatorMinus(a, b);
    }
    if (a > 0 && (a + b < 0))
    {
      throw std::runtime_error("Overlow in operation \"Addition\"");
    }
    return a + b;
  }
  int64_t operatorMinus(int64_t a, int64_t b)
  {
    if (b < 0)
    {
      return operatorPlus(a, b);
    }
    if (a < 0 && a - b > 0)
    {
      throw std::runtime_error("Overlow in operation \"Substraction\"");
    }
    return a - b;
  }
  int64_t operatorMultiply(int64_t a, int64_t b)
  {
    int64_t result = a * b;
    if (a != 0 && result / a != b)
    {
      throw std::runtime_error("Overlow in operation \"Multiplication\"");
    }
    return result;
  }
  int64_t operatorDivision(int64_t a, int64_t b)
  {
    return a / b;
  }
  int64_t operatorModulus(int64_t a, int64_t b)
  {
    return ((a % b) + b) % b;
  }
}
