#include<iostream>
using namespace std;

// Polymorphism
// i => Compile Time Polymorphism
class A {

public:
    int a;
    int b;

    int add() {
        return a + b;
    }
    // Operator Overloading +
    void operator+(A& obj) {
        cout << "Yahan + ka operator overload horaha hai." << endl;
        int val1 = this->a;
        int val2 = obj.a;
        cout << "Output: " << val1 - val2 << endl;
    }
    // Operator Overloading ()
    void operator() () {
        cout << "Yahan () ka operator overload horaha hai." << endl;
        cout << "it's bracket " << this->a << endl;
    }
    // Operator Overloading =
    void operator% (A& obj) {
        cout << "Yahan % ka operator overload horaha hai." << endl;
        int val1 = this->a;
        int val2 = obj.a;
        cout << "Output: " << val1 * val2 << endl;
    }

};


int main() {

    A obj1, obj2;
    // obj1.a = 10;
    // obj1.b = 20;
    // cout << "Sum is: " << obj1.add() << endl;
    obj1.a = 39;
    obj2.a = 24;
    obj1 + obj2;
    obj1();
    obj1% obj2;


    return 0;
}
