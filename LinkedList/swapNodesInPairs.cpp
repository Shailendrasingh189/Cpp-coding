#include <iostream>
using namespace std;

class Node // class to create a node
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

class List // class to add, delete, print and search nodes
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_back(int val) // add node on back or end of linked list
    {
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

    // send head if pass node
    Node *swapPairs() // swap pair function
    {
        if (head == NULL || head->next == NULL) // one or no node check
        {
            return head;
        }

        // Initialising three pointers
        Node *first = head;
        Node *sec = head->next;
        Node *prev = NULL;

        while (first != NULL && sec != NULL)
        {
            Node *third = sec->next;

            sec->next = first;
            first->next = third;

            if (prev != NULL)
            {
                prev->next = sec;
            }
            else
            {
                head = sec;
            }

            // update
            prev = first;
            first = third;

            if (third != NULL)
            {
                sec = third->next;
            }
            else
            {
                sec = NULL;
            }
        }

        return head;
    }

    void printLL() // to print linked list
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

int main()
{
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original Linked List: ";
    ll.printLL();

    // Node *newHead = ll.swapPairs(ll.getHead());
    // ll.setHead(newHead);
    ll.swapPairs();

    cout << "New Linked List: ";
    ll.printLL();

    return 0;
}