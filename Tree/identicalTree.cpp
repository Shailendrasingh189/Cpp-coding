#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build Tree from Preorder
Node* buildTree(vector<int>& preorder, int& idx) {
    if (idx >= preorder.size() || preorder[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    idx++;
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);
    return root;
}

// Identical Trees
bool isIdentical(Node* p, Node* q) {
    if (p == NULL || q == NULL)
        return p == q;

    return (p->data == q->data) &&
           isIdentical(p->left, q->left) &&
           isIdentical(p->right, q->right);
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    int idx1 = 0, idx2 = 0;
    Node* p = buildTree(preorder, idx1);
    Node* q = buildTree(preorder, idx2);

    cout << "Trees are Identical: " << (isIdentical(p, q) ? "Yes" : "No") << endl;

    return 0;
}
