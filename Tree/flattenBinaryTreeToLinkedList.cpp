#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// building BT and implementing different tree traversals

// Node class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

Node *nextRight = NULL;

void flatten(Node *root)
{
    if (root == NULL)
        return;

    flatten(root->right);
    flatten(root->left);

    root->left;
    root->right = nextRight;
    nextRight = root;
}

void printFlattenedList(Node *root)
{
    cout << "Flattened linked list: ";
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    flatten(root);

    printFlattenedList(root);

    return 0;
}