#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        if (v.empty())
        {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }
        v.pop_back();
    }

    int top()
    {
        return v[v.size() - 1];
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl;

    while (!s.isEmpty())
    {
        cout << "Popping: " << s.top() << endl;
        s.pop();
    }
    return 0;
}