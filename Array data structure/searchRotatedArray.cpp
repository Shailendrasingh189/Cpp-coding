#include <iostream>
#include <vector>
using namespace std;
// Rotated sorted array

int main()
{

    vector<int> arr = {3, 4, 5, 6, 7, 0, 1, 2};
    int target = 6;

    int st = 0, end = arr.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target)
        {
            cout << mid << endl;
            return mid;
        }

        if (arr[st] <= arr[mid])
        {
            if (arr[st] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && target <= arr[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return 0;
}
