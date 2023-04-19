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
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: Unable to create child process");
		return (1);
	}
	my_pid = getpid();
	printf("My pid is %u \n", my_pid);
	if (child_pid == 0)
		printf("(%u) Noooooooooo!\n", my_pid);
	else
		printf("(%u) %u, I am your father\n", my_pid, child_pid);

	return (0);
}

