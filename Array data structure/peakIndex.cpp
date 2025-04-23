#include <iostream>
#include <vector>
using namespace std;
//optimized approach - binary search

int main()
{
    vector<int> arr = {0, 3, 8, 9, 5, 2};
    int st = 1, end = arr.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            cout << mid << endl;
            return mid;
        }
        else if (arr[mid - 1] < arr[mid])
        { // right
            st = mid + 1;
        }
        else
        { // left
            end = mid - 1;
        }
    }

    return -1;
}