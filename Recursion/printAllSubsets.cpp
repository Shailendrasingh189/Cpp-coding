#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans, int i)
{
    if (i == arr.size())
    {
        cout << "[ ";
        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << "], ";
        cout << endl;
        return;
    }

    // include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    // exclude
    ans.pop_back(); // backtrack
    printSubsets(arr, ans, i + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;

    printSubsets(arr, ans, 0);

    return 0;
}