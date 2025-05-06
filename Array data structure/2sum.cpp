#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// hashing method

vector<int> twoSum(vector<int> &arr, int target)
{
    unordered_map<int, int> m;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        int first = arr[i];
        int second = target - first;

        if (m.find(second) != m.end())
        {
            result.push_back(i);
            result.push_back(m[second]);
            break;
        }
        m[first] = i;
    }
    return result;
}

int main()
{

    vector<int> arr = {5, 2, 11, 7, 15};
    int target = 9;

    vector<int> result = twoSum(arr, target);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}