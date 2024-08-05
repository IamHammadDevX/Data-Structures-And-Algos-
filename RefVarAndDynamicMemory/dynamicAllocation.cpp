#include<iostream>
using namespace std;


int getSum(int* arr, int n) {

    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += *(arr + j);
    }




    return sum;
}


int main() {

    int n;
    cout << "Enter the array size => ";
    cin >> n;

    // dynamic array creation
    int* arr = new int[n];

    // taking i/p
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);
    cout << "Answer is => " << ans << endl;

    return 0;
}