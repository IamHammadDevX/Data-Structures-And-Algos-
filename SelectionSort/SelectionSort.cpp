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

// Selection Sort Logic 
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }

        }
        swap(arr[minIdx], arr[i]);

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
    selectionSort(arr, size);
    cout << "Sorted Array: ";
    printArray(arr, size);
    return 0;
}