#include <iostream>
#include <vector>
using namespace std;

bool isArraySorted(vector<int> arr, int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }

    return isArraySorted(arr, n - 1) && (arr[n - 1] >= arr[n - 2]);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    cout << isArraySorted(arr, n) << endl;
}