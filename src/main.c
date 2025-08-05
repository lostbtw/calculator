#include "main.h"
#include "expression_handler.h"
int main() {
    bool running = true;
    char* command = (char*) calloc(MAX_COMMAND_SIZE, sizeof(char));
    double result = 0;

    while(running){
        printf("Calculator\n");
        printf("Write your expression (e.g. '24+656=')\n");
        printf("To exit the program write 'e' or 'exit' (case insensitive)\n");
        scanf("%s", command);
        enum ExpressionValidatorOutput output = validateExpression(command);
        switch(output){
            case EXIT_CODE:
                running = false;
                break;
            case ERR_INVALID_CHAR:
                printf("ERROR: Invalid char used in expression\n");
                break;
            case ERR_EMPTY_EXPRESSION:
                printf("ERROR: Empty expression\n");
                break;
            case ERR_DIVISION_BY_ZERO:
                printf("ERROR: Division by zero\n");
                break;
            case ERR_SYNTAX:
                printf("ERROR: Invalid syntax\n");
                break;
            case ERR_UNKNOWN:
                printf("ERROR: Unknown error (that's not supposed to happen\n");
                break;
            case VALID_EXPRESSION:
                result = solveExpression(command);
                printf("%s = %lf\n", command, result);
                break;
            default:
                printf("ERROR: Undefined behaviour\n");
                break;
        }
    }

    free(command);
    return 0;
}
