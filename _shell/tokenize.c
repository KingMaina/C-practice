#include "main.h"

#define BUFFER_SIZE 1024

/**
* tokenize - Breaks down a delimitered string
* into an array of tokens
* @str: String to tokenize
* @delim: Delimeter
*
* Return: Pointer to an array of token strings, NULL otherwise
*/
char **tokenize(char *str, char *delim)
{
	char **tokens = NULL;
	size_t num_of_toks = 0;
	size_t max_toks = BUFFER_SIZE;
	size_t tok_len = 0;
	size_t toks_len = 0;

	tokens = malloc(sizeof(*tokens) * max_toks);
	if (tokens == NULL)
		return (NULL);
	tokens[num_of_toks] = strtok(str, delim);
	while (tokens[num_of_toks] != NULL)
	{
		if (num_of_toks >= max_toks)
		{
			fprintf(stderr, "Error: Maximum numbre of tokens reached");
			return (NULL);
		}
		num_of_toks++;
		tokens[num_of_toks] = strtok(NULL, DELIM);
	}
	tokens[num_of_toks] = NULL;
	return (tokens);
}
