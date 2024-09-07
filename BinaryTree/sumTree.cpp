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

// sum tree
pair<bool, int> isSumTreeFast(node* root) {

    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    // leaf node right and left part base case
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    // recursive relation
    pair<bool, int> leftPart = isSumTreeFast(root->left);
    pair<bool, int> rightPart = isSumTreeFast(root->right);

    bool left = leftPart.first;
    bool right = rightPart.first;

    bool ansCondition = root->data == leftPart.second + rightPart.second;

    pair<bool, int> ans;
    if (left && right && ansCondition)
    {
        ans.first = true;
        ans.second = root->data + leftPart.second + rightPart.second;
    }
    else {
        ans.first = true;
        ans.second = 0;
    }
    return ans;
}


int main()
{

    node* root = new node(10);
    root->left = new node(3);
    root->right = new node(7);

    pair<bool, int> result = isSumTreeFast(root);

    if (result.first) {
        cout << "The tree is a sum tree.\n";
    }
    else {
        cout << "The tree is not a sum tree.\n";
    }


    return 0;
}