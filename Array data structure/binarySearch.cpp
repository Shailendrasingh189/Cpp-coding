#include <iostream>
#include <vector>
using namespace std;
//binary search - iterative method
// T.C - O(logn)
// S.C - O(1)

int binarySearch(vector<int> arr, int tar)
{
    int st = 0, end = arr.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2; // to controll overflow error form (st + end) /2  st - INT_MAX , end - INT_MAX

        if (tar > arr[mid])
        {
            st = mid + 1;
        }
        else if (tar < arr[mid])
        {
            end = mid - 1;
        }
        else if (tar == arr[mid])
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int tar1 = 5;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};
    int tar2 = 5;
    cout << binarySearch(arr1, tar1) << endl;
    cout << binarySearch(arr2, tar2) << endl;
    // binarySearch(arr, tar);
}