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


// bottom View tree
vector<int> bottomView(node* root) {

    // answer vector mein
    vector<int> ans;
    //base case
    if (root == NULL)
    {
        return ans;
    }

    // make a map
    map<int, int> topNode;
    queue<pair<node*, int> > q;


    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second;


        topNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode) {
        ans.push_back(i.second);
    }

    return ans;

}

int main()
{

    // output still pending.......
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> bottom = bottomView(root);
    for (auto i : bottom) {
        cout << i << " ";
    }

    return 0;
}