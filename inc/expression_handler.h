#ifndef EXPRESSION_HANDLER_H
#define EXPRESSION_HANDLER_H
#include <stdio.h>
#include <ctype.h>

typedef enum {
    VALID_EXPRESSION,
    EXIT_CODE,
    ERR_DIVISION_BY_ZERO,
    ERR_INVALID_CHAR,
    ERR_SYNTAX,
    ERR_EMPTY_EXPRESSION,
    ERR_UNKNOWN

} ExpressionValidatorOutput;
ExpressionValidatorOutput validateExpression(char* command);
double solveExpression(char* command);
#endif
