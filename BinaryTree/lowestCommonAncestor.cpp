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

// LCA = LOWEST COMMON ANCESTOR
node* lca(node* root, int n1, int n2) {

    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node* leftAns = lca(root->left, n1, n2);
    node* rightAns = lca(root->right, n1, n2);

    // permutations lga lete hain
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
        return NULL;
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

    // Finding LCA of two nodes
    int n1 = 8, n2 = 1;
    node* lcaNode = lca(root, n1, n2);

    if (lcaNode != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lcaNode->data << endl;
    }
    else {
        cout << "LCA does not exist in the tree." << endl;
    }



    return 0;
}