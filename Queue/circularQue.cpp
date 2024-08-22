#include<iostream>
using namespace std;

// circular queue
class circularQue {

    // data members
    int* arr;
    int size;
    int front;
    int rear;


public:
    // constructor to initialize
    circularQue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // push()
    bool enqueue(int data) {
        // check whether queue is full??
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full!" << endl;
            return false;
        }
        // for first elem to push
        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        // to maintain cycle
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
            // normal flow
        {
            rear++;
        }
        arr[rear] = data;


        return true;
    }

    // pop
    int deQueue() {

        // empty??
        if (front == -1)
        {
            return -1;
        }

        // for single elem
        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            // to maintain cyclic nature
            front = 0;
        }
        else
        {
            // normal flow
            front++;
        }
        return ans;
    }

};



int main()
{

    circularQue q(6);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.deQueue();

    return 0;
}