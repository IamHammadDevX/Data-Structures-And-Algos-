#include<iostream>
using namespace std;


// Recursive Function
void bubbleSort(int* arr, int size) {

    // base case
    if (size == 0 || size == 1)

        return;



    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }

    }

    // Recursive call
    bubbleSort(arr, size - 1);



}


int main() {


    int arr[5] = { 2,5,1,6,3 };
    int size = 5;
    cout << "Original Array => ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    bubbleSort(arr, size);
    cout << "Sorted Array => ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}