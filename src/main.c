#include "main.h"

int main() {
    bool running = true;
    char* command = (char*) calloc(MAX_COMMAND_SIZE, sizeof(char));

    while(running){
        printf("Calculator\n");
        printf("Write your expression (e.g. '24+656=')\n");
        printf("To exit the program write 'e' or 'exit' (case insensitive)\n");
        scanf("%s", command);
        if(*command == 'e'){
            running = false;
        }
    }

    free(command);
    return 0;
}
