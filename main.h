#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define clear() printf("\033[H\033[J")

typedef struct options
{
	char *name;
	int (*fp)();
} option_t;

/**
 * struct builtin - object for builtin command
 * @name: name of the command argument
 * @fp: function pointer thats stores the algo for the functions to be called
 */
typedef struct builtin
{
	char *name;
	int (*fp)();
} builtin_t;

int builtin_call(char **argv, char **av);
int shl_exit();
int shl_help();
void init_shell(char **argv);
int clear_all();

int shl_exec(char **argv, char **av);
int shl_loop(char **av);
int games();
int option_call(char **argv, char **av);

#endif
