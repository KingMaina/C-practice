#include "main.h"

#define BUFF_SIZE 1024
#define DELIM " \t\n"

/**
* main - Entry of app
*
* Return: Always 0, error otherwise if non-zero
*/
int main(void)
{
	char **tokens = NULL;
	char *buffer = NULL;
	size_t buff_len = 0;
	ssize_t bytesRead = -1;

	while (1)
	{
		print_prompt();
		bytesRead = getline(&buffer, &buff_len, stdin);
		if (bytesRead == -1)
		{
			printf("Error\n");
			free(buffer);
			return (EXIT_SUCCESS);
		}
		if (buffer[0] == '\n')
		{
			free(buffer);
			buff_len = 0;
			continue;
		}
		if (strstr(buffer, "exit\n"))
			break;
		tokens = tokenize(buffer, DELIM);
		if (tokens == NULL)
			break;
		free_buffer(buffer);
		free_tokens(&tokens);
		buff_len = 0;
	}

	return (EXIT_SUCCESS);
}
