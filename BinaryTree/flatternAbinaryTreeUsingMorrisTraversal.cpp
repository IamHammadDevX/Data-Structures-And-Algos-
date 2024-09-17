#include<iostream>
using namespace std;

class node {
public:
    node* left;
    node* right;
    int data;

    // constructor
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Morris Traversal
// flattern a binary tree
void flatten(node* root) {

    node* curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            node* pred = curr->left;
            while (pred->right)
            {
                // right me jata ja
                pred = pred->right;

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
        }
        // set the predecessor
        curr = curr->right;
    }
}


int main()
{

    node* root = new node(1);
    root->left = new node(3);
    root->right = new node(4);
    root->right->left = new node(2);
    root->right->left->right = new node(5);

    flatten(root);


    return 0;
}