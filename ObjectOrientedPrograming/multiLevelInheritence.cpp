#include<iostream>
using namespace std;

// Multilevel Inheritence
class Animal {
public:
    void speak()
    {
        cout << "speak..." << endl;
    }

};
class Dog :public Animal {
public:
    void bark() {
        cout << "Dog is barking... " << endl;
    }
};
class Lion : public Dog {
public:
    void roar() {
        cout << "Lios is roaring...." << endl;
    }
};



int main() {

    Animal an;
    an.speak();
    Dog dg;
    dg.bark();
    dg.speak();
    Lion ln;
    ln.roar();
    ln.speak();
    ln.bark();


    return 0;
}
