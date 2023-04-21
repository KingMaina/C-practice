#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
#define BUFF_SIZE 1024
#define MAX_TOKENS 1024
#define DELIM ":"

typedef struct directory_list
{
	char *dir_name;
	struct directory_list *next;
} dir_l;

char *_getenv(const char *name);
void print_env_dir(const char *name);
dir_l *add_node_begin(dir_l **head, char *str);
dir_l *build_env_dirs(dir_l **head, char *str);

char *_getenv(const char *name)
{
	int i = 0;
	int name_len = strlen(name);
	char *path = NULL;

	while (environ[i] != NULL)
	{
		if (strstr(environ[i], name) != NULL)
		{
			path = strdup(environ[i] + name_len + 1);
			return (path);
		}
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

dir_l *add_node_begin(dir_l **head, char *str)
{
	dir_l *node = NULL;
	
	if (str == NULL)
	{
		fprintf(stderr, "Cannot create an empty node\n");
		return (NULL);
	}
	node = malloc(sizeof(dir_l));
	if (node == NULL)
	{
		fprintf(stderr, "Could not allocate memory for node\n");
		return (NULL);
	}
	node->dir_name = strdup(str);
	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
	}
	else
	{
		node->next = *head;
		*head = node;
	}
	return (node);
}

dir_l *build_env_dirs(dir_l **head, char *str)
{
	char *token = NULL;

	if (*head != NULL)
	{
		fprintf(stderr, "List is not empty...");
		return (NULL);
	}
	token = strtok(str, DELIM);
	while (token != NULL)
	{
		add_node_begin(head ,token);
		token = strtok(NULL, DELIM);
	}
	return (*head);
}

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
/*	dir_ptr = dirs;
	while (dir_ptr->next != NULL)
	{
		free();
*/	free(_env);

	return (0);
}
