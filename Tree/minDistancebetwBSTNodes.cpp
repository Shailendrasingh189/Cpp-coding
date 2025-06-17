#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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

int minDiffInBST(Node *root, Node *&prev)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    int ans = INT_MAX;

    if (root->left != NULL)
    {
        int leftMin = minDiffInBST(root->left, prev);
        ans = min(ans, leftMin);
    }

    if (prev != NULL)
    {
        ans = min(ans, root->data - prev->data);
    }
    prev = root;

    if (root->right != NULL)
    {
        int rightMin = minDiffInBST(root->right, prev);
        ans = min(ans, rightMin);
    }

    return ans;
}

int main()
{
    vector<int> arr = {83, 62, 88, 42, 82, 52};

    // Build the BST
    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val);
    }

    // previous node
    Node *prev = NULL;

    // Get the minimum difference
    int result = minDiffInBST(root, prev);
    cout << "Minimum difference between any two nodes in BST: " << result << endl;

    return 0;
}