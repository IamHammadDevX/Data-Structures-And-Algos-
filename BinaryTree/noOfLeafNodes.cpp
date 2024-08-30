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


// build level order traversal
void buildLevelOrderTraversal(node*& root) {

    queue<node*> q;
    int data;
    cout << "Enter the root elem: ";
    cin >> data;

    root = new node(data);

    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout << "Enter the left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }


        cout << "Enter the right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// max height of the tree
int heightOfTree(node* root) {

    // base case
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    int ans = max(left, right) + 1;

    return ans;
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

int main()
{

    node* root = NULL;

    // Building the tree using level order input
    buildLevelOrderTraversal(root);

    // Displaying the level order traversal of the tree
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    // Calculating and displaying the height of the tree
    cout << "Height of the Tree: " << heightOfTree(root) << endl;


    return 0;
}