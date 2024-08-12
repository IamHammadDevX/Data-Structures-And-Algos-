#include<iostream>
using namespace std;

// Multiple Inheritence
class A {
public:
    void func() {
        cout << "I am A!" << endl;
    }
};
class B {
public:
    void func() {
        cout << "I am B!" << endl;
    }

};

class C : public A, public B {
public:

};


int main() {

    C c;
    c.A::func();
    c.B::func();


    return 0;
}
