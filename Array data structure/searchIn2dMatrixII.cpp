#include <iostream>
#include <vector>
using namespace std;
//Binary search approach - O(n + m) time complexity

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int r = 0, c = n - 1;

    while (r < m && c >= 0)
    {
        if (matrix[r][c] == target)
        {
            return true; // Target found
        }
        else if (matrix[r][c] > target)
        {
            c--; // Move left in the row
        }
        else
        {
            r++; // Move down in the column
        }
    }

    return false; // Target not found
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 7;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}