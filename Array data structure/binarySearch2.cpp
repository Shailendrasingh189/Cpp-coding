#include <iostream>
#include <vector>
using namespace std;
// binary search - recursion

int recBinarySearch(vector<int> arr, int tar, int st, int end)
{

    if (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (tar > arr[mid])  //2nd half
        {
            return recBinarySearch(arr, tar, mid+1, end);
        }
        else if (tar < arr[mid]) // 1st half
        {
            return recBinarySearch(arr, tar, st, mid - 1);
        }
        else if (tar == arr[mid]) // return ans
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int tar1 = 20;
    int st = 0, end = arr1.size() - 1;
    cout << recBinarySearch(arr1, tar1, st, end) << endl;

}