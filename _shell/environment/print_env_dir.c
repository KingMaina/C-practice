#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name);
void print_env_dir(const char *name);
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

void print_env_dir(const char *name)
{
	while (*name != '\0')
	{
		if (*name == ':')
		{
			printf("\n");
			name++;
			continue;
		}
		printf("%c", *name++);
	}
	printf("\n");
}

int main(void)
{
	char *var = "PATH";
	char *_env = _getenv(var);

	if (_env == NULL)
	{
		printf("Did not find the path specified");
		return (0);
	}
	print_env_dir((const char *) _env);
	return (0);
}
