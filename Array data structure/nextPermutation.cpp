#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//optimized approach  TC - O(n), SC - O(1)

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    // find the pivot
    int pivot = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }

    if (pivot == -1)
    {
        reverse(arr.begin(), arr.end()); // in place changes
    }

    // 2nd step: next larger element
    for (int i = n - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // 3rd step: reverse (piv+1 to n-1)
    int i = pivot + 1, j = n - 1;

    while (i <= j)
    {
        swap(arr[i++], arr[j--]);
        i++, j--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}