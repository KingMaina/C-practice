#include <stdio.h>

extern char **environ;
/**
* main - Entry of app
* @argc: Number of arguments to the program
* @argv: NULL terminated list of the program arguments
* @env: NULL terminated list of the proces environment
* Return: Always 0, error otherwise
*/
int main(int ac, __attribute__((unused)) char **av)
{
	unsigned int i;

	i = 0;
	while (ac && (environ[i] != NULL))
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
