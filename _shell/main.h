#ifndef __SHELL_PRACTICE__H
#define __SHELL_PRACTICE__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void print_prompt(void);
void free_buffer(char *buffer);
char **tokenize(char *str, char *delim);
void free_tokens(char ***tokens);

#endif /* #ifndef __SHELL_PRACTICE__H */
