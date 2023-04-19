#include "main.h"

/**
* main - Entry of app
* @argc: Number of arguments to the program
* @argv: NULL terminated list of the program arguments
*
* Return: Always 0, error otherwise
*/
int main(void)
{
	char **tokens = NULL;
	char *buffer = NULL;
	size_t buff_len = 0, i;
	ssize_t bytesRead = -1;

	while (1)
	{
		print_prompt();
		bytesRead = getline(&buffer, &buff_len, stdin);
		if (bytesRead == -1)
		{
			printf("Error\n");
			return (EXIT_FAILURE);
		}
		if (buffer[0] == '\n')
			continue;
		if (strstr(buffer, "exit\n"))
			break;
		printf("%s", buffer);
		buff_len = strlen(buffer);
		tokens = tokenize(buffer, buff_len);
		if (tokens == NULL)
			break;
		for (i = 0; tokens[i] != NULL; i++)
			printf("%s\n", tokens[i]);
	}
	if (tokens != NULL)
		free_tokens(tokens);
	free(buffer);

	return (EXIT_SUCCESS);
}
