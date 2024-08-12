#include<iostream>
using namespace std;

// i => Interfaces
class Animal {

public:
    // pure virtual func
    virtual void sound() = 0;
    // Normal func
    void sleep() {
        cout << "Sleeping..." << endl;
    }

};
class Dog : public Animal {
public: void sound() {
    cout << "Woof..." << endl;
}
};


int main() {

    Dog d;
    d.sound();
    d.sleep();


    return 0;
}
