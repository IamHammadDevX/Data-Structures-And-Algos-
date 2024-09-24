#include<iostream>
#include<queue>
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

// InOrder Traversal L-N-R
void inOrderTraversal(node* root) {

    // L - N - R
    // base case
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << endl;
    inOrderTraversal(root->right);

}

// Two Sum in a BST
void inOrder(node* root, vector<int>& in) {

    // base case
    if (root == NULL)
    {
        return;
    }

    // INORDER => LNR
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);

}

bool twoSumInBst(node* root, int target) {

    vector<int> inOrderValue;
    inOrder(root, inOrderValue);
    // two ptr approach
    int i = 0, j = inOrderValue.size() - 1;

    while (i < j)
    {
        int sum = inOrderValue[i] + inOrderValue[j];
        if (sum == target)
            return true;

        else if (sum > target)
            j--;

        else
            i++;
    }

    return false;

}


node* insertIntoBst(node* root, int d) {

    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    // recursive relations
    if (d > root->data)
    {
        // right part me insert kerna hai
        root->right = insertIntoBst(root->right, d);
    }
    if (d < root->data)
    {
        // left part me insert kerna hai
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}

// take input for BST
void takeInput(node*& root) {

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

int main()
{

    node* root = NULL;

    cout << "Enter the data to create BST: " << endl;
    takeInput(root);

    int target = 20;

    if (twoSumInBst(root, target))
    {
        cout << "Two sum is exist!" << endl;
    }
    else
    {
        cout << "Two sum is not exist!" << endl;
    }




    return 0;
}