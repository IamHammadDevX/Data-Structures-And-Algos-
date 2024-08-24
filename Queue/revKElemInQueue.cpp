#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// reverse first K elem in queue
queue<int> RevKqueElems(queue<int> q, int k) {

    // Algo
    // 1 - fetch k elems from queue and put into stack
    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        int elem = q.front();
        q.pop();
        s.push(elem);
    }

    // 2 - fetch elems from stack and put into queue
    while (!s.empty())
    {
        int elem = s.top();
        s.pop();
        q.push(elem);
    }

    // 3 - fetch n-k elems from queue and push into queue
    int backPutPart = q.size() - k;

    while (backPutPart--)
    {
        int elem = q.front();
        q.pop();
        q.push(elem);
    }

    return q;
}

int main()
{

    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);

    queue<int> reverse = RevKqueElems(que, 2);
    cout << "After reversing the kth elems of Que: ";
    while (!reverse.empty())
    {
        cout << reverse.front() << " ";
        reverse.pop();
    }
    cout << endl;




    return 0;
}