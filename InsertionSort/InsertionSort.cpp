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

// Insertion Sort Logic 
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1; // i=1 => j=1-1=0, So 0th idx kept for comparing 
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // 1 place shift
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }

        }
        arr[j + 1] = temp;

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

    cout << "Original Array is: ";
    printArray(arr, size);
    insertionSort(arr, size);
    cout << "Sorted Array: ";
    printArray(arr, size);
    return 0;
}