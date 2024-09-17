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

int solve(node* root, int& i, int k) {

    // base case
    if (root == NULL)
    {
        return -1;
    }

    // LNR
    // L -> left call
    int left = solve(root->left, i, k);
    // data print in inOrder Traversal
    if (left != -1)
    {
        return left;
    }
    i++;
    // right ki call
    if (i == k)
    {
        return root->data;
    }

    return solve(root->right, i, k);

}

int kthSmallestElem(node* root, int k) {
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

// kth largest elem
int largest(node* root, int& i, int k) {

    // base case
    if (root == NULL)
    {
        return -1;
    }

    // RNL
    // right ki call
    int right = largest(root->right, i, k);

    if (right != -1)
    {
        return right;
    }

    i++;

    // equal to case
    if (i == k)
    {
        return root->data;
    }

    // left ki call
    return largest(root->left, i, k);

}

int kthLargestElem(node* root, int k) {

    int i = 0;
    int ans = largest(root, i, k);
    return ans;

}

int main()
{

    node* root = NULL;

    cout << "Enter the data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST By Level order Traversal => " << endl;
    levelOrderTraversal(root);

    int kthElem = kthSmallestElem(root, 3);
    cout << "Kth Smallest Element: " << kthElem << endl;
    int kthLarge = kthLargestElem(root, 3);
    cout << "Kth largest elem: " << kthLarge << endl;

    return 0;
}