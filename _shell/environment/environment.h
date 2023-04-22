#ifndef __ENV_H__
#define __ENV_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
#define BUFF_SIZE 1024
#define MAX_TOKENS 1024
#define DELIM ":"

/**
* struct directory_list - Definition for a node in linked list
* @dir_name: The direcorty path
* @next: POinter to the the next node in the
* directoy_list linked list
*/
typedef struct directory_list
{
	char *dir_name;
	struct directory_list *next;
} dir_l;

char *_getenv(const char *name);
void print_env_dir(const char *name);
dir_l *add_node_begin(dir_l **head, char *str);
dir_l *build_env_dirs(dir_l **head, char *str);
void free_dirl(dir_l **head);

#endif /* ifndef __ENV_H__ */
