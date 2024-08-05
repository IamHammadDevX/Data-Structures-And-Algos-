#include<iostream>
using namespace std;


void print(int* ptr) {
    cout << "Inside Print Func" << endl;
    cout << "Value of pointer: " << *ptr << endl;
    cout << "Address of pointer: " << ptr << endl;
}

void update(int* ptr) {
    *ptr = *ptr + 1;
    cout << " => Inside func " << *ptr << endl;
}

int getSum(int* arr, int n) {
    cout << endl << "Size of array: " << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main() {

    int val = 5;
    cout << "Address of var: " << &val << endl;
    int* ptr = &val;

    // print(ptr);
    cout << " Before => " << *ptr << endl;
    update(ptr);
    cout << " After => " << *ptr << endl;


    int arr[6] = { 1,2,3,4,5,6 };

    cout << "Sum is: " << getSum(arr + 3, 3) << endl;


    return 0;
}