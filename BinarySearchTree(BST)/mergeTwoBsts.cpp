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
void inOrderTraversal(node* root, vector<int>& in) {

    // L - N - R
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive function
    inOrderTraversal(root->left, in);
    cout << root->data << " ";
    in.push_back(root->data);
    inOrderTraversal(root->right, in);
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

// merge two sorted BSTS
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {

    // merge the a + b = c;
    vector<int> c(a.size() + b.size());

    // two ptrs i for vect a, j for vect b
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i];
            i++;
        }
        else
        {
            c[k++] = b[j];
            j++;
        }
    }

    while (i < a.size())
    {
        c[k++] = a[i];
        i++;
    }

    while (j < b.size())
    {
        c[k++] = b[j];
        j++;
    }

    return c;
}

node* inorderToBst(int s, int e, vector<int>& in) {

    // base case
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    node* root = new node(in[mid]);

    // recursive left and right
    root->left = inorderToBst(s, mid - 1, in);
    root->right = inorderToBst(mid + 1, e, in);

    return root;
}

void convertIntoSortedDLL(node* root, node*& head)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive functions
    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if (head != NULL)
    {
        head->left = root;
    }


    head = root;
    convertIntoSortedDLL(root->left, head);
}
// merge Sorted LL
node* mergeLinkedList(node* head1, node* head2) {
    node* head = NULL;
    node* tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }

        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }

    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }


    return head;

}


node* mergeTwoBsts(node* root1, node* root2) {

    // step 1: Stores 2 bsts InOrder

    vector<int> bst1, bst2;
    // 1st BST
    inOrderTraversal(root1, bst1);
    // 2nd BST
    inOrderTraversal(root2, bst2);

    // Merge two arrays
    vector<int> mergedArray = mergeArrays(bst1, bst2);

    // Build a new BST from the merged inorder array
    int s = 0, e = mergedArray.size() - 1;
    return inorderToBst(s, e, mergedArray);
}

int main()
{
    node* root1 = NULL;
    node* root2 = NULL;

    cout << "Enter the data to create the first BST (-1 to end input): " << endl;
    takeInput(root1);

    cout << "Enter the data to create the second BST (-1 to end input): " << endl;
    takeInput(root2);

    cout << "Merging the two BSTs..." << endl;
    node* mergedRoot = mergeTwoBsts(root1, root2);

    cout << "Printing the merged BST by Level Order Traversal => " << endl;
    levelOrderTraversal(mergedRoot);

    return 0;
}
