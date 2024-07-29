#include<iostream>
using namespace std;

// Sorted Rotated
bool sortedRotated(int arr[], int size) {
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }

    }
    if (arr[size - 1] > arr[0])
        count++;

    return count <= 1;
}

int main() {

    // int arr[5] = { 3,4,5,1,2 };
    // int arr[5] = { 1,2,3,4,5 };
    // int arr[5] = { 3,5,7,1,6 };
    int arr[3] = { 1,1,1 };
    bool ans = sortedRotated(arr, 3);
    if (ans)
    {
        cout << "Array is Sorted & Rotated!" << endl;
    }
    else {
        cout << " !(Sorted & Rotated!) " << endl;
    }


    return 0;
}