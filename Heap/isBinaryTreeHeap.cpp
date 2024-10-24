#include<bits/stdc++.h>
using namespace std;

// isBinaryTree Heap???
class node {

public:
    int data;
    node* left;
    node* right;

    // constructor
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBst(node* root, int d) {

    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    // recursive relations
    if (d > root->data)
    {
        // right part me insert kerna hai
        root->right = insertIntoBst(root->right, d);
    }
    if (d < root->data)
    {
        // left part me insert kerna hai
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}

// take input for BST
void takeInput(node*& root) {

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

// Count Nodes
int countNodes(node* root) {

    if (root == NULL)
    {
        return 0;
    }

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

// isCBT
bool isCBT(node* root, int idx, int cnt) {

    // base case
    if (root == NULL)
        return true;

    if (idx >= cnt)

        return false;

    else
    {
        bool left = isCBT(root->left, 2 * idx + 1, cnt);
        bool right = isCBT(root->right, 2 * i + 2, cnt);

        return (left && right);
    }

}

// isMaxOrder Property
bool isMaxOrder(node* root) {
    // base case
    // leaf Node check
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    // only left node
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }

    // both child exist
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}


// isBinary Heap???
bool isHeap(node* tree) {

    int idx = 0;
    int totalCount = countNodes(tree);
    if (isCBT(tree, idx, totalCount) && isMaxOrder(tree))
    {
        return true;
    }
    else
        return false;
}

int main()
{

    


    return 0;
}