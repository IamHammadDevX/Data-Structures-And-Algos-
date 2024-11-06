#include<iostream>
#include<queue>
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

// make info class
class info {
public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};


// InOrder Traversal L-N-R
void inOrderTraversal(node* root) {

    // L - N - R
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive function
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// PreOrder traversal = n - l - r
void preOrderTraversal(node* root) {

    // base case
    if (root == NULL)
    {
        return;
    }

    // N - L - R
    // recursive function
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}


// PostOrder traversal = L - R - N
void postOrderTraversal(node* root) {

    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive call
    // L - R - N
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

/// Level Order traversal
void levelOrderTraversal(node* root) {
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Marker for the end of the current level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // We have reached the end of the current level
            cout << endl;
            if (!q.empty()) {
                // Add a marker for the next level
                q.push(NULL);
            }
        }
        else {
            // Print the current node's data
            cout << temp->data << " ";

            // Enqueue left child
            if (temp->left) {
                q.push(temp->left);
            }

            // Enqueue right child
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
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

// Largest BST
info solve(node* root, int& ans) {

    // base case
    if (root == NULL)
    {
        return { INT_MIN, INT_MAX, true, 0 };
    }

    // recursive case
    // left & right call
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    // maxi and mini
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    // check BST
    if (left.isBst && right.isBst && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBst = true;
    }
    else
    {
        currNode.isBst = false;
    }

    // answer update
    if (currNode.isBst)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBst(node* root) {

    int maxSize = 0;
    info temp = solve(root, maxSize);

    return maxSize;
}


int main()
{

    node* root = NULL;

    // Input the BST data
    cout << "Enter the data to create BST (-1 to end input): " << endl;
    takeInput(root);

    // Printing the BST using Level Order Traversal
    cout << "Printing the BST by Level Order Traversal => " << endl;
    levelOrderTraversal(root);

    // Finding the largest BST in the binary tree
    int largestBSTSize = largestBst(root);
    cout << "The size of the largest BST in the given tree is: " << largestBSTSize << endl;

    return 0;
}