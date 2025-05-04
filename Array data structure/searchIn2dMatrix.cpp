#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target, int row)
{
    int n = matrix[0].size();

    int st = 0, end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target == matrix[row][mid])
        {
            return true;
        }
        else if (target > matrix[row][mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false; // Target not found
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int stRow = 0, endRow = m - 1;

    while (stRow <= endRow)
    {
        int midRow = stRow + (endRow - stRow) / 2;
        if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1])
        {
            return searchMatrix(matrix, target, midRow);
        }
        else if (target > matrix[midRow][0])
        {
            stRow = midRow + 1;
        }
        else
        {
            endRow = midRow - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    int target = 36;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}