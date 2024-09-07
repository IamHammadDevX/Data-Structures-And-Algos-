#include<iostream>
#include<vector>
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

// zig zag traversal
vector<int> zigZagTraversal(node* root) {

    vector<int> result;
    // base case
    if (root == NULL)
    {
        return result;
    }

    // take a queue
    queue<node*> q;
    q.push(root);

    // direction flag
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            // take a front elem of queue
            node* frontElem = q.front();
            q.pop();

            // insertion 
            // normal = left to right
            int idx = leftToRight ? i : size - i - 1;
            // put data of frontElem to queue
            ans[idx] = frontElem->data;

            if (frontElem->left)
            {
                q.push(frontElem->left);
            }
            if (frontElem->right)
            {
                q.push(frontElem->right);
            }


            for (auto i : ans) {
                result.push_back(i);
            }

            // change the direction
            leftToRight = !leftToRight;

        }

    }
    return result;
}





int main()
{

    // Example usage
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> traversal = zigZagTraversal(root);

    for (int val : traversal) {
        cout << val << " ";
    }


    return 0;
}