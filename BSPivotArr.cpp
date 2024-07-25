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

    cout << "Original Array is: ";
    printArray(arr, size);
    int pivotIndex = pivot(arr, size);
    cout << "The pivot element is at index: " << pivotIndex << " and its value is: " << arr[pivotIndex] << endl;


    return 0;
}