#include "environment.h"

/**
* main - Application's entry point
*
* Return: 0 on success, no-zero otherwise on error
*/
int main(void)
{
	char *var = "PATH";
	char *_env = _getenv(var);
	dir_l *dirs = NULL;
	dir_l *dir_ptr = NULL;

	if (_env == NULL)
	{
		printf("Did not find the path specified");
		return (1);
	}
	print_env_dir((const char *) _env);
	dirs = build_env_dirs(&dirs, _env);
	if (dirs == NULL)
	{
		perror("Error building dir list\n");
		free(_env);
		return (1);
	}

	dir_ptr = dirs;
	while (dir_ptr->next != NULL)
	{
		printf("Directory: %s\n", dir_ptr->dir_name);
		dir_ptr = dir_ptr->next;
	}
	free_dirl(&dirs);
	free(_env);

	return (0);
}
