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

// Construct BST from PreOrder = n - l - r
node* solve(vector<int>& pre, int mini, int maxi, int& i) {

    // base casses
    if (i >= pre.size())
    {
        return NULL;
    }

    // out of range
    if (pre[i] < mini || pre[i] > maxi)
    {
        return NULL;
    }

    // recursive case
    node* root = new node(pre[i++]);
    root->left = solve(pre, mini, root->data, i);
    root->left = solve(pre, root->data, root->data, i);
    return root;
}
node* preOrderBst(vector<int>& preOrd) {

    // range identify
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preOrd, mini, maxi, i);

}


int main()
{

    node* root = NULL;

    cout << "Enter the data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST By Level order Traversal => " << endl;
    levelOrderTraversal(root);

    vector<int> preOrderInput = { 10, 5, 1, 7, 40, 50 };  // example pre-order input
    node* preOrderRoot = preOrderBst(preOrderInput);

    cout << "Printing BST constructed from PreOrder traversal => " << endl;
    levelOrderTraversal(preOrderRoot);


    return 0;
}