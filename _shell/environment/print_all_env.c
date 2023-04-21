#include <stdio.h>

extern char **environ;
/**
* main - Entry of app
* @argc: Number of arguments to the program
* @argv: NULL terminated list of the program arguments
* @env: NULL terminated list of the proces environment
* Return: Always 0, error otherwise
*/
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	printf("Address of av: %p\n",(void *) &av);
	printf("Address of environ: %p\n", (void *) &environ);

	return (0);
}
