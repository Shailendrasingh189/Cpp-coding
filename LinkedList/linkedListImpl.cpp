#include <iostream>
using namespace std;

class Node
{ // class to create a node

public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{ // class to add, delete, print and search nodes
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val) // add node on front of linked list, TC - O(1)
    {
        Node *newNode = new Node(val); // dynamic object

        if (head == NULL)
        { // empty linked list
            head = tail = newNode;
            return;
        }
        else // not empty
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    { // add node on back of linked list, TC - O(1)
        Node *newNode = new Node(val);

        if (head == NULL) // empty linked list
        {
            head = tail = newNode;
            return;
        }
        else // not empty
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() // delete node from front of linked list, TC - O(1)
    {
        if (head == NULL)
        {
            cout << "LL is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    void pop_back() // TC - O(n)
    {
        if (head == NULL)
        {
            cout << "LL is empty\n";
            return;
        }

        Node *temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos) // TC - O(n)
    {
        if (pos < 0)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "INvalid position\n";
                return;
            }
            temp = temp->next;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key) // to search node //TC - O(n)
    {
        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void printLL()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main()
{
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_back(1);

    ll.insert(4, 1);

    ll.printLL();

    cout << ll.search(3) << endl;

    return 0;
}