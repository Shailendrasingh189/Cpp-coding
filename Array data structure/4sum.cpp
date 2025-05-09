#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// two pointer approach
//  Time complexity: O(nlogn + n^3)
//  space complexity: O(unique quadruplets))

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;

    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            int p = j + 1, q = n - 1;

            while (p < q)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                if (sum < target)
                {
                    p++;
                }
                else if (sum > target)
                {
                    q--;
                }
                else // sum == target
                {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});

                    while (p < q && nums[p] == nums[p + 1])
                        p++;
                    while (p < q && nums[q] == nums[q - 1])
                        q--;

                    p++;
                    q--;
                }
            }
            j++;
            while (j < n && nums[j] == nums[j - 1])
            {
                j++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    for (const auto &quad : result)
    {
        cout << "[";
        for (size_t i = 0; i < quad.size(); ++i)
        {
            cout << quad[i];
            if (i < quad.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}