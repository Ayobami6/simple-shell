#include "main.h"
/**
 * main - main
 * @argc: arg count
 * @argv: arg vector
 * Return: exit success
 */
int main(int argc, char **argv)
{
    (void)(argc);
    init_shell(argv);
    shl_loop(argv);

    return (EXIT_SUCCESS);
}
