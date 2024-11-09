#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// smallest range own data structure
class node {
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// own comperator
class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

int kSortedLists(vector<vector<int> >& arr, int k, int n) {

    // take mini & maxi elems
    int mini = INT_MAX, maxi = INT_MIN;
    // min_heap construct
    priority_queue<node*, vector<node*>, compare > minHeap;

    // har list ka 1st elems heap me push karo
    for (int i = 0; i < k; i++)
    {
        // 1st elem of every list mean 0row, 1col
        int elem = arr[i][0];
        // update mini and maxi
        mini = min(mini, elem);
        maxi = max(maxi, elem);
        // push to heap
        minHeap.push(new node(elem, i, 0));
    }

    // start and end range
    int start = mini, end = maxi;

    while (!minHeap.empty())
    {
        node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        // compare the range
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // list khtm to nahi hogai??
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, arr[temp->row][temp->col + 1]);
            minHeap.push(new node(arr[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            // next elem does not exist
            break;
        }
    }

    return (end - start + 1);
}

int main()
{




    return 0;
}