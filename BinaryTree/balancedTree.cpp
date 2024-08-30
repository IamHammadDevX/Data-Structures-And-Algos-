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

// Build the tree using level order traversal
void buildLevelOrderTraversal(node*& root) {
    queue<node*> q;

    int data;
    cout << "Enter the root elem: ";
    cin >> data;
    root = new node(data);

    q.push(root);  // Push the root node into the queue

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter the data for the left of node: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the data for the right of node: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// Display the tree using level order traversal
void levelOrderTraversal(node*& root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Marker for the end of the current level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// isBalanced tree <=1
pair<bool, int> isBalancedFast(node*& root) {

    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }


    // left call
    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);

    // save the ans in bool
    bool leftAns = left.first;
    bool rightAns = right.first;

    // difference
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isBalanced(node*& root) {
    return isBalancedFast(root).first;
}
int main() {
    node* root = NULL;

    // Building the tree using level order input
    buildLevelOrderTraversal(root);

    // Displaying the level order traversal of the tree
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    if (isBalanced)
    {
        cout << "Tree is balanced!" << endl;
    }
    else
    {
        cout << "Tree is not balanced!" << endl;
    }



    return 0;
}
