#include "environment.h"

/**
* _getenv - Searches the environment variable specified
* @name: The environment variable
*
* Return: Pointer to the start of the env variable's value,
* NULL otherwise
*/
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

/**
* print_env_dir - Prints a list of directories from
* the PATH env variable
* @name: The PATH env value
*
* Return: void
*/
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

/**
* add_node_begin - Adds a new node to the start of a
* dir_l linked list
* @head: Pointer to the head node's address
* @str: String to add to the node
*
* Return: Pointer to the created node
*/
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

/**
* build_env_dirs - Creates a linked list from a delimetered string
* @head: Pointer to the head node of a dir_l linked list
* @str: Delimetered string
*
* Return: Pointer to the start of the linked list, NULL otherwise on error
*/
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
		add_node_begin(head, token);
		token = strtok(NULL, DELIM);
	}
	return (*head);
}

/**
* free_dirl - De-allocates memory from a dir_l linked list
* @head: Pointer to the head node address of the linked list
*
* Return: void
*/
void free_dirl(dir_l **head)
{
	dir_l *curr_ptr = NULL;
	dir_l *next_ptr = NULL;

	if (!head || !(*head))
	{
		fprintf(stderr, "List not found");
	}
	else
	{
		curr_ptr = *head;
		next_ptr = (*head)->next;

		while (next_ptr != NULL)
		{
			free(curr_ptr->dir_name);
			free(curr_ptr);
			curr_ptr = next_ptr;
			next_ptr = next_ptr->next;
		}
		free(curr_ptr->dir_name);
		free(curr_ptr);
		*head = NULL;
	}
}

