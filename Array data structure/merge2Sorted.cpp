#include <iostream>
#include <vector>
using namespace std;
//optimized approach

vector<int> merge2Sorted(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] >= arr2[j])
        {
            arr1[idx] = arr1[i];
            idx--, i--;
        }
        else
        {
            arr1[idx] = arr2[j];
            idx--, j--;
        }
    }

    while (j >= 0)
    {
        arr1[idx] = arr2[j];
        idx--, j--;
    }

    return arr1;
}

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};

    int m = 3, n = 3;

    // merge2Sorted(arr1, m, arr2, n);
    printArr(merge2Sorted(arr1, m, arr2, n));

    return 0;
}