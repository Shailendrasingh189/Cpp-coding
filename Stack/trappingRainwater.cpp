#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// prefix array 

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);

    lmax[0] = height[0];
    rmax[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], height[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += min(lmax[i], rmax[i]) - height[i];
    }

    return ans;
}

int main()
{
    vector<int> arr = {4, 2, 0, 3, 2, 5};
    cout << trap(arr) << endl;

    return 0;
}