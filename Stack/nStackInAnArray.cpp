#include<iostream>
#include<stack>
using namespace std;

// HARD QUESTION 
// N stack implementation in a single array
class NStack {

    // required vars
    int* arr;
    int* top;
    int* next;

    // s = size, n = no. of stacks & top wala array
    int n, s;
    int freeSpot;

public:
    // constructor to intialize data
    NStack(int N, int S) {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top ko initialize kerdya
        for (int i = 0; i < N; i++)
        {
            top[i] = -1;
        }

        // next ko initialize kerdya
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }

        // next k last idx me -1
        // s = 5, s-1 = 4, 0,1,2,3,4
        // last idx = -1
        next[s - 1] = -1;

        freeSpot = 0;

    }

    // pushes x into mth stack
    // x = value, m = stack
    bool push(int x, int m) {
        // check for overflow
        if (freeSpot == -1)
        {
            return false;
        }

        // 1 - index nikalo
        int idx = freeSpot;

        // 2 - update freeSpot
        freeSpot = next[idx];

        // 3 - insert elem
        arr[idx] = x;

        // 4 - update next
        next[idx] = top[m - 1];


        // 5 - update top
        top[m - 1] = idx;

        return true;

    }

    // pop top elem from mth stack
    int pop(int m) {
        // check for underflow
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int idx = top[m - 1];

        top[m - 1] = next[idx];

        next[idx] = freeSpot;

        freeSpot = idx;


        return arr[idx];
    }


};




int main()
{

    NStack n(3, 6);

    n.push(10, 1);
    n.push(20, 1);
    n.push(30, 3);

    n.pop(1);
    n.pop(2);


    return 0;
}