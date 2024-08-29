#include<iostream>
#include<queue>
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

    // data lele
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
// print the tree
void levelOrderTraversal(node* root) {
    // take queue
    queue<node*> q;
    q.push(root);

    // separator add and hit enter to new line
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();


        if (temp == NULL)
        {
            // old level completed
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        // empty nahi hai
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

    }
}



int main()
{

    // take root elem
    node* root = NULL;

    // creating a tree
    root = buildTree(root);

    // printing the tree
    levelOrderTraversal(root);

    return 0;
}
