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

    // base case
    if (preorder[idx] == -1)
    {
        return NULL;
    }

    // create root node
    Node *root = new Node(preorder[idx]);

    // left sub tree recursion call
    root->left = buildTree(preorder);

    // right sub tree recursion call
    root->right = buildTree(preorder);

    return root;
}

int maxWidthOfBinaryTree(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    int maxWidth = 0;

    while (q.size() > 0)
    {
        int currLevelSize = q.size();
        int stIdx = q.front().second;
        int endIdx = q.back().second;

        maxWidth = max(maxWidth, endIdx - stIdx + 1);

        for (int i = 0; i < currLevelSize; i++)
        {
            auto curr = q.front();
            q.pop();

            if (curr.first->left)
            {
                q.push({curr.first->left, curr.second * 2 + 1});
            }

            if (curr.first->right)
            {
                q.push({curr.first->right, curr.second * 2 + 2});
            }
        }
    }

    return maxWidth;
}

int main()
{
    vector<int> preorder = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9, -1, -1};
    Node *root = buildTree(preorder);

    cout << maxWidthOfBinaryTree(root) << endl;

    return 0;
}