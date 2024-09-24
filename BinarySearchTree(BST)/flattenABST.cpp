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

node* flatten(node* root) {

    vector<int> inOrderValue;
    // store inOrder
    inOrder(root, inOrderValue);
    int n = inOrderValue.size();
    // new Node
    // newRoot = 1;
    node* newRoot = new node(inOrderValue[0]);

    // current node
    node* curr = newRoot;

    for (int i = 1; i < n; i++)
    {
        // tempnode chahiye to store the newRoot next value;
        node* temp = new node(inOrderValue[i]);

        curr->left = NULL;
        curr->right = temp;

        curr = temp;
    }

    // final step me
    curr->left = NULL;
    curr->right = NULL;


    return newRoot;
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

int main(
{

    node* root = NULL;

    cout << "Enter the data to create BST: " << endl;
    takeInput(root);

    node* list = flatten(root);

    cout << "List ka root: " << list->data << endl;



    return 0;
}