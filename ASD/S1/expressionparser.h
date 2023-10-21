#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>

#include "queue.h"

namespace averich
{
  Queue< std::string > parseExpression(const std::string& expression);
}

#endif
