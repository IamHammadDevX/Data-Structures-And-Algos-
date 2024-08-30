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

// Calculate the diameter of the tree
pair<int, int> diameterFast(node*& root) {
    if (root == NULL) {
        return make_pair(0, 0);
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(node*& root) {
    return diameterFast(root).first;
}

int main() {
    node* root = NULL;

    // Building the tree using level order input
    buildLevelOrderTraversal(root);

    // Displaying the level order traversal of the tree
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    // Calculating and displaying the diameter of the tree
    cout << "Diameter of the Tree: " << diameter(root) << endl;

    return 0;
}
