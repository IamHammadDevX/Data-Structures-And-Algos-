#include<iostream>
using namespace std;

// Polymorphism
// i => Compile Time Polymorphism
class A {
public:
    // function overloading
    void sayHello() {
        cout << "Hello Roy!" << endl;
    }
    void sayHello(string name) {
        cout << "Hello " << name << endl;
    }
    int sayHello(string name, int n) {
        cout << "Hello " << name << endl;
        return n;
    }
};


int main() {

    A a;
    a.sayHello();
    a.sayHello("Jay!");
    a.sayHello("USOS", 3);


    return 0;
}
