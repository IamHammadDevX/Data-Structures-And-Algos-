#include<iostream>
using namespace std;


// K Queues in a single array
class kQueue {

    // data members
public:
    int n;
    int k;
    int* front;
    int* rear;
    int* arr;
    int freeSpot;
    int* next;

    // Constructors
public:
    kQueue(int n, int k) {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        // initialize front & rear array with -1
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        // put -1 in the last idx of next array
        next[n - 1] = -1;

        // initialize array
        arr = new int[n];
        freeSpot = 0;

    }

    // push operation
    void enqueue(int data, int qn) {
        // check freeSpot is present!
        if (freeSpot == -1)
        {
            cout << "No Free Spot is available" << endl;
            return;
        }
        // find first free idx
        int idx = freeSpot;

        // update freeSpot
        freeSpot = next[idx];

        // check whether first elem?
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = idx;
        }
        else
        {
            // link new elem to prev elem!
            next[rear[qn - 1]] = idx;
        }

        // update next
        next[idx] = -1;

        // update rear
        rear[qn - 1] = idx;

        // push elem!
        arr[idx] = data;
    }

    // pop()
    int deQueue(int qn) {
        // check freeSpot
        if (front[qn - 1] == -1)
        {
            cout << "Underflow!" << endl;
            return -1;
        }
        // find idx
        int idx = front[qn - 1];

        // move front to agayy
        front[qn - 1] = next[idx];

        // manage freesPOTS
        next[idx] = freeSpot;
        freeSpot = idx;

        return arr[idx];
    }

};


int main()
{

    kQueue kq(10, 3);
    kq.enqueue(10, 1);
    kq.enqueue(15, 1);
    kq.enqueue(20, 2);
    kq.enqueue(25, 1);

    cout << kq.deQueue(1) << endl;
    cout << kq.deQueue(2) << endl;
    cout << kq.deQueue(1) << endl;
    cout << kq.deQueue(1) << endl;

    cout << kq.deQueue(2) << endl;


    return 0;
}