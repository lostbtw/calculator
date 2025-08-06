#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char* expr_ptr;

void skip_spaces();
double parse_expression();
double parse_term();
double parse_factor();
double parse_number();

#endif