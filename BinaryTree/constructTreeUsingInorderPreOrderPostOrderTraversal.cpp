#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

// construction Binary Tree
int findPosition(int inOrder[], int elem, int size) {

    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == elem)
        {
            return i;
        }

    }
    return -1;
}


node* solve(int inOrder[], int preOrder[], int& preIdx, int inOrderStart, int inOrderEnd, int size) {

    // base case
    if (preIdx >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // buddy root element nikale
    int rootElem = preOrder[preIdx++];
    // make a node
    node* root = new node(rootElem);
    // posiition nikalo
    int position = findPosition(inOrder, rootElem, size);

    // recursive calls
    root->left = solve(inOrder, preOrder, preIdx, inOrderStart, position - 1, size);
    root->right = solve(inOrder, preOrder, preIdx, position + 1, inOrderEnd, size);


    return root;
}


node* buildTree(int inOrder[], int preOrder[], int size) {

    int preOrderIdx = 0;
    node* ans = solve(inOrder, preOrder, preOrderIdx, 0, size - 1, size);

    return ans;
}


// print tree
void printInOrder(node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{


    // Sample inorder and preorder traversals
    int inOrder[] = { 4, 2, 5, 1, 6, 3, 7 };
    int preOrder[] = { 1, 2, 4, 5, 3, 6, 7 };
    int size = sizeof(inOrder) / sizeof(inOrder[0]);

    // Build the tree
    node* root = buildTree(inOrder, preOrder, size);

    // Print the tree (in-order traversal)
    cout << "In-order traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;




    return 0;
}