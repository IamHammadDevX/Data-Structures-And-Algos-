#include<iostream>
#include<vector>
using namespace std;


// Heapify Algo: it put the node to its right position
void heapifyAlgo(vector<int>& arr, int size, int idx) {

    int smallest = idx;
    // if 0 base indexing
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < size && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != idx)
    {
        swap(arr[smallest], arr[idx]);
        // recursive call for right and vice versa other nodes
        heapifyAlgo(arr, size, smallest);
    }
}

vector<int> buildMinHeap(vector<int>& arr) {

    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyAlgo(arr, n, i);
    }
    return arr;
}


int main()
{

    cout << endl << " (-_-) Heapify Algorithm and Building the Min Heap (-_-) " << endl << endl;

    vector<int> arr;
    arr.push_back(54);
    arr.push_back(53);
    arr.push_back(55);
    arr.push_back(52);
    arr.push_back(50);

    vector<int> result = buildMinHeap(arr);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
