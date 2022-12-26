#include "main.h"

/**
 * shl_exit - exit the current process with a status
 * Return: the exit status
 */
int shl_exit()
{

    puts("****************GOODBYE**************\n");
    puts("Thanks for using, if encouter any issue or have any feature to add"
         "\ncreate a pull request on github or an issue..");
    return (0);
}
int clear_all()
{
    clear();
    return (1);
}
/**
 * shl_help - the cli help function
 * Return: 0
 */
int shl_help()
{

    puts("***********WELCOME TO AYOBAMI SIMPLE SHELL HELP PAGE***********\n");

    puts("Copyright @Ayobami6\n");
    puts("Supports all Unix shell commands"
         "\n Other built in commands are:"
         "\npublish: git command to add, commit and publish changes to your github");

    return (1);
}
/**
 * builtin_call - function that execute the buitin commands
 * @argv: data parsed
 * @av: array of strings from the command line.
 * Return: -1 if function not found, 0 if sucessful,
 * 1 if not successful.
 */
int builtin_call(char **argv, char **av)
{

    int i;

    builtin_t builtin[] = {
        {"exit", shl_exit},
        {"help", shl_help},
        {"1", clear_all},
        {"2", games},
        {"3", shl_help},
        {NULL, NULL}};
    /*If  the first arg  is null prompt again*/
    if (argv[0] == NULL)
        return (1);
    /*Checking if the parsed command is the same with builtin command name*/
    for (i = 0; builtin[i].name; i++)
        if (strcmp(argv[0], builtin[i].name) == 0)
            return (builtin[i].fp());
    /*If the command not in buitin run shl_exec on command executable*/
    return (shl_exec(argv, av));
}
