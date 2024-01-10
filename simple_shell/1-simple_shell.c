#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
char command[MAX_COMMAND_LENGTH];
pid_t pid;

while (1)
{
printf("$ ");

if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
if (feof(stdin)) {
printf("\nGoodbye!\n");
exit(EXIT_SUCCESS);
} else {
perror("Error reading command");
exit(EXIT_FAILURE);
}
}

command[strcspn(command, "\n")] = '\0';

pid = fork();

if (pid == -1) {
perror("Fork failed");
exit(EXIT_FAILURE);
} else if (pid == 0) {
if (execlp(command, command, NULL) == -1) {
perror("Command not found");
exit(EXIT_FAILURE);
}
} else {
int status;
waitpid(pid, &status, 0);

if (WIFEXITED(status)) {
printf("Command executed successfully with status %d\n", WEXITSTATUS(status));
} else {
printf("Error executing command\n");
}
}
}

return 0;
}
