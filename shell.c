#include "main.h"

/**
 * shl_exec - executes the commands passed
 * @argv: string array
 * @av: Arrayof strings
 * Return: -1 if sucessful, 0 if failed
 */
int shl_exec(char **argv, char **av)
{
    pid_t pid;

    int status;

    /*If no arg is parsed to the prompt return 1 as a status then reprompt*/
    if (argv[0] == NULL)
    {
        return (1);
    }

    pid = fork();

    /*if creating child process failed.*/
    if (pid == -1)
        return (1);

    /*entering the child process to perform the execution*/
    if (pid == 0)
    {

        if (execvp(argv[0], argv) == -1)
        {
            /*Putting the name of the shell ran from the commandline stderr*/
            perror(av[0]);
            return (0);
        }
    }
    /*Parent process waiting for the child*/
    else
    {
        wait(NULL);
    }

    return (-1);
}

/**
 * shl_loop - shell loop for prompt
 * @av: takes no arg
 * * Return: -1 for EOF and 0 for exit, 1 repeat
 */
int shl_loop(char **av)
{
    size_t n = 0;
    char *args = NULL;
    int status = 1;

    while (status)
    {
        int i = 1;
        ssize_t parsed = 0;
        char *delim = " ";
        char *options[3] = {"1", "2", "3"};
        int switched = 0;
        int j = 0;
        /*Using null delim for commnds to take no args*/
        char *del = "\0";
        char **tokens = malloc(1024 * sizeof(char *));

        if (tokens == NULL)
        {
            free(tokens);
            return (0);
        }
        /*For interactivity, if std input fd is 0 put the prompt sign*/
        if (isatty(STDIN_FILENO))
            printf("$ ");
        parsed = getline(&args, &n, stdin);
        /*For EOF i.e ctrl + D*/
        if (parsed == -1)
        {
            free(args);
            free(tokens);
            return (-1);
        }
        /*Replacing the newline character added from the getline with null*/
        *(args + (strlen(args) - 1)) = '\0';
        tokens[0] = strtok(args, delim);

        /*Initializing tokenized str at index 1 of token arrays with garbage*/
        tokens[1] = "foo";
        while (tokens[i])
        {
            tokens[i] = strtok(NULL, delim);
            i++;
        }
        tokens[i] = NULL;

        /*Calling the exec and assign it return to status*/

        status = builtin_call(tokens, av);
        free(tokens);
    }
    return (EXIT_SUCCESS);
}
