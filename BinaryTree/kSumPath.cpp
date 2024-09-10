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

// K SUM PATH K=5;
void solve(node* root, int k, int& cnt, vector<int> path) {

    // base case
    if (root == NULL)
    {
        return;
    }

    // root ko push kerde vector
    path.push_back(root->data);

    // left recursive call & right
    solve(root->left, k, cnt, path);
    solve(root->right, k, cnt, path);

    int size = path.size();

    // start from leaf node and cnt++ if k cnt find
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        // add leaf node to vector
        sum = sum + path[i];
        if (sum == k)
        {
            cnt++;
        }
    }

    path.pop_back();

}


int sumK(node* root, int k) {

    vector<int> path;
    int cnt = 0;

    solve(root, k, cnt, path);

    return cnt;
}

int main()
{

    // Creating the binary tree
    // Creating the binary tree
    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(6);
    root->left->left = new node(8);
    root->left->right = new node(1);
    root->left->right->left = new node(6);
    root->right->left = new node(2);
    root->right->right = new node(3);

    // Define the target sum k
    int k = 5;

    // Call sumK function to count paths that sum to k
    int countPaths = sumK(root, k);

    // Output the result
    cout << "Number of paths with sum " << k << " is: " << countPaths << endl;

    return 0;
}