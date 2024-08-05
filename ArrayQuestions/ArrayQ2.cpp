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

// Find Duplicates
int duplicates(int arr[], int size) {
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < size; i++)
    {
        ans = ans ^ i;
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

    int dup = duplicates(arr, size);
    cout << "Duplicate element is: " << dup << endl;

    return 0;
}