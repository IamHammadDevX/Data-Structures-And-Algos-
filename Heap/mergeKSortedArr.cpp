#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    int i;
    int j;
    node(int data, int row, int col) {
        this->data = data;
        this->i = row;
        this->j = col;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

// mergekSortedArrays
vector<int> mergeKthSortedArr(vector<vector<int> >& Karrs, int k) {

    // min_heap
    priority_queue<node*, vector<node*>, compare > minHeap;

    // saare arrays k first elem push karo
    for (int i = 0; i < k; i++)
    {
        node* temp = new node(Karrs[i][0], i, 0);
        minHeap.push(temp);
    }
    vector<int> ans;

    while (minHeap.size() > 0)
    {
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        // present!!!???
        if (j + 1 < Karrs[i].size())
        {
            node* next = new node(Karrs[i][j + 1], i, j + 1);
            minHeap.push(next);
        }

    }
    return ans;
}

int main()
{




    return 0;
}