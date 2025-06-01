#include <iostream>
using namespace std;
// T.C.: O(n)
// S.C. : O(n/k) for recursion stack

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class List
{
public:
    Node *head;

    List()
    {
        head = nullptr;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node *reverseKGroup(Node *head, int k)
    {
        Node *temp = head;
        int count = 0;

        // Check if there are at least k nodes ahead
        while (count < k)
        {
            if (temp == nullptr)
            {
                return head;
            }
            temp = temp->next;
            count++;
        }

        // Recursive call for the next group
        Node *prevNode = reverseKGroup(temp, k);

        // Reverse current k nodes
        temp = head;
        count = 0;
        while (count < k)
        {
            Node *next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }
        return prevNode;
    }

    void reverseInGroups(int k)
    {
        head = reverseKGroup(head, k);
    }
};

int main()
{
    List myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(6);
    myList.push_back(7);

    cout << "Original list: ";
    myList.printList();

    int k = 3;
    myList.reverseInGroups(k);

    cout << "Reversed in groups of " << k << ": ";
    myList.printList();

    return 0;
}
