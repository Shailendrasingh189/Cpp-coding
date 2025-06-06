#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s; // to store unique combinations

void getAllCombinations(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &combin)
{
    int n = arr.size();

    if (idx == n || target < 0) // base case
    {
        return;
    }

    // base case
    if (target == 0)
    {
        if (s.find(combin) == s.end())
        {
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);

    getAllCombinations(arr, idx + 1, target - arr[idx], ans, combin); // single element choice

    getAllCombinations(arr, idx, target - arr[idx], ans, combin); // multiple element choice

    combin.pop_back(); // backtrack

    getAllCombinations(arr, idx + 1, target, ans, combin); // not including the element - exclusion element choice
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> combin;

    getAllCombinations(arr, 0, target, ans, combin);

    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 5};
    int target = 8;

    vector<vector<int>> result = combinationSum(arr, target);

    // Printing the subsets
    cout << "Combinations are:\n";
    for (const auto &combination : result)
    {
        cout << "{ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}