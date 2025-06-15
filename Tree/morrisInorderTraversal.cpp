#include <iostream>
#include <vector>
#include <queue>
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

vector<int> inorderTraversal(Node *root)
{
    vector<int> ans;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // find the IP
            Node *IP = curr->left;
            while (IP->right != NULL && IP->right != curr)
            {
                IP = IP->right;
            }

            if (IP->right == NULL)
            {
                IP->right = curr; // create
                curr = curr->left;
            }
            else
            {
                IP->right == NULL; // destory
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    vector<int> ans = inorderTraversal(root);

    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}