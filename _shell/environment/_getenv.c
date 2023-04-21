#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	int name_len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strstr(environ[i], name) != NULL)
			return ((char *)environ[i] + name_len + 1);
		i++;
	}
	return (NULL);
}

/**
* _getenv - gets an environent variable
* @argc: Number of arguments to the program
* @argv: NULL terminated list of the program arguments
* @env: NULL terminated list of the proces environment
* Return: Always 0, error otherwise
*/
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	char *_env = NULL;
	char *var = "PATH";

	_env = _getenv(var);
	if (_env == NULL)
	{
		printf("Did not find a variable name with that name");
		return (1);
	}
	printf("%s\n", _env);

	return (0);
}
