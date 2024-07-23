#include<iostream>
using namespace std;


void printArray(int arr[], int size) {
    cout << "Printing the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << "Printing Done!";

}

int main() {
    int size = 10;
    int arr[size] = { 1,2,3,4,5,6,7 };
    printArray(arr, size);





    return 0;
}