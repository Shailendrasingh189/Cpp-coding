#include <iostream>
#include <vector>
#include <queue>
#include <string>
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

void allPaths(Node *root, string path, vector<string> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(path);
        return;
    }

    if (root->left)
    {
        allPaths(root->left, path + "->" + to_string(root->left->data), ans);
    }
    if (root->right)
    {
        allPaths(root->right, path + "->" + to_string(root->right->data), ans);
    }
}

vector<string> binaryTreePaths(Node *root)
{
    vector<string> ans;
    string path = to_string(root->data);

    allPaths(root, path, ans);
    return ans;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    vector<string> allPaths = binaryTreePaths(root);
    
    cout << "Root-to-leaf paths:\n";
    for (const string &p : allPaths)
    {
        cout << p << endl;
    }

    return 0;
}