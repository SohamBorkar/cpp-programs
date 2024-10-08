#include <stdio.h>
// Function to print the Tic Tac Toe board
void printBoard(char board[3][3])
{
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}
// Function to check if a player has won
int checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return 1; // Player has won
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return 1; // Player has won
    }
    return 0; // No winner yet
}
// Function to make a move for the machine using a specific strategy
void makeMachineMove(char board[3][3], int turn)
{
    printf("Machine's move:\n");
    // Check for the center
    if (board[1][1] == ' ')
    {
        board[1][1] = 'O';
    }
    else
    {
        // magic square strategy
        int magicSquare[3][3] = {
            {8, 1, 6},
            {3, 5, 7},
            {4, 9, 2}};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    return;
                }
            }
        }
    }
}
int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
    int row, col;
    int turn = 0;
    do
    {
        printBoard(board);
        if (turn == 0)
        {
            printf("User's move (row and column): ");
            scanf("%d %d", &row, &col);
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
            {
                printf("Invalid move. Try again.\n");
                continue;
            }
            board[row - 1][col - 1] = 'X';
        }
        else
        {
            makeMachineMove(board, turn);
        }
        if (checkWin(board, 'X'))
        {
            printBoard(board);
            printf("User wins!\n");
            break;
        }
        else if (checkWin(board, 'O'))
        {
            printBoard(board);
            printf("Machine wins!\n");
            break;
        }
        int tie = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    tie = 0;
                    break;
                }
            }
            if (!tie)
            {
                break;
            }
        }
        if (tie)
        {
            printBoard(board);
            printf("It's a tie!\n");
            break;
        }
        turn = 1 - turn;
    } while (1);
    return 0;
}
