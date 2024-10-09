#include<iostream>
#include<queue>
using namespace std;

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

// Heap Sort
void heapSort(int arr[], int n) {

    int size = n;

    while (size > 1)
    {
        // step1 = swap 1st node with last
        swap(arr[size], arr[1]);
        size--;

        // step2: put the root node at its right position
        heapifyAlgo(arr, size, 1);
    }

}

int main()
{
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

    // heap sort
    cout << endl << "^_* Heap Sort ^_*" << endl;
    heapSort(arr, n);
    // print
    cout << "Heap Sorted array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << " CPP STL Priority-Queue " << endl;
    // Max-Heap
    priority_queue<int> maxi;

    // min-heap
    priority_queue<int, vector<int>, greater<int>> mini;
    cout << "Max-Heap: " << endl;
    for (int i = 0; i <= 20; i += 2)
    {
        maxi.push(i);
    }
    cout << "Size => " << maxi.size() << endl;
    int size = maxi.size();
    for (int i = 0; i < size; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;

    cout << "Min-Heap: " << endl;

    for (int i = 0; i <= 20; i += 2)
    {
        mini.push(i);
    }
    cout << "Size => " << mini.size() << endl;
    int sizeMin = mini.size();
    for (int i = 0; i < sizeMin; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }cout << endl;


    return 0;
}
