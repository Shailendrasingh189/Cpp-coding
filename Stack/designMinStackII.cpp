#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack
{
public:
    stack<long long int> s;
    long long int minVal;

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            minVal = val;
        }
        else
        {
            if (val < minVal)
            {
                s.push((long long)2 * val - minVal);
                minVal = val;
            }
            else
            {
                s.push(val);
            }
        }
    }

    void pop()
    {
        if (s.top() < minVal)
        {
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }

    int top()
    {
        if (s.top() < minVal)
        {
            return minVal;
        }
        s.top();
    }

    int getMin()
    {
        return minVal;
    }
};

int main()
{
    MinStack ms;

    ms.push(-2);
    ms.push(0);
    ms.push(-3);

    cout << "Minimum value : " << ms.getMin() << endl;

    ms.pop();

    cout << "Top value : " << ms.top() << endl;
    cout << "Minimum value : " << ms.getMin() << endl;

    return 0;
}