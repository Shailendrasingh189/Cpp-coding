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

// Find a node with a given value
Node *findNode(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
        return root;

    Node *leftResult = findNode(root->left, val);
    if (leftResult != NULL)
        return leftResult;

    return findNode(root->right, val);
}

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;

    if (root->data == p->data || root->data == q->data)
        return root;

        Node* leftLCA = lowestCommonAncestor(root->left, p, q);
        Node* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA) {
            return root;
        } else if(leftLCA != NULL) {
            return leftLCA;
        } else {
            return rightLCA;
        }

}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, 8, -1, -1, 9, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node *root = buildTree(preorder);
    Node *p = findNode(root, 6);
    Node *q = findNode(root, 7);

    Node *lca = lowestCommonAncestor(root, p, q);

    cout<<lca->data<<endl;

    return 0;
}