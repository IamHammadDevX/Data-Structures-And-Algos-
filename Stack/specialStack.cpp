#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

// Problem is designe a special stack
class specialStack {
    // data member define
    stack<int> s;
    int mini = INT_MAX;

    // public functions
public:
    // push()
    void push(int data) {
        // first elem
        if (s.empty())
        {

            s.push(data);
            mini = data;

        }
        else
        {

            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    // pop()
    int pop() {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        s.pop();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    // top()
    int top() {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    // empty()
    bool isEmpty() {
        return s.empty();
    }

    // getMin()
    int getMin() {
        if (s.empty())
        {
            return -1;
        }

        return mini;
    }


};


int main()
{

    specialStack spSt;
    spSt.push(5);
    spSt.pop();
    spSt.push(3);
    spSt.pop();
    spSt.push(8);
    // spSt.pop();
    spSt.push(2);
    // spSt.pop();
    spSt.push(4);
    // spSt.pop();


    int mini = spSt.getMin();
    cout << "Minimum value in special stack: " << mini << endl;
    int top = spSt.top();
    cout << "top value in special stack: " << mini << endl;

    return 0;
}