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

// Swap Alternate
// void swapAlternate(int arr[], int size) {
//     int tempArr;
//     for (int i = 0; i < size; i += 2)
//     {
//         if (i + 1 < size)
//         {
//             tempArr = arr[i + 1]; //temp hold i+1 elem for some time until swapping done
//             arr[i + 1] = arr[i];
//             arr[i] = tempArr;
//         }

//     }

// }

int uniqueElem(int arr[], int size) {
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;

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
    // cout << "Alternate Swapped Array is: ";
    // swapAlternate(arr, size);
    // printArray(arr, size);
    int uniq = uniqueElem(arr, size);
    cout << "Unique element in the array is: " << uniq << endl;


    return 0;
}