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

// sum of nodes along the longest path

void solve(node* root, int sum, int& maxSum, int len, int& maxLen) {

    // base case
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    // root data ko add
    sum = sum + root->data;
    // left recursive call
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}


int sumOfLongRootToLeafPath(node* root) {

    // lens <len, maxLen>
    int len = 0, maxLen = 0;

    int sum = 0, maxSum = 0;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}

int main()
{

    // output still pending.......
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(7);
    root->left->right = new node(1);
    root->left->right->left = new node(6);
    root->right->left = new node(2);
    root->right->right = new node(3);

    int sumOfLongestPath = sumOfLongRootToLeafPath(root);
    cout << "Sum of longest path: " << sumOfLongestPath << endl;

    return 0;
}