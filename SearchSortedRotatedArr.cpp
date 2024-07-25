#include<iostream>
using namespace std;


// Print Array func
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}


// Pivot = lowest element index
int pivot(int arr[], int size) {
    int s = 0, e = size - 1, mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }

    return e;
}

// Binary Search
int binarySearch(int arr[], int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;

    }

    return -1;
}

// Find Target Key
int findTarget(int arr[], int size, int key) {
    int pivotIndex = pivot(arr, size);
    if (key >= arr[pivotIndex] && key <= arr[size - 1])
    {   //for second line of graph
        return binarySearch(arr, pivotIndex, size - 1, key);
    }
    else
    {
        return binarySearch(arr, 0, pivotIndex - 1, key);

    }
}

int main() {


    int size;
    cout << "Enter the array Size: ";
    cin >> size;
    int arr[100];
    cout << "Enter the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " index value: ";
        cin >> arr[i];
    }
    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    cout << "Original Array is: ";
    printArray(arr, size);

    int target = findTarget(arr, size, key);
    cout << "Target is at index: " << target << endl;

    return 0;
}