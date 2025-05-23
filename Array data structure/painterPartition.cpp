#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// binary Search approach - T.C. = O(log(sum)*n) = O(nlogn)

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime) // O(n)
{
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++)
    {

        if ((time + arr[i]) <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painters++;
            time = arr[i];
        }
    }
    return painters > m ? false : true;
}

int minTimeToPaint(vector<int> &arr, int n, int m)
{
    int sum = 0, maxVal = INT_MIN;

    for (int i = 0; i < arr.size(); i++) // O(n)
    {
        if (maxVal < arr[i])
        {
            maxVal = arr[i];
        }
        sum += arr[i];
    }

    int st = maxVal, end = sum, ans = -1;
    while (st <= end) // O(log(sum)) * n
    {

        if (n < m)
        {
            return -1;
        }

        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid))
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
    vector<int> arr = {40, 30, 10, 20};
    int n = 4, m = 2;
    cout << minTimeToPaint(arr, n, m) << endl;
    return 0;
}
