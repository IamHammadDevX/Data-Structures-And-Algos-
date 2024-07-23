#include<iostream>
using namespace std;


// Min Max Elem in an Array
// int getMin(int num[], int size) {
//     int min = INT_MAX;
//     for (int i = 0; i < size; i++)
//     {
//         if (num[i] < min)
//         {
//             min = num[i];
//         }

//     }

//     return min;
// }

// int getMax(int num[], int size) {
//     int max = INT_MIN;
//     for (int i = 0; i < size; i++)
//     {
//         if (num[i] > max)
//         {
//             max = num[i];
//         }

//     }
//     return max;
// }


// Sum of array elems
// int sumOfArray(int arr[], int size) {
//     int sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum = sum + arr[i];
//     }


//     return sum;
// }



// Linear Search
// bool Search(int arr[], int size, int key)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (key == arr[i])
//         {
//             return 1;
//         }

//     }


//     return 0;
// }


// Reverse the array
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {


    int size;
    cout << "Enter the Size of an array: ";
    cin >> size;
    int num[100];
    cout << "Input the array Elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " index value: ";
        cin >> num[i];
    }
    // cout << "Maximum element is: " << getMax(num, size) << endl;
    // cout << "Minimum element is: " << getMin(num, size) << endl;

    // cout << "Sum of array elements is: " << sumOfArray(num, size);

    // int key;
    // cout << "Enter the key to search: ";
    // cin >> key;
    // bool res = Search(num, size, key);
    // if (res)
    // {
    //     cout << "Key is Present!";
    // }
    // else
    // {
    //     cout << "Key is absent!";
    // }


    cout << "Original Array: ";
    printArray(num, size);
    reverseArray(num, size);
    cout << "Reversed Array: ";
    printArray(num, size);

    return 0;
}