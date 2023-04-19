#ifndef __SHELL_PRACTICE__H
#define __SHELL_PRACTICE__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void print_prompt(void);
char **tokenize(char *str, size_t str_len);
void free_tokens(char **tokens);

#endif /* #ifndef __SHELL_PRACTICE__H */
