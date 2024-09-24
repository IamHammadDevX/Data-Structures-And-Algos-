#include<iostream>
#include<queue>
#include<vector>
using namespace std;

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

// InOrder Traversal L-N-R
void inOrderTraversal(node* root) {

    // L - N - R
    // base case
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << endl;
    inOrderTraversal(root->right);

}

// Two Sum in a BST
void inOrder(node* root, vector<int>& in) {

    // base case
    if (root == NULL)
    {
        return;
    }

    // INORDER => LNR
    inOrder(root->left, in);
    in.push_back(root->data); //1 2 3 4 5 6 7...
    inOrder(root->right, in);

}

node* inorderToBst(int s, int e, vector<int>& in) {

    // base case
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    node* root = new node(in[mid]);

    // recursive left and right
    root->left = inorderToBst(0, mid - 1, in);
    root->right = inorderToBst(mid + 1, e, in);

    return root;
}

node* balanceBst(node* root) {

    vector<int> inOrderValue;
    // store inOrder
    inOrder(root, inOrderValue);

    return inorderToBst(0, inOrderValue.size() - 1, inOrderValue);
}


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

int main()
{

    node* root = NULL;

    cout << "Enter the data to create BST: " << endl;
    takeInput(root);

    node* balance = balanceBst(root);

    cout << "Balance: " << balance->data << endl;

    return 0;
}