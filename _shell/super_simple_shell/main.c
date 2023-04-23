#include "shell.h"

#define DELIM " \n\t"
#define BUFFER_SIZE 1024

/**
* main - Entry point of shell program
* @argc: Number of arguments of the program
* @argv: NULL terminated list of arguments to the program
*
* Return: Always 0, error otherwise
*/
int main(__attribute__((unused)) int ac, char **argv, char **env)
{
/*	char *args[] = { "/bin/ls", "-l", "/tmp", NULL }; */
	char *args = NULL;
	char *out_buff = NULL;
	char **tokens = NULL;
	char *token = NULL;
	size_t args_len = 0;
	size_t out_buff_len = 0;
	size_t tok_len = 0;
	size_t num_of_toks = 0;
	ssize_t bytesRead = -1;
	size_t i  = 0;
	pid_t pid;
	int child_status = 0;
	char *err_buff = NULL;
	size_t err_buff_len = 0;


	while (1)
	{
		prompt();
		bytesRead = getline(&args, &args_len, stdin);
		if (bytesRead == -1)
		{
			break;
		}
		args_len = strlen(args);
		token = strtok(args, DELIM);
		out_buff = malloc(sizeof(*out_buff) * (args_len + 1));
		if (out_buff == NULL)
		{
			perror("Error: ");
			break;
		}
		tokens = malloc(sizeof(*tokens) * BUFFER_SIZE);
		if (tokens == NULL)
		{
			perror("Error allocating memory for token ids");
			break;
		}
		for (i = 0; token != NULL; i++)
		{
			tok_len = strlen(token);
			memcpy(out_buff + out_buff_len, token, tok_len);
			out_buff[out_buff_len + tok_len] = '\0';
			tokens[num_of_toks] = out_buff + out_buff_len;
			out_buff_len += tok_len + 1;
			num_of_toks++;
			token = strtok(NULL, DELIM);
		}
		tokens[num_of_toks] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("Error creating process");
			break;
		}
		if (pid == 0)
		{
			if (execve(tokens[0], tokens, env) == -1)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], tokens[0]);
				break;
			}
		}
		else
		{
			wait(&child_status);
		}
		free(out_buff);
		free(tokens);
		free(args);
		out_buff = NULL;
		tokens = NULL;
		args = NULL;
		out_buff_len = 0;
		args_len = 0;
		num_of_toks = 0;
	}
	if (args != NULL)
	{
		free(args);
		args = NULL;
	}
	if (out_buff != NULL)
	{
		free(out_buff);
		out_buff = NULL;
	}
	if (tokens != NULL)
	{
		free(tokens);
		tokens = NULL;
	}

	return (EXIT_SUCCESS);
}
