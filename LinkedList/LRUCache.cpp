#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// TC - O(1)

class Node
{
public:
    int key, val;
    Node *prev, *next;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        prev = next = NULL;
    }
};

class LRUCache
{
    Node *head;
    Node *tail;
    unordered_map<int, Node *> m;
    int limit;

public:
        void addNode(Node *newNode)
    {

        Node *temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }

    void delNode(Node *oldNode)
    {
        Node *prevNode = oldNode->prev;
        Node *nextNode = oldNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    LRUCache(int capacity)
    {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }

        Node *ansNode = m[key];
        int ans = ansNode->val;
        m.erase(key);

        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value)
    {

        if (m.find(key) != m.end())
        {
            Node *existingNode = m[key];
            delNode(existingNode);
            m.erase(key);
        }

        if (m.size() == limit)
        {
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1

    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)

    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4

    return 0;
}