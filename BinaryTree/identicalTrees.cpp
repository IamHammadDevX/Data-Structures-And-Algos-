#include<iostream>
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

// identical trees
bool isIdenticalTrees(node* root1, node* root2) {

    // base case
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }


    // recursive relation
    bool left = isIdenticalTrees(root1->left, root2->left);
    bool right = isIdenticalTrees(root1->right, root2->right);
    bool value = root1->data == root2->data;

    return left && right && value;
}


int main()
{

    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);

    if (isIdenticalTrees(root1, root2)) {
        cout << "The trees are identical." << endl;
    }
    else {
        cout << "The trees are not identical." << endl;
    }


    return 0;
}