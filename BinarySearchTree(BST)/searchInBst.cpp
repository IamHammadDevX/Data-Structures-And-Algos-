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


node* insertBst(node* root, int d) {

    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        //right part
        root->right = insertBst(root->right, d);
    }
    if (d < root->data)
    {
        //left part
        root->left = insertBst(root->left, d);
    }

    return root;
}

void takeInput(node*& root) {

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertBst(root, data);
        cin >> data;
    }
}


// Search in a BST
bool searchInBst(node* root, int key) {

    // base case
    if (root == NULL)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    // recursive calls
    if (root->data > key)
    {
        // left part
        return searchInBst(root->left, key);
    }
    else
    {
        // right part
        return searchInBst(root->right, key);
    }
}

int main()
{

    node* root = NULL;

    cout << "Enter the data to create BST: " << endl;
    takeInput(root);
    // cout << "Printing the BST By Level order Traversal => " << endl;
    // levelOrderTraversal(root);

    int key;
    cout << "Enter the key to search in BST: ";
    cin >> key;
    if (searchInBst(root, key)) {
        cout << "Key is found!" << endl;
    }
    else
    {
        cout << "Key is not found!" << endl;
    }



    return 0;
}