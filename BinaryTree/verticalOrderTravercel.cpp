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


// Vertical Order traversal
vector<int> verticalOrderTraversal(node* root) {

    // make a data structor
    map<int, map<int, vector<int> > > nodes;
    queue<pair<node*, pair<int, int> > > q;
    vector<int> ans;

    // base case
    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));


    while (!q.empty())
    {
        pair<node*, pair<int, int> > temp = q.front();
        q.pop();
        // front elem
        node* frontNode = temp.first;
        // horizontal distance
        int hd = temp.second.first;
        // level
        int lvl = temp.second.second;

        // map
        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }

        for (auto i : nodes) {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }

        }

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

    vector<int> verticalView = verticalOrderTraversal(root);
    for (auto i : verticalView) {
        cout << i << " ";
    }cout << endl;

    return 0;
}