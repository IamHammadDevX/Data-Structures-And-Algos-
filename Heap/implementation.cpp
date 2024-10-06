#include<iostream>
using namespace std;

// make a class
class heap {

public:
    int arr[100];
    int size;

    // constructor
    heap() {
        // put -1 at the 0th location
        arr[0] = -1;
        size = 0;
    }

    // insertion
    void insertAtEnd(int val) {

        // insert at end mean size = size+1
        size = size + 1;
        int idx = size;
        arr[idx] = val;

        while (idx > 1)
        {
            // i/2 = parent => 5/2 = 2 parent Location
            int parent = idx / 2;

            if (arr[parent] < arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else
            {
                return;
            }
        }
    }

    // print
    void print() {

        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

    }


};


int main()
{

    heap h;
    h.insertAtEnd(50);
    h.insertAtEnd(55);
    h.insertAtEnd(53);
    h.insertAtEnd(52);
    h.insertAtEnd(54);
    cout << "Printing the Heap: ";
    h.print();


    return 0;
}