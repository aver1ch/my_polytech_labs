#ifndef EXPRESSION_PARSER_COMMON_H
#define EXPRESSION_PARSER_COMMON_H

#include <string>

namespace averich
{
  bool isNumber(const std::string& s);
  bool isOperator(const std::string& s);
  bool isLeftParenthesis(const std::string& s);
  bool isRightParenthesis(const std::string& s);
  size_t operatorPrecendence(char op);
  bool operatorPrecendenceGreaterOrEqual(char op1, char op2);
  int64_t operatorPlus(int64_t a, int64_t b);
  int64_t operatorMinus(int64_t a, int64_t b);
  int64_t operatorMultiply(int64_t a, int64_t b);
  int64_t operatorDivision(int64_t a, int64_t b);
  int64_t operatorModulus(int64_t a, int64_t b);
}

#endif
