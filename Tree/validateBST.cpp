#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// insert node
Node *insert(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return new Node(val);
    }

    // left sub tree call
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }

    // right sub tree call
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// build binary search tree
Node *buildBST(vector<int> arr)
{
    Node *root = NULL;

    for (int val : arr)
    {
        root = insert(root, val);
    }

    return root;
}

bool helper(Node *root, Node *min, Node *max)
{
    if (root == NULL)
        return true;

    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    return helper(root->left, min, root) && helper(root->right, root, max);
}

bool isValidBST(Node *root)
{
    return helper(root, NULL, NULL);
}

// preorder sequence
void preorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // print root
    cout << root->data << " ";

    // left sub tree call
    preorder(root->left);

    // right sub tree call
    preorder(root->right);
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node *root = buildBST(arr);

    cout << "Pre-order Traversal of Balanced BST: ";
    preorder(root);
    cout << endl;
    cout << isValidBST(root);

    return 0;
}