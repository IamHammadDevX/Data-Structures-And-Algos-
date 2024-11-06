#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// kth largest sum of subarray
int kthLargestSumSubArray(vector<int>& arr, int k) {

    // min-heap
    priority_queue<int, vector<int>, greater<int> > mini;

    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (mini.size() < k)
            {
                // insert into heap
                mini.push(sum);
            }
            else
            {
                if (sum > mini.top())
                {
                    // top pop and then push
                    mini.pop();
                    mini.push(sum);
                }

            }

        }
    }

    return mini.top();
}


int main()
{

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(4);
    arr.push_back(3);

    int kthLarg = kthLargestSumSubArray(arr, 3);
    cout << "Kth Largest elem: " << kthLarg << endl;

    return 0;
}