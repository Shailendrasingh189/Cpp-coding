#include <iostream>
#include <vector>
#include <string>
using namespace std;
// TC - O(n!)

bool isSafe(vector<string> &board, int row, int col, int n) // O(n)
{

    // horizontal
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    // vertical
    for (int j = 0; j < n; j++)
    {
        if (board[j][col] == 'Q')
            return false;
    }

    // diagonal left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // diagonal right
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nQueens(vector<vector<string>> &result, vector<string> &board, int row, int n) // O(n!)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            nQueens(result, board, row + 1, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    nQueens(result, board, 0, n);
    return result;
}

void printBoard(const vector<string> &board)
{
    for (const string &row : board)
    {
        cout << row << endl;
    }
    cout << endl;
}

int main()
{
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total solutions for n = " << n << ": " << solutions.size() << endl;

    for (const auto &solution : solutions)
    {
        printBoard(solution);
    }

    return 0;
}