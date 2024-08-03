#include<iostream>
using namespace std;


int main() {

    int num = 5;
    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    int* ptr = &num;
    cout << "Value of ptr: " << *ptr << endl;
    cout << "Address of ptr: " << ptr << endl;
    double d = 4.5;
    double* dptr = &d;
    cout << "Value of Dptr: " << *dptr << endl;
    cout << "Address of Dptr: " << dptr << endl;
    cout << "Size of integer or double is: " << sizeof(num) << " and " << sizeof(d) << endl;
    cout << "Size of Pointer to integer or double is: " << sizeof(ptr) << " and " << sizeof(dptr) << endl;
    int* q = ptr;
    cout << q << " - " << ptr << endl;
    cout << *q << " - " << *ptr << endl;
    int i = 7;
    int* iPtr = &i;
    cout << "Before Inc : " << *iPtr << endl;
    cout << "Before Inc : " << iPtr << endl;
    (*iPtr)++;
    cout << "After Inc : " << *iPtr << endl;
    cout << "After Inc : " << iPtr << endl;
    cout << "After Inc : " << i << endl;

    int h = 3;
    int* hPtr = &h;
    *hPtr = *hPtr + 1;
    cout << "Value of int pointer: " << *hPtr << endl;
    cout << "ADDRESS of int pointer before inc: " << hPtr << endl;
    hPtr = hPtr + 1;
    cout << "ADDRESS of int pointer After inc: " << hPtr << endl;


    return 0;
}