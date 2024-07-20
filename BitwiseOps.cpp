#include<iostream>
using namespace std;

int main() {
    // Bitwise Operators
    int a = 5;
    int b = 7;
    cout << "a&b = " << (a & b) << endl;
    cout << "a|b = " << (a | b) << endl;
    cout << "~a = " << ~a << endl;
    cout << "a^b = " << (a ^ b) << endl;

    // Left & Right Shifting
    cout << (17 >> 1) << endl;
    cout << (17 >> 2) << endl;
    cout << (19 << 1) << endl;
    cout << (21 << 2) << endl;

    // Post & Pre Increament & Decrement
    int c = 1;
    int d = c++;
    // d=1, c=2
    int e = ++c;
    // e=3
    cout << d << endl;
    cout << e << endl;

    int i = 11;
    int f = ++i;
    cout << f << " " << i << endl;
    return 0;
}