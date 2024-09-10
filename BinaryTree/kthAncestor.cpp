#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

// Kth Ancestor
// Kth Ancestor
bool solve(node* root, int& k, int Node, node*& ancestor) {
    // base case
    if (root == NULL) {
        return false;
    }
    if (root->data == Node) {
        return true;
    }

    // Search in the left and right subtrees
    bool foundInLeft = solve(root->left, k, Node, ancestor);
    bool foundInRight = solve(root->right, k, Node, ancestor);

    // If the Node was found in either subtree
    if (foundInLeft || foundInRight) {
        k--;
        if (k == 0) {
            ancestor = root;
        }
        return true; // Continue returning true to propagate up the tree
    }

    return false; // Node not found in this subtree
}

int kthAncestor(node* root, int k, int Node) {
    node* ancestor = NULL;
    solve(root, k, Node, ancestor);

    // Return the data if the ancestor exists, otherwise -1
    return (ancestor != NULL) ? ancestor->data : -1;
}

int main()
{

    // Creating the binary tree
    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(6);
    root->left->left = new node(8);
    root->left->right = new node(1);
    root->left->right->left = new node(6);
    root->right->left = new node(2);
    root->right->right = new node(3);

    // Define the node and k value
    int Node = 6;  // Node whose ancestor we want to find
    int k = 2;     // We want to find the 2nd ancestor

    // Find and output the kth ancestor
    int ancestor = kthAncestor(root, k, Node);

    if (ancestor == -1) {
        cout << "The " << k << "th ancestor of node " << Node << " does not exist." << endl;
    }
    else {
        cout << "The " << k << "th ancestor of node " << Node << " is: " << ancestor << endl;
    }



    return 0;
}