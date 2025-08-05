#include "expression_handler.h"
enum ExpressionValidatorOutput validateExpression(char* expr){
    if (expr == NULL || *expr == '\0') return ERR_EMPTY_EXPRESSION;

    if(*expr == 'e'){
        return EXIT_CODE;
    }

    int paren_balance = 0;
    char prev = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c == ' ') continue;

        if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
            if (c == '(') paren_balance++;
            else if (c == ')') {
                paren_balance--;
                if (paren_balance < 0)
                    return ERR_SYNTAX;
            }
            // Catch invalid sequences like "++", "+*", "*/", etc.
            if ((prev == '+' || prev == '-' || prev == '*' || prev == '/') &&
                (c == '+' || c == '-' || c == '*' || c == '/')) {
                return ERR_SYNTAX;
            }
            prev = c;
        }
        else {
            return ERR_INVALID_CHAR;
        }
    }

    if (paren_balance != 0)
        return ERR_SYNTAX;

    return VALID_EXPRESSION;
}


double solveExpression(char* command){
    if(validateExpression(command) != VALID_EXPRESSION){
        return 0;
    }
    return 1; // TODO: implement solving
}