#include <stdio.h>
#include <unistd.h>

/**
* main - Entry of app
* @argc: Number of arguments to the program
* @argv: NULL terminated list of the program arguments
*
* Return: Always 0, error otherwise
*/
int main(void)
{
	char *argv[] = { "/bin/ls", "-l", "/usr/", NULL };

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error executing program");
	printf("After execve\n");
	return (0);
}

