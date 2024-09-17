#include<iostream>
#include<map>
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

// Minimum time required to burn a tree
// map with parent
// target find
node* createParentMapping(node* root, int target, map<node*, node*>& nodeToParent) {

    node* res;
    // make a queue
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        node* front = q.front();
        q.pop();

        // search the target
        if (front->data == target)
        {
            res = front;
        }

        if (front->left)
        {
            // agar left part hai target node ka then uska parent front hoga vice versa for right
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            // agar left part hai target node ka then uska parent front hoga vice versa for right
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(node* root, map<node*, node*>& nodeToParent) {


    map<node*, bool> visited;

    queue<node*> q;
    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = 0;
        // process the neighbouring nodes
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node* front = q.front();
            q.pop();

            // left part
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if (nodeToParent[front] && !visited[front])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }

        if (flag == 1)
        {
            ans++;
        }


    }
    return ans;
}

int minTime(node* root, int target) {

    // Algo
    // 1 - create a node to parent mapping
    // 2 - find target node
    // 3 - burn the tree in min time

    ;
    map<node*, node*> nodeToParent;
    node* targetNode = createParentMapping(root, target, nodeToParent);

    int time = burnTree(targetNode, nodeToParent);

    return time;
}

int main()
{

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->right->right->right = new node(9);
    root->right->right->right->right = new node(10);

    int target = 9;

    int burnTime = minTime(root, target);
    cout << "Minimum time to burn a tree: " << burnTime << endl;

    return 0;
}