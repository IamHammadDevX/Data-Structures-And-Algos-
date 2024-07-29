#include<iostream>
using namespace std;


// Rotate by kth value
void rotateByKthvalue(int arr[], int size, int k) {

    int temparr[size];
    for (int i = 0; i < size; i++)
    {
        temparr[(i + k) % size] = arr[i];
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temparr[i];
    }
}


// Print Array 3
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {

    int arr[5] = { 11,12,13,14,15 };
    int k;
    cout << "Enter the kth index: ";
    cin >> k;
    cout << "Original Array: " << endl;
    printArray(arr, 5);
    rotateByKthvalue(arr, 5, k);
    cout << "Rotated Array: " << endl;
    printArray(arr, 5);

    return 0;
}