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
    // base case
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right, in);
}

// PreOrder traversal = n - l - r
void preOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// PostOrder traversal = L - R - N
void postOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Level Order traversal
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
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
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

node* insertIntoBst(node* root, int d) {
    if (root == NULL) {
        root = new node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBst(root->right, d);
    } else if (d < root->data) {
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}

// Take input for BST
void takeInput(node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

// Merge two sorted arrays
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> c(a.size() + b.size());
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < a.size()) {
        c[k++] = a[i++];
    }

    while (j < b.size()) {
        c[k++] = b[j++];
    }

    return c;
}

node* inorderToBst(int s, int e, vector<int>& in) {
    if (s > e) {
        return NULL;
    }
    int mid = (s + e) / 2;
    node* root = new node(in[mid]);
    root->left = inorderToBst(s, mid - 1, in);
    root->right = inorderToBst(mid + 1, e, in);
    return root;
}

void convertIntoSortedDLL(node* root, node*& head) {
    if (root == NULL) {
        return;
    }
    convertIntoSortedDLL(root->right, head);
    root->right = head;

    if (head != NULL) {
        head->left = root;
    }

    head = root;
    convertIntoSortedDLL(root->left, head);
}

// Merge sorted linked lists
node* mergeLinkedList(node* head1, node* head2) {
    node* head = NULL;
    node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(node* head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->right;
    }
    return cnt;
}

node* sortedLLtoBst(node*& head, int n) {
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    node* left = sortedLLtoBst(head, n / 2);
    node* root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLtoBst(head, n - n / 2 - 1);
    return root;
}

node* mergeTwoBsts(node* root1, node* root2) {
    node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    node* head = mergeLinkedList(head1, head2);
    return sortedLLtoBst(head, countNodes(head));
}

// Memory cleanup function
void deleteTree(node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    node* root1 = NULL;
    node* root2 = NULL;

    // Input for the first BST
    cout << "Enter the data to create the first BST (-1 to end input): " << endl;
    takeInput(root1);

    // Input for the second BST
    cout << "Enter the data to create the second BST (-1 to end input): " << endl;
    takeInput(root2);

    // Merging the two BSTs
    cout << "Merging the two BSTs..." << endl;
    node* mergedRoot = mergeTwoBsts(root1, root2);

    // Printing the merged BST using Level Order Traversal
    cout << "Printing the merged BST by Level Order Traversal => " << endl;
    levelOrderTraversal(mergedRoot);

    // Memory cleanup
    deleteTree(mergedRoot);
    deleteTree(root1);
    deleteTree(root2);

    return 0;
}
