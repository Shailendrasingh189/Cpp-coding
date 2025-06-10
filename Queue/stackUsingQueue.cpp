#include <iostream>
#include <queue>
using namespace std;
// implementation of stack using 2 queues

class Stack
{
public:
    queue<int> q1;
    queue<int> q2;

    void push(int val)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(val);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(4);

    cout << "Top: " << s1.top() << endl;
    cout << "Popped: " << s1.pop() << endl;

    cout << "Is empty: " << s1.empty() << endl;

    return 0;
}