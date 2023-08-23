#include "shell.h"
/**
 *
 *
 *
 *
 *
 *
 *
 */
int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH];
    const char *delim = " \t\n";
    pid_t child_pid;

    while (1) {
	   _printf("SimpleShell> ");
	   fgets(input, MAX_INPUT_LENGTH, stdin);
	   
	   int arg_count = 0;
	   args[arg_count] = strtok(input, delim);
	   while (args[arg_count] != NULL) 
	   {
		   arg_count++;
		   args[arg_count] = strtok(NULL, delim);
	   }

	   if (arg_count > 0) {
		   if (access(args[0], X_OK) == 0) {
			   child_pid = fork();
			   if (child_pid == 0) {

				   execv(args[0], args);
				   perror("execv");
				   exit(EXIT_FAILURE);
			   } else if (child_pid > 0) {
				   waitpid(child_pid, NULL,0);
			   } else
		{
                    perror("fork");
                }
            } else {
                printf("Command not found: %s\n", args[0]);
            }
        }
    }

    return 0;
}
