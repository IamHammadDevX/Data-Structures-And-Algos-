#include<iostream>
using namespace std;

void print(int* arr, int n) {
    cout << endl << "Size of array => " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;

}

// Recursive Function
int getSum(int* arr, int size) {
    print(arr, size);
    // base case
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }


    // Recursive relation
    int smallProb = getSum(arr + 1, size - 1);
    int bigProb = arr[0] + smallProb;
    return bigProb;
}



int main() {


    int arr[5] = { 2,4,6,9,13 };
    int size = 5;
    int ans = getSum(arr, size);
    cout << "Sum is => " << ans << endl;


    return 0;
}