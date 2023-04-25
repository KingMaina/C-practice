# Description

## Shell program

This is a simple shell program that takes in input from the standard input and prompts the user for other input

`main.c` is the entry point of the application and is responsible for declaring variables to be used throughout the processing of commands
`tokenize.c` tokenizes the input command string into an array of tokens
`memory.c` contains functions for memory management in the shell program including allocating and de-allocating

## Project Setup

Ensure you have gcc compiler installed in your system (will update link & readme).

## Compile

Compile the code with 
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```
Here we check for compilation errors, warnings and adherance to C89 stadards for this case. We the nnilcude all the C files to be compiled `main.c`, `tokenizer.c`, `memory.c` and output into the file `shell`

## Run the shell

To run the shell program, run the output file `./shell` in your terminal
```bash
./shell
```
When the shell runs you will be prompted to enter a command. Enter a command or string, press enter and you will be prompted for the next command

## Drawbacks

The shell does not yet run any command applications.
