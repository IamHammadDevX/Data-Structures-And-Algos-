#include<iostream>
using namespace std;

// make a heap class
class heap {
public:
    int arr[100];

    int size;

    // Constructor to intialize the values
    heap() {
        // put -1 or X NULL at the zeroth idx
        // arr[100] = -1,1,2,3,4,5
        arr[0] = -1;
        size = 0;
    }

    // insert
    void insert(int val) {
        size = size + 1;
        int idx = size;
        arr[idx] = val;

        // check right position of the elem
        while (idx > 1)
        {
            // check the parent 
            // parent must be greater than child in MAX HEAP
            // parent = 5/2 = 2(parent);
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

    // Delete from heap
    void deleteFromHeap() {
        // check whether heap is empty or not
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        // Step1: copy last node at 1st location
        arr[1] = arr[size];

        // Step2: Remove the last node
        size--;

        // Step3: propagate the root elem to its right position
        int i = 1;
        while (i < size)
        {
            // root ka left = 2*1 = 2
            int leftIdx = 2 * i;
            // root ka right = 2*1+1 = 3
            int rightIdx = 2 * i + 1;

            if (leftIdx < size && arr[i] < arr[leftIdx])
            {
                swap(arr[i], arr[leftIdx]);
                i = leftIdx;
            }
            else if (rightIdx < size && arr[i] < arr[rightIdx])
            {
                swap(arr[i], arr[rightIdx]);
                i = rightIdx;
            }
            else
            {
                return;
            }
        }
    }

    // print kerna hai
    void print() {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

// Heapify Algo: it put the node to its right position
void heapifyAlgo(int arr[], int size, int idx) {

    int largest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != idx)
    {
        swap(arr[largest], arr[idx]);
        // recursive call for right and vice versa other nodes
        heapifyAlgo(arr, size, largest);
    }
}

int main()
{

    heap maxHeap;
    cout << endl << " ^_^ Insertion into heap ^_^ " << endl << endl;
    maxHeap.insert(65);
    maxHeap.insert(14);
    maxHeap.insert(89);
    maxHeap.insert(85);
    maxHeap.insert(53);
    maxHeap.insert(67);
    cout << "Printing the max Heap: ";
    maxHeap.print();
    cout << endl << " ^_^ Deleting from heap ^_^ " << endl << endl;
    maxHeap.deleteFromHeap();
    cout << "Printing the max Heap After Deletion: ";
    maxHeap.print();

    cout << endl << " (-_-) Heapify Algorithm (-_-) " << endl << endl;
    int arr[6] = { -1, 54, 53, 55, 52, 50 };
    int n = 5;
    cout << "Printing the array Before Heapify: ";
    for (int i = 0; i < n + 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // no need to process the leaf node bcz they are in itself a heap
    // thats why we start from n/2
    for (int i = n / 2; i > 0; i--)
    {
        heapifyAlgo(arr, n, i);
    }
    // print
    cout << "Printing the array After Heapify: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;



    return 0;
}
