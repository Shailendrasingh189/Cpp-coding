#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getAllSubsets(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
    if (i == arr.size())
    {
        allSubsets.push_back({ans});
        return;
    }

    // include
    ans.push_back(arr[i]);
    getAllSubsets(arr, ans, i + 1, allSubsets);

    ans.pop_back(); // backtrack

    int idx = i + 1;
    while (idx < arr.size() && arr[idx] == arr[i])
    {
        idx++;
    }

    // exclude
    getAllSubsets(arr, ans, idx, allSubsets);
}

int main()
{
    vector<int> arr = {1, 2, 2};
    sort(arr.begin(), arr.end());

    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(arr, ans, 0, allSubsets);
    // Printing the subsets
    cout << "Unique subsets are:\n";
    for (const auto &subset : allSubsets)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}