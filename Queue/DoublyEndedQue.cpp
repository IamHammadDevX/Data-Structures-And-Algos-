#include<iostream>
using namespace std;

// circular queue
class deQueue {

    // data members
    int* arr;
    int size;
    int front;
    int rear;


public:
    // constructor to initialize
    deQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // push_front()
    bool pushFront(int data) {

        // check full??
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;


        return true;
    }

    // push_back()
    bool pushRear(int data) {
        // check full??
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;


        return true;
    }

    // pop_front()
    int popFront() {
        // empty??
        if (isEmpty())
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

    // pop_rear()
    int popRear() {
        // empty??
        if (isEmpty())
        {
            return -1;
        }

        // for single elem
        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            // to maintain cyclic nature
            rear = size - 1;
        }
        else
        {
            // normal flow
            rear--;
        }
        return ans;
    }

    // getFront()
    int getFront() {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    // getRear()
    int getRear() {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    // isEmpty()
    bool isEmpty() {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // isFull()
    bool isFull() {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
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



    return 0;
}