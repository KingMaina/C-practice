#include "main.h"

/**
* free_buffer - De-allocates memory allocated
* to the command input buffer
* @buffer: Input buffer string
*
* Return: void
*/
void free_buffer(char *buffer)
{
	if (buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
}

/**
* free_tokens - De-allocates memory allocated
* to an array list of tokens
* @tokens: Address of pointer to array of tokens
*
* Return: void
*/
void free_tokens(char ***tokens)
{
	if (*tokens != NULL)
	{
		free(*tokens++);
		*tokens = NULL;
	}
}
