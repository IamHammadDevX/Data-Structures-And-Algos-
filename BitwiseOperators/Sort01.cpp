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

// void SortOne(int arr[], int size) {
//     int left = 0, right = size - 1;
//     while (left < right)
//     {
//         while (arr[left] == 0 && left < right)
//         {
//             left++;
//         }
//         while (arr[right] == 1 && left < right)
//         {
//             right--;
//         }

//         if (left < right)
//         {
//             swap(arr[left], arr[right]);
//             left++;
//             right--;
//         }



//     }

// }

// Sort 0, 1, 2
void SortThreeVals(int arr[], int size) {
    int start = 0, end = size - 1, middle = (start + end) / 2;
    while (middle <= end) {
        if (arr[middle] == 0) {
            swap(arr[start], arr[middle]);
            start++;
            middle++;
        }
        else if (arr[middle] == 1) {
            middle++;
        }
        else { // arr[middle] == 2
            swap(arr[middle], arr[end]);
            end--;
        }
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
    // SortOne(arr, size);
    SortThreeVals(arr, size);
    cout << "Sorted Array is: ";
    printArray(arr, size);
    return 0;
}