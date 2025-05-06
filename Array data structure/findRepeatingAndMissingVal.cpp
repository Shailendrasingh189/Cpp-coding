#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// hashing method

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &mat)
{
    vector<int> result;
    unordered_set<int> s;
    int n = mat.size();
    int a, b;

    int expSum = 0, actualSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            actualSum += mat[i][j];

            if (s.find(mat[i][j]) != s.end())
            {
                a = mat[i][j];
                result.push_back(a);
            }
            s.insert(mat[i][j]);
        }
    }
    expSum = (n * n) * (n * n + 1) / 2;
    b = expSum - (actualSum - a);
    result.push_back(b);

    return result;
}

int main()
{
    vector<vector<int>> mat = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    vector<int> result = findMissingAndRepeatedValues(mat);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}