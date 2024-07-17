#include<iostream>
using namespace std;

int main() {
    cout << "C++ DSA Series" << endl;
    int a = 123;
    cout << a << endl;
    char ch = '&';
    cout << ch << endl;
    bool isTrue = true;
    cout << isTrue << endl;
    float f = 1.23F;
    cout << f << endl;
    double d = 1.445332;
    cout << d << endl;

    // Sizeof()
    int size = sizeof(f);
    cout << "Size of int is: " << size << " byte" << endl;
    // Type Casting
    int c = 'c';
    cout << c << endl;
    char c1 = 99;
    cout << c1 << endl;
    int a1 = 5;
    int b1 = 6;
    bool o = (a1 <= b1);
    cout << o << endl;
    float f1 = 5 / 2.9;
    cout << f1 << endl;
    int h = 'H';
    cout << h << endl;
    int dec = 10;
    cout << (float)dec << endl;
}