#include<iostream>
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


// Boundry traversal
void traverseLeft(node* root, vector<int>& ans) {

    // base case
    // yan phr leaf node hai
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    // push to ans
    ans.push_back(root->data);

    if (root->left)
        traverseLeft(root->left, ans);
    else
    {
        traverseLeft(root->right, ans);
    }
}

//traverse the leaf
void traverseLeaf(node* root, vector<int>& ans) {

    // base case
    if (root == NULL)
    {
        return;
    }

    // leaf node push
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    // no need to check the left right part in leaf node bcz leaf is ending node
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

// traverse right
void traverseRight(node* root, vector<int>& ans) {

    // base case
        // yan phr leaf node hai
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    // right part
    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);

}

vector<int> boundry(node* root) {

    vector<int> ans;

    // base case
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // print left part without leaf node
    traverseLeft(root->left, ans);

    // print the leaf nodes
    // left subTree
    traverseLeaf(root->left, ans);
    // right subTree
    traverseLeaf(root->right, ans);

    // right part
    traverseRight(root->right, ans);


    return ans;
}

int main()
{

    // output still pending.......
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> boundryView = boundry(root);
    for (auto i : boundryView) {
        cout << i << " ";
    }

    return 0;
}