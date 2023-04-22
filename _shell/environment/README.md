# Description

Contains various functions that get, print and create a linked list of the environment variables' value, along with other functions that loop through the environment variables.
Take care when modifying the env variable's value as it will change the process' environment which may cause unexpected results if not handled.

## build\_env\_dir.c

### Description

Contains functions used to search for an environment variable, print the valuue and also construct a linked list of the values. In this case, we are searching for the PATH variable and creating a linked list of the directories inthe value field delimetered with a ':'.
Searches the environment path specified and builds a linked list from the values form the env variable.

