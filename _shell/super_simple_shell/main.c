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
	// get user input (getline) - store in buffer
	// tokenize command input into tokens (program name and arguments)
	// Search program in PATH

	// Backend:
	// DEtermine type of command execution type - single, sequential, pipe, &&, ||
	// Create process for execting jobs
	// Execute commands - execve(program name, arg_list, env_arr)
/*	char *args[] = { "/bin/ls", "-l", "/tmp", NULL }; */
	char *args = NULL;
	char **tokens = NULL;
	size_t args_len = 0;
	size_t toks_len = 0;
	int i  = 0, child_status = 0;
	pid_t pid;

	while (1)
	{
		prompt();

		while((args_len = getline(&args, &args_len, stdin)) != -1)
		{
			printf("Number of bytes read %zd\n", args_len);
			printf("Input: %s\n", args);
			break;
		}
	}

/*	while (i++ < 5)
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
*/
	return (EXIT_SUCCESS);
}
