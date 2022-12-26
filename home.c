#include "main.h"
/**
 * init_shell - shell home page
 * @argv: strings array
 */
void init_shell(char **argv)
{
    clear();
    printf("\n\n\n\n******************"
           "************************");
    printf("\n\n\n\t****AYOBAMI SHELL****");
    printf("\n\n\t-HAVE FUN!-");
    printf("\n\n\n\n*******************"
           "***********************");
    char *username = getenv("USER");
    printf("\n\n\nUSER is: @%s", username);
    printf("\n");
    printf("1. SHELL");
    printf("\t2. GAMES");
    printf("\t3. HELP\n");
    printf("\n");
    printf("press 1\\2\\3 to select shell option\n");
}

/**
 * games - games page select game to play
 * @argv: string of arrays
 * Return: 1
 */
int games(char **argv)
{
    (void)(argv);

    clear();
    printf("\t\t GAMES PAGE\n");
    printf("\n1. Game-1: tic-tac -> Enter tic-tac to play \t game by Ayobami Alaran");
    printf("\n");

    return (1);
}
