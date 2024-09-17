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


// max & min node in BST
node* minValue(node* root) {
    node* minNode = root;

    while (minNode->left != NULL)
    {
        minNode = minNode->left;
    }

    return minNode;
}
// MAX NODE
node* maxValue(node* root) {
    node* maxNode = root;

    while (maxNode->right != NULL)
    {
        maxNode = maxNode->right;
    }

    return maxNode;
}

// DELETE THE NODE
node* deleteFromBST(node* root, int val) {
    // base case
    if (root == NULL)
    {
        return root;
    }

    // value mill gai hai
    if (root->data == val)
    {
        // 0 child case
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child case
        // left & right cases
        // left wala
        if (root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            // right wala
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child case
        if (root->left != NULL && root->right != NULL)
        {
            // yn to right me se min value lelo
            // yn left me se max value lelo
            int mini = minValue(root)->data;
            // copy kerdo
            root->data = mini;
            // right me jata ja
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        // left me jana hai
        // RECURSIVELY
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
        // right me jana hai
        root->right = deleteFromBST(root->right, val);
    return root;
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
    cout << "Printing the BST By Level order Traversal => " << endl;
    levelOrderTraversal(root);

    cout << endl << "Printing inOrder => " << endl;
    inOrderTraversal(root);
    cout << endl << "Printing preOrder => " << endl;
    preOrderTraversal(root);
    cout << endl << "Printing postOrder => " << endl;
    postOrderTraversal(root);

    cout << endl << "Min Node in BST => " << minValue(root)->data << endl;
    cout << "Max Node in BST => " << maxValue(root)->data << endl;

    cout << "DELETION" << endl;
    deleteFromBST(root, 30);

    cout << "Printing the BST By Level order Traversal => " << endl;
    levelOrderTraversal(root);

    cout << endl << "Printing inOrder => " << endl;
    inOrderTraversal(root);
    cout << endl << "Printing preOrder => " << endl;
    preOrderTraversal(root);
    cout << endl << "Printing postOrder => " << endl;
    postOrderTraversal(root);

    cout << endl << "Min Node in BST => " << minValue(root)->data << endl;
    cout << "Max Node in BST => " << maxValue(root)->data << endl;

    // int key;
    // cout << "Enter the key to search in BST: ";
    // cin >> key;
    // if (searchInBst(root, key)) {
    //     cout << "Key is found!" << endl;
    // }
    // else
    // {
    //     cout << "Key is not found!" << endl;
    // }



    return 0;
}