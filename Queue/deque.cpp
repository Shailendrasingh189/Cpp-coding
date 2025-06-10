#include <iostream>
#include <deque>
using namespace std;

int main()
{

    deque<int> dq;

    dq.push_back(2);
    dq.push_back(4);
    dq.push_front(6);

    cout << dq.front() << " " << dq.back() << endl;

    dq.pop_back();
    cout << dq.front() << " " << dq.back() << endl;

    cout << endl;
    return 0;
}