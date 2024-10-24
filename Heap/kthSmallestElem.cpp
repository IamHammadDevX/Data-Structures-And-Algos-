#include<bits/stdc++.h>
using namespace std;

int kthSmallestElem(int arr[], int k, int size) {

    // step1: create a max heap for kth elems
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step2: for rest elems
    for (int i = k; i <= size - 1; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // return ans
    int ans = pq.top();
    return ans;
}


int main()
{

    int arr[5] = { 7, 10, 4, 20, 15 };
    int k = 4;
    int size = 5;
    int kThSmallestElem = kthSmallestElem(arr, k, size);
    cout << "Kth Smallest Elem: " << kThSmallestElem << endl;

    return 0;
}