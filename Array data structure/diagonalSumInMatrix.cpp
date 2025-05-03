#include <iostream>
#include <limits.h>
using namespace std;

int diagonalSum(int matrix[][4], int n) // O(n^2)
{
    int sum = 0;

    // pd : j = i;
    // sd : j = n - i - 1;

    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
        if (i != n - i - 1)
        {
            sum += matrix[i][n - i - 1];
        }
    }
    return sum;
}

int main()
{
    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
    int n = 4;

    cout << diagonalSum(matrix, n) << endl;
}