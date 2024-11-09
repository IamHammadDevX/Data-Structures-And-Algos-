#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Median in a stream
// signum func
int signum(int a, int b) {
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
        return 1;
    else
        return -1;
}

// find Median
void callMedian(int elem, priority_queue<int>& maxi, priority_queue<int, vector<int>, greater<int> >& mini, int& median) {

    switch (signum(mini.size(), maxi.size()))
    {
    case 0:
        if (elem > median) {
            mini.push(elem);
            median = mini.top();
        }
        else {
            maxi.push(elem);
            median = maxi.top();

        }
        break;

    case 1:
        if (elem > median) {
            mini.push(elem);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(elem);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    case -1:
        if (elem > median) {
            maxi.push(mini.top());
            mini.pop();
            mini.push(elem);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            maxi.push(elem);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    }

}


vector<int> findMedian(vector<int>& arr, int n) {

    vector<int> ans;
    // create min and maxheaps
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int median = 0;

    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }


    return ans;
}


int main()
{




    return 0;
}