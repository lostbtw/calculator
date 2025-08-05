#ifndef EXPRESSION_HANDLER_H
#define EXPRESSION_HANDLER_H
#include <stdio.h>
#include <ctype.h>
enum ExpressionValidatorOutput{
    VALID_EXPRESSION,
    EXIT_CODE,
    ERR_DIVISION_BY_ZERO,
    ERR_INVALID_CHAR,
    ERR_SYNTAX,
    ERR_EMPTY_EXPRESSION,
    ERR_UNKNOWN

};
enum ExpressionValidatorOutput validateExpression(char* command);
double solveExpression(char* command);
#endif
