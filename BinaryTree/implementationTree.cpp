#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


// creatiion of tree
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

// build tree
node* buildTree(node* root) {

    // data pakro
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;
    root = new node(data);

    // -1 = NULL
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data in the left of: " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data in the right of: " << data << endl;
    root->right = buildTree(root->right);

    return root;
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

// reverse the order travesal
void reverseLevelOrderTraversal(node* root) {

    // take a vector to rever the answer
    vector<int> ans;
    // base case
    if (!root)
    {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

}

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
// Number of leaf node
void inOrderTraversalForNoOfLeafNodes(node* root, int cnt) {

    // L - N - R
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive function
    inOrderTraversalForNoOfLeafNodes(root->left, cnt);

    // check the condition for leaf
    if (root->left == NULL || root->right == NULL)
    {
        cnt++;
    }

    inOrderTraversalForNoOfLeafNodes(root->right, cnt);
}

// Number of leaf nodes main logic
int noOfLeafNodes(node* root) {
    int cnt = 0;
    inOrderTraversalForNoOfLeafNodes(root, cnt);
    return cnt;
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


int main()
{

    // take root elem
    node* root = NULL;


    buildLevelOrderTraversal(root);
    levelOrderTraversal(root);
    // creating a tree
    // root = buildTree(root);

    // // printing the tree
    // levelOrderTraversal(root);

    // cout << endl << "Reversing the binary tree :";
    // reverseLevelOrderTraversal(root);

    // // Inorder Traversal
    // cout << endl << "InOrder Taversal: ";
    // inOrderTraversal(root);


    // // Preorder Traversal
    // cout << endl << "preOrder Taversal: ";
    // preOrderTraversal(root);



    // // Postorder Traversal
    // cout << endl << "postOrder Taversal: ";
    // postOrderTraversal(root);





    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
