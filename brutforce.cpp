// Bruteforce: 
#include<iostream>
#include<vector>
using namespace std;

const int N = 8; // Size of the chessboard

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}; // Possible x-movements for the knight
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2}; // Possible y-movements for the knight

bool isSafe(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

bool solveKTUtil(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == N * N)
        return true;

    for (int k = 0; k < 8; k++) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];

        if (isSafe(next_x, next_y, board)) {
            board[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, board))
                return true;
            else
                board[next_x][next_y] = -1; // Backtrack
        }
    }

    return false;
}

void printSolution(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

void solveKT(int startX, int startY) {
    vector<vector<int>> board(N, vector<int>(N, -1));

    board[startX][startY] = 0;

    if (solveKTUtil(startX, startY, 1, board))
        printSolution(board);
    else
        cout << "Solution does not exist" << endl;
}

int main() {
    int startX, startY;
    cout << "Enter starting coordinates (x y): ";
    cin >> startX >> startY;

    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        cout << "Invalid starting coordinates. Please try again." << endl;
        return 1;
    }

    solveKT(startX, startY);

    return 0;
}