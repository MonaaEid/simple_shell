#include "shell.h"

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 100

void executeCommand(char *command) {
    char *args[MAX_COMMAND_LENGTH];
    int arg_count = 0;

    char *token = strtok(command, " ");
    while (token != NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    pid_t pid = fork();
    if (pid == 0) {
        
        execvp(args[0], args);
        perror("Execution failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Command failed\n");
        }
    } else {
        perror("Fork failed");
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Shell $:):\n");

    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

    char *commands[MAX_COMMANDS];
    int command_count = 0;

    
    char *token = strtok(input, "&&||");
    while (token != NULL) {
        commands[command_count++] = token;
        token = strtok(NULL, "&&||");
    }

    
    int index = 0;
    int success = 1; 
    
    while (index < command_count) {
        int result;
        executeCommand(commands[index]);
        
        if (success && index < command_count - 1) {
            if (strstr(commands[index + 1], "&&") != NULL) {
                result = 1;
            } else if (strstr(commands[index + 1], "||") != NULL) {
                result = 0;
            } else {
                fprintf(stderr, "Invalid logical operator\n");
                return EXIT_FAILURE;
            }
            index++;
            success = result;
        } else if (!success && index < command_count - 1) {
            if (strstr(commands[index + 1], "&&") != NULL) {
                result = 0;
            } else if (strstr(commands[index + 1], "||") != NULL) {
                result = 1;
            } else {
                fprintf(stderr, "Invalid logical operator\n");
                return EXIT_FAILURE;
            }
            index++;
            success = result;
        }
        index++;
    }

    return EXIT_SUCCESS;
}
