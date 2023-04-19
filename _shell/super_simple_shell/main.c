#include "shell.h"

/**
* main - Entry point of shell program
* @argc: Number of arguments of the program
* @argv: NULL terminated list of arguments to the program
*
* Return: Always 0, error otherwise
*/
int main(void)
{
	// Frontend
	// create infinite loop
	// prompt user
	char *args[] = { "/bin/ls", "-l", "/tmp", NULL };
	pid_t pid;
	int i  = 0, child_status = 0;

	while (i++ < 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error creating process");
			return (EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error executing program");
				return (EXIT_FAILURE);
			}
		}
		else
		{
			printf("Waiting for %u to finish\n", pid);
			wait(&child_status);
		}
	}
	// get user input (getline) - store in buffer
	// tokenize command input into tokens (program name and arguments)
	// Search program in PATH

	// Backend:
	// DEtermine type of command execution type - single, sequential, pipe, &&, ||
	// Create process for execting jobs
	// Execute commands - execve(program name, arg_list, env_arr)

	return (EXIT_SUCCESS);
}
