#include <iostream>
#include <list>
using namespace std;

class Stack
{
    list<int> ll;

public:
    void push(int val)
    {
        ll.push_front(val);
    }
    void pop()
    {
        ll.pop_front();
        }

    int top()
    {
        return ll.front();
    }

    bool isEmpty()
    {
        return ll.size() == 0;
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