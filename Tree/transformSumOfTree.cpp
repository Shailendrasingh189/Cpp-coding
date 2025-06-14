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

// preorder
void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

// Transform to sum tree
int sumTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;

    return root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    preOrder(root);
    cout << endl;

    sumTree(root);

    preOrder(root);

    return 0;
}