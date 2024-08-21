#include<iostream>
#include<stack>
#include<vector>
using namespace std;


// next smaller element
vector<int> nextSmallerElement(vector<int>& arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int cur = arr[i];
        while (s.top() >= cur)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(cur);
    }

    return ans;
}


int main()
{

    vector<int> arr;
    int n = 4;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    vector<int> nxtsmall = nextSmallerElement(arr, n);
    for (int i : nxtsmall) {
        cout << i << " ";
    }cout << endl;

    return 0;
}