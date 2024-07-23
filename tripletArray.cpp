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

void checkTriplet(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {

        cout << " Value of i: " << arr[i];
        for (int j = i + 1; j < size; j++)
        {

            cout << " Value of j: " << arr[j];
            for (int k = j + 1; k < size; k++)
            {
                cout << " Value of k: " << arr[k] << endl;
            }

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
    checkTriplet(arr, size);

    return 0;
}