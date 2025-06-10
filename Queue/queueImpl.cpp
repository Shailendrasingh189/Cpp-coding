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

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    void push(int data)
    { // insert data at tail TC - O(1)
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    { // O(1)
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        Node *temp = head;
        head = temp->next;
        delete temp;
    }

    int front()
    { // O(1)
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return 0;
        }

        return head->data;
    }

    bool isEmpty()
    { // O(1)
        return head == NULL;
    }
};

int main()
{

    Queue q;

    q.push(2);
    q.push(4);
    q.push(6);

    while (!q.isEmpty())
    {
        cout<< q.front() << " ";
        q.pop();
    }
    
    cout << endl;
    return 0;
}