#include<iostream>
using namespace std;

// Polymorphism
// i => Run Time Polymorphism
class Animal {
public:
    // Method overRiding
    void speak() {
        cout << "Speaking..." << endl;
    }
};
class Dog : public Animal {

    // function overRided
public:
    void speak() {
        cout << "Barking..." << endl;
    }

};


int main() {

    Dog dg;
    dg.speak();


    return 0;
}
