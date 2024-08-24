#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;


// first -ve integer in k size window

vector<long long> printFirstNegInt(long long int arr[], long long int N, long long int K) {

    // N = array size
    // K = current window size
    deque<long long int> dq;
    vector<long long> ans;

    // 1 - process first window of k size
    for (int i = 0; i < K; i++)
    {
        if (arr[i] < 0)
        {
            // save the idx of current neg elem
            dq.push_back(i);
        }

    }

    // 2 - answer nikale for k size window
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    // save zero 0 if no elem is present at dqueue
    else
    {
        ans.push_back(0);
    }

    // 3 - process for remaining windows
    for (int i = K; i < N; i++)
    {
        // pichle window ka front elem remove kerna hai
        // remove logic
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        // addition of new elem of next window
        if (arr[i] < 0)
        {
            // save the idx of current neg elem
            dq.push_back(i);
        }

        // 2 - answer nikale for k size window
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        // save zero 0 if no elem is present at dqueue
        else
        {
            ans.push_back(0);
        }

    }

    return ans;
}



int main()
{




    return 0;
}