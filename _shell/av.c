#include <stdio.h>

/**
* main - Entry of app
* @argc: Number of arguments to the program
* @argv: NULL terminated list of the program arguments
*
* Return: Always 0, error otherwise
*/
int main(__attribute__((unused)) int ac, char **av)
{
	size_t i;

	i = 0;
	while(av[i])
	{
		printf("%s\n", av[i++]);
	}

	return (0);
}
