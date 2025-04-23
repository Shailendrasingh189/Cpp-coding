#include <iostream>
#include <vector>
using namespace std;
// optimized approach - binary search

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages)
{
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++)
    {
        if ((arr)[i] > maxAllowedPages)
        {
            return false;
        }

        if ((pages + arr[i]) <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else
        {
            students++;
            pages = arr[i];
        }
    }
    return students > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m)
{
    if(m > n) {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int st = 0, end = sum, ans = -1; // range of possible
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3,5, 4,2,5,3,6,1};
    int n = arr.size(), m = 4;

    cout << allocateBooks(arr, n, m) << endl;

    return 0;
}