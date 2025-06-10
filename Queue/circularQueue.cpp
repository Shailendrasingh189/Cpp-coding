#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularQueue
{
    int *arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size)
    {
        cap = size;
        currSize = 0;
        arr = new int[cap];
        f = 0;
        r = -1;
    }

    void push(int data)
    {
        if (currSize == cap)
        {
            cout << "CQ is Full\n";
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "CircularQueue is Empty\n";
            return;
        }

        f = (f + 1) % cap;
        currSize--;
    }

    int front()
    { // O(1)
        if (isEmpty())
        {
            cout << "CircularQueue is Empty\n";
            return 0;
        }

        return arr[f];
    }

    bool isEmpty()
    { // O(1)
        return currSize == 0;
    }

    void printArr()
    {
        for (int i = 0; i < cap; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    CircularQueue cq(3);

    cq.push(2);
    cq.push(4);
    cq.push(6);
    cq.pop();
    cq.push(9);
    cq.printArr();

    while (!cq.isEmpty())
    {
        cout << cq.front() << " ";
        cq.pop();
    }

    return 0;
}