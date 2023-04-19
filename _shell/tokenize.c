#include "main.h"

#define DELIM " \n\t"
#define BUFFER_SIZE 1024

/**
* tokenize - Breaks down a delimitered string
* into an array of tokens
* @str: String to tokenize
* @str_len: Length of the string
*
* Return: Pointer to an array of token strings, NULL otherwise
*/
char **tokenize(char *str, size_t str_len)
{
	char *buffer = NULL;
	char **tokens = NULL;
	char *token = strtok(str, DELIM);
	size_t num_of_toks = 0;
	size_t buff_len = 0;
	size_t max_toks = BUFFER_SIZE;
	size_t tok_len = 0;

	buffer = malloc(sizeof(*buffer) * (str_len + 1));
	if (buffer == NULL)
	{
		fprintf(stderr, "Error allocating buffer memory, aborting...");
		return (NULL);
	}
	tokens = malloc(sizeof(*tokens) * BUFFER_SIZE);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error allocating buffer memory, aborting...");
		free(buffer);
		return(NULL);
	}
	while (token != NULL)
	{
		if (num_of_toks >= max_toks)
		{
			fprintf(stderr, "Error: Maximum numbre of tokens reached");
			free(buffer);
			free_tokens(tokens);
			return(NULL);
		}
		tok_len = strlen(token);
		memcpy(buffer + buff_len, token, tok_len);
		buffer[buff_len + tok_len] = '\0';
		tokens[num_of_toks] = buffer + buff_len;
		buff_len += tok_len + 1;
		num_of_toks++;
		token = strtok(NULL, DELIM);
	}
	tokens[num_of_toks] = NULL;

	return (tokens);
}
