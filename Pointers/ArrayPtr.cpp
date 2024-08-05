#include<iostream>
using namespace std;


int main() {

    int arr[10] = { 2,5,7 };

    // cout << "Address of base location of array: " << arr << endl;
    // cout << "Address of base location of array: " << &arr[0] << endl;
    // cout << "Value at base location of array: " << arr[0] << endl;
    // cout << "Value at base location of array: " << *arr << endl;
    // cout << "Value at base location of array: " << *arr + 1 << endl;
    // cout << "Value of array: " << *(arr + 1) << endl;
    // cout << "Value:  " << (*arr) + 1 << endl;



    // int arr1[10] = { 23,122,41,67 };
    // cout << "Value at 3rd location " << *(arr1 + 2) << endl;
    // int i = 3;
    // cout << i[arr1] << endl;

    // int temp[10] = { 1,2 };
    // cout << "Size of array: " << sizeof(temp) << endl;
    // cout << "1st: " << sizeof(*temp) << endl;
    // cout << "2nd: " << sizeof(&temp) << endl;
    // cout << "1st: " << *temp << endl;
    // cout << "2nd: " << &temp << endl;

    // int* p = temp;
    // cout << "Size of ptr: " << sizeof(p) << endl;
    // cout << "Size of base location ptr: " << sizeof(*p) << endl;
    // cout << "Size location ptr: " << sizeof(&p) << endl;

    int arr3[10];
    // arr3 = arr3 + 1;   Error
    cout << arr << endl;

    int* arr3Ptr = &arr3[0];
    arr3Ptr = arr3Ptr + 1;
    cout << arr3Ptr << endl;



    return 0;
}