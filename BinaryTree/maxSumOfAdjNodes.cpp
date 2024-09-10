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

// maxSum of nonAdjacent Nodes
pair<int, int> solve(node* root) {

    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    // left recursive & right one
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    // including
    res.first = root->data + left.second + right.second;
    // excluding
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
}


int getMaxSum(node* root) {

    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}

int main()
{

    // Creating the binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);

    int ans = getMaxSum(root);
    cout << "Maximum sum of non-adjacent nodes: " << ans << endl;
    
    return 0;
}