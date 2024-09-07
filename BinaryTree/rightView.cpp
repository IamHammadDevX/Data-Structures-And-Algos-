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


// right View tree
void solve(node* root, vector<int>& ans, int level) {
    // base case
    if (root == NULL)
    {
        return;
    }

    // next level reached
    if (level == ans.size())
    {
        // mean next level reached
        ans.push_back(root->data);
    }

    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);

}

vector<int> rightView(node* root) {

    vector<int> ans;
    solve(root, ans, 0);
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

    vector<int> rightEyeViewOfTree = rightView(root);
    for (auto i : rightEyeViewOfTree) {
        cout << i << " ";
    }

    return 0;
}