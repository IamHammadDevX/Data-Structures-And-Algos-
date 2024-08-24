#include<iostream>
#include<stack>
#include<queue>
using namespace std;


// Reverse Queue
queue<int> rev(queue<int> q) {
    // 1 - queue se elem nikalo stack me daalo
    stack<int> s;

    while (!q.empty())
    {
        int elem = q.front();
        q.pop();
        s.push(elem);
    }

    // 2 - stack se elem nikalo queue me daalo
    while (!s.empty())
    {
        int elem = s.top();
        s.pop();
        q.push(elem);
    }

    return q;
}

int main()
{

    queue<int> que;
    que.push(4);
    que.push(3);
    que.push(1);
    que.push(10);
    que.push(2);
    que.push(6);

    cout << "Front Elem of Queue: " << que.front() << endl;
    cout << "back Elem of Queue: " << que.back() << endl;

    queue<int> reverse = rev(que);

    cout << "After reversing the elems of Que: ";
    while (!reverse.empty())
    {
        cout << reverse.front() << " ";
        reverse.pop();
    }
    cout << endl;


    return 0;
}