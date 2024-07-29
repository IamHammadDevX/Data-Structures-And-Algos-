#include<iostream>
using namespace std;


//Move Zeros
void moveZeros(int arr[], int size) {
    int nonZero = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonZero]);
            nonZero++;
        }

    }

}




// Print Array 3
void printArray(int ans[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

}



int main() {

    int arr[6] = { 0,1,0,3,12,0 };
    cout << "Original Array: " << endl;
    printArray(arr, 6);
    moveZeros(arr, 6);
    cout << "Move Zero Array: " << endl;
    printArray(arr, 6);


    return 0;
}