#include <iostream>
#include <vector>
using namespace std;
// permutation in array
// TC - O(n*n!)
// SC - O(n!)

void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        getPerms(nums, idx + 1, ans);

        swap(nums[idx], nums[i]); // backtrack
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    getPerms(nums, 0, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> result = permute(arr);

    // Printing the subsets
    cout << "Permutations are:\n";
    for (const auto &permutation : result)
    {
        cout << "{ ";
        for (int num : permutation)
        {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}