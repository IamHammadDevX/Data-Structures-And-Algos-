#include<iostream>
using namespace std;


int main() {

    int arr[10] = { 0 };
    cout << arr << endl;
    int* ptr = &arr[0];
    cout << ptr << endl;
    char ch[6] = "abcde";
    cout << ch << endl;
    cout << &ch[0] << endl;
    char* cPtr = &ch[0];
    cout << cPtr << endl;
    cout << *cPtr << endl;




    return 0;
}