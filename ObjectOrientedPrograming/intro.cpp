#include<iostream>
using namespace std;

// class
class Hero {

    // data members
public:
    string heroName;
private:
    int health;
    char level;

public:
    // constructor
    Hero() {
        cout << "Constructor Called!" << endl;
    }
    // Parametrized constructor
    Hero(int health) {
        cout << "Address of this -> " << this << endl;
        this->health = health;
    }


    void print() {
        cout << level << endl;
    }

    int getHealth() {
        return health;
    }
    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }
    void setLevel(char l) {
        level = l;
    }


};


int main() {

    // creation of object
    Hero h1(10);
    cout << "Address of h1 object -> " << &h1 << endl;
    h1.heroName = "Vicky";
    h1.setHealth(90);
    h1.setLevel('D');
    cout << "Name of hero is => " << h1.heroName << endl;
    cout << "Health is => " << h1.getHealth() << endl;
    cout << "Level is => " << h1.getLevel() << endl;

    Hero* h = new Hero(20);
    cout << "Address of hero object -> " << &h << endl;
    h->heroName = "Virat";
    h->setHealth(101);
    h->setLevel('A');
    cout << "Name of hero is => " << (*h).heroName << endl;
    cout << "Health is => " << h->getHealth() << endl;
    cout << "Level is => " << (*h).getLevel() << endl;



    // h1.print();

    // char         1 byte 
// short int    2 bytes 
// int          4 bytes 
// double       8 bytes 
    cout << "Size of class => " << sizeof(h1) << endl;

    return 0;
}