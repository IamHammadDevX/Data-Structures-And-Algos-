#include<iostream>
using namespace std;

// Multiple Inheritence
class A {
public:
    void func1() {
        cout << "Inside A class func 1!" << endl;
    }
};
class B : public A {
public:
    void func2() {
        cout << "Inside B class func 2!" << endl;
    }

};
class D {
public:
    void func4() {
        cout << "Inside D class func 4!" << endl;
    }
};
class C : public A, public D {
public:
    void func3() {
        cout << "Inside C class func 3!" << endl;
    }

};


int main() {

    A a;
    a.func1();
    B b;
    b.func1();
    b.func2();
    C c;
    c.func1();
    // c.func2();   ERROR
    c.func3();
    c.func4();


    return 0;
}
