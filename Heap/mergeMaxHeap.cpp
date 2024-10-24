#include<iostream>
#include<vector>
using namespace std;

class heap {
public:
    int arr[100];

    int size;

    // Constructor to intialize the values
    heap() {
        // put -1 or X NULL at the zeroth idx
        // arr[100] = -1,1,2,3,4,5...so on
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
    // Heapify Algo: it put the node to its right position
    void heapifyAlgo(vector<int>& arr, int size, int idx) {
        // 1-based indexing
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

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

    // mergeTwo MaxHeaps
    vector<int> mergeTwoHeaps(vector<int>& a, vector<int>& b, int n, int m) {

        // step1: merge both arrays into one
        vector<int> c;
        for (auto i : a)
        {
            c.push_back(i);
        }
        for (auto i : b)
            c.push_back(i);

        // build heap from merged array algo
        int size = c.size();
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapifyAlgo(c, size, i);
        }

        return c;
    }

};




int main()
{




    return 0;
}