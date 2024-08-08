#include<iostream>
using namespace std;

// Partition algo
int partition(int* arr, int s, int e) {

    int pivot = arr[s];

    // place pivot at its right position
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }

    }

    int pivotIdx = s + cnt;
    swap(arr[pivotIdx], arr[s]);

    // pivotIdx > leftPart && pivotIdx < rightPart
    int i = s, j = e;
    while (i < pivotIdx && j > pivotIdx)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIdx && j > pivotIdx)
        {
            swap(arr[i++], arr[j--]);
        }


    }


    return pivotIdx;
}



// Quick Sort
void quickSort(int* arr, int s, int e) {

    // base case
    if (s >= e)
    {
        return;
    }

    // Recursive call
    int p = partition(arr, s, e);

    // Left part
    quickSort(arr, s, p - 1);
    // right wala part
    quickSort(arr, p + 1, e);



}


int main() {

    int arr[6] = { 6,9,3,57,2,7 };
    int size = 6;
    cout << "Original Array => ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    quickSort(arr, 0, size - 1);
    cout << "Quick Algorithm Sorted Array => ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;




    return 0;
}