#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

char player = 'X';

void draw_board()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void player_turn()
{
    int row, col;
    printf("Player %c turn.\n", player);
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);
    row--;
    col--;

    if (board[row][col] != ' ')
    {
        printf("Invalid move! Try again.\n");
        player_turn();
    }
    else
    {
        board[row][col] = player;
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}
int checkwin()
{
    if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] != ' ' && board[0][1] == board[0][2])
    {
        printf("Player %c wins \n", board[0][2]);
        exit(0);
    }
    else if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] != ' ' && board[1][1] == board[1][2])
    {
        printf("Player %c wins \n", board[1][2]);
        exit(0);
    }
    else if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] != ' ' && board[2][1] == board[2][2])
    {
        printf("Player %c wins \n", board[2][2]);
        exit(0);
    }
    else if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] != ' ' && board[1][0] == board[2][0])
    {
        printf("Player %c wins \n", board[2][0]);
        exit(0);
    }
    else if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] != ' ' && board[1][1] == board[2][1])
    {
        printf("Player %c wins \n", board[2][1]);
        exit(0);
    }
    else if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] != ' ' && board[1][2] == board[2][2])
    {
        printf("Player %c wins \n", board[2][2]);
        exit(0);
    }
    else if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] != ' ' && board[1][1] == board[2][2])
    {
        printf("Player %c wins \n", board[2][2]);
        exit(0);
    }
    else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] != ' ' && board[1][1] == board[2][0])
    {
        printf("Player %c wins \n", board[2][0]);
        exit(0);
    }

    return (0);
}

int main()
{
    draw_board();
    while (1)
    {
        checkwin();
        player_turn();
        draw_board();
    }

    return 0;
}
