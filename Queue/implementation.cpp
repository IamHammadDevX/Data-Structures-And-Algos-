#include<iostream>
#include<queue>
using namespace std;

// implementing QUEUE

class Que {

    // data members
    int* arr;
    int size;
    int rear;
    int front;

public:
    // constructor
    Que() {
        size = 10001;
        arr = new int[size];
        rear = 0;
        front = 0;
    }

    // push in QUEUE
    void enqueue(int data) {
        // check whether full??
        if (rear == size && front == 0)
        {
            cout << " Queue is full! " << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    // pop in queue
    int deQueue() {
        // check whether 1 elem is present or not??
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    // front top()
    int Qfront() {
        // empty??
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    // empty()
    bool isEmpty() {
        // empty??
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};


int main()
{

    // creation or implementation of QUEUE
    Que q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front elem of queue: " << q.Qfront() << endl;
    q.deQueue();
    cout << "Front elem of queue: " << q.Qfront() << endl;

    return 0;
}