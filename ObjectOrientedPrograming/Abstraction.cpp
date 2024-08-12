#include<iostream>
using namespace std;

// i => Abstraction
class A {

private:
    int a = 10;
    int b = 20;
public:
    int add() {
        return a + b;
    }

};


int main() {

    A obj1;
    cout << "Sum is: " << obj1.add() << endl;


    return 0;
}
