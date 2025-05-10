#include <iostream>
using namespace std;

int printNums(int n)
{
    if (n == 1)
    {

        return 1;
    }

    return n + printNums(n - 1);
}

int main()
{
    cout << printNums(6) << endl;
    cout << printNums(10) << endl;
}