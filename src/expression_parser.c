#include "expression_parser.h"

void skip_spaces() {
    while (*expr_ptr == ' ') expr_ptr++;
}

double parse_expression() {
    double result = parse_term();

    while (1) {
        skip_spaces();
        if (*expr_ptr == '+') {
            expr_ptr++;
            result += parse_term();
        } else if (*expr_ptr == '-') {
            expr_ptr++;
            result -= parse_term();
        } else {
            break;
        }
    }

    return result;
}

double parse_term() {
    double result = parse_factor();

    while (1) {
        skip_spaces();
        if (*expr_ptr == '*') {
            expr_ptr++;
            result *= parse_factor();
        } else if (*expr_ptr == '/') {
            expr_ptr++;
            double divisor = parse_factor();
            if (divisor == 0) {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            result /= divisor;
        } else {
            break;
        }
    }

    return result;
}

double parse_factor() {
    skip_spaces();

    if (*expr_ptr == '-') {
        expr_ptr++; // skip '-'
        return -parse_factor(); // apply minus to the next factor
    }

    if (*expr_ptr == '(') {
        expr_ptr++; // skip '('
        double result = parse_expression();
        skip_spaces();
        if (*expr_ptr == ')') {
            expr_ptr++; // skip ')'
            return result;
        } else {
            printf("Error: Missing closing parenthesis\n");
            exit(EXIT_FAILURE);
        }
    } else {
        return parse_number();
    }
}

double parse_number() {
    skip_spaces();
    char* end_ptr;
    double value = strtod(expr_ptr, &end_ptr);
    if (expr_ptr == end_ptr) {
        printf("Error: Expected number at '%s'\n", expr_ptr);
        exit(EXIT_FAILURE);
    }
    expr_ptr = end_ptr;
    return value;
}

