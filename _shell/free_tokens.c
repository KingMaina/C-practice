#include "main.h"

/**
* free_tokens - De-allocates memory allocated
* to an array list of tokens
* @tokens: Address of pointer to array of tokens
*
* Return: void
*/
void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i++]);
	}
	free(tokens);
	tokens = NULL;
}
