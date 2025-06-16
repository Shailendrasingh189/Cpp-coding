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

    Node *helper(vector<int> &nums, int st, int end)
    {
        if (st > end)
        {
            return NULL;
        }

        int mid = st + (end - st) / 2;
        Node *root = new Node(nums[mid]);

        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    Node *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
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
    vector<int> arr = {-10, -3, 0, 5, 9};

    Node *root = sortedArrayToBST(arr);

    cout << "Pre-order Traversal of Balanced BST: ";
    preorder(root);
    cout << endl;

    return 0;
}