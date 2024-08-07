#include<iostream>
using namespace std;


// Recursive Function
void selectionSort(int* arr, int size) {

    // base case
    if (size == 0 || size == 1)
        return;


    int minIdx = 0;
    for (int i = minIdx + 1; i < size; i++)
    {
        if (arr[i] < arr[minIdx])
        {
            minIdx = i;
        }
    }
    swap(arr[minIdx], arr[0]);


    selectionSort(arr + 1, size - 1);


}


int main() {

    int arr[5] = { 2,5,1,6,3 };
    int size = 5;
    cout << "Original Array => ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    selectionSort(arr, size);
    cout << "Sorted Array => ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}