#include<iostream>
using namespace std;

void update(int** p) {
    // Anything change  - NO
    // p = p + 1;
    // // Anything change - YES
    // *p = *p + 1;
    // // Anything change - YES
    **p = **p + 1;


}



int main() {

    int i = 5;
    int* p = &i;
    int** p2 = &p;

    cout << "Address of i => " << &i << endl;
    cout << "Address of i in p => " << p << endl;
    cout << "Address of p => " << &p << endl;
    cout << "Address of p in p2 => " << p2 << endl;
    cout << "Address of p2 => " << &p2 << endl << endl;
    // printing value i
    cout << "Printing value i => " << endl;
    cout << "1st => " << i << endl;
    cout << "2nd => " << *p << endl;
    cout << "3rd => " << **p2 << endl << endl;
    // printing value p
    cout << "Printing value p => " << endl;
    cout << "1st => " << &i << endl;
    cout << "2nd => " << p << endl;
    cout << "3rd => " << *p2 << endl << endl;
    // printing value p2
    cout << "Printing value p2 => " << endl;
    cout << "2nd => " << &p << endl;
    cout << "3rd => " << p2 << endl;
    cout << endl;

    cout << "Analysing dbl ptr in func => " << endl;
    cout << " => Before => " << i << endl;
    cout << " => Before => " << p << endl;
    cout << " => Before => " << p2 << endl;
    update(p2);
    cout << " => After => " << i << endl;
    cout << " => After => " << p << endl;
    cout << " => After => " << p2 << endl;

    return 0;
}