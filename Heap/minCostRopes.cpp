#include<bits/stdc++.h>
using namespace std;

// Minimum cost of ropes???
long long minCost(long long arr[], long long n) {

    // create a min heap
    priority_queue<long long, vector<long long>, greater<long long> > pq;

    // push all elems in min heap
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long cost = 0;

    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}


int main()
{

    long long arr[4] = { 4,3,2,6 };
    long long n = 4;
    long long res = minCost(arr, n);
    cout << "Sum of Minimum cost of ropes: " << res << endl;


    return 0;
}