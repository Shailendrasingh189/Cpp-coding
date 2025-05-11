#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int st, int end, int target)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] <= target)
        {
            return binarySearch(arr, mid + 1, end, target);
        }
        else
        {
            return binarySearch(arr, st, mid - 1, target);
        }
    }
    return -1; // target not found
}

int search(vector<int> arr, int n, int target)
{
    int l = 0;
    int r = n - 1;
    return binarySearch(arr, l, r, target);
}

int main()
{
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int n = arr.size();
    int target = 9;

    cout << search(arr, n, target) << endl;
}