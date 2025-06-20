#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalGas = 0, totalCost = 0;

    // unique solution always exists
    int start = 0, currGas = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        totalGas += gas[i];
        totalCost += gas[i];

        currGas += (gas[i] - cost[i]);

        if (currGas < 0)
        {
            start = i + 1;
            currGas = 0;
        }
    }

    return totalGas < totalCost ? -1 : start;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}