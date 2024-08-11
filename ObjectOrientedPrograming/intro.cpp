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
    Hero(int health, char level) {
        cout << "Parametrized constructor called!" << endl;
        cout << "Address of this -> " << this << endl;
        this->health = health;
        this->level = level;
    }
    Hero(Hero& copy) {
        cout << "Copy Constructor called!" << endl;
        this->health = copy.health;
        this->level = copy.level;
    }


    void print() {
        cout << "Health is => " << this->health << endl;
        cout << "Level is => " << this->level << endl;
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
    Hero h1(10, 'C');
    cout << "Address of h1 object -> " << &h1 << endl;
    h1.heroName = "Vicky";
    h1.setHealth(90);
    h1.setLevel('D');
    cout << "Name of hero is => " << h1.heroName << endl;
    cout << "Health is => " << h1.getHealth() << endl;
    cout << "Level is => " << h1.getLevel() << endl << endl;

    Hero* h = new Hero(20, 'B');
    cout << "Address of hero object -> " << &h << endl;
    h->heroName = "Virat";
    h->setHealth(101);
    h->setLevel('A');
    cout << "Name of hero is => " << (*h).heroName << endl;
    cout << "Health is => " << h->getHealth() << endl;
    cout << "Level is => " << (*h).getLevel() << endl << endl;


    // Copy Constructor
    Hero A(30, 'E');
    cout << "Address of A object => " << &A << endl;
    A.heroName = "Anushka Sharma";
    cout << "Name of hero is => " << A.heroName << endl;
    // cout << "Health is => " << A.getHealth() << endl;
    // cout << "Level is => " << A.getLevel() << endl << endl;
    A.print();

    Hero wife(A);
    cout << "Address of A object => " << &wife << endl;
    wife.heroName = "Anushka";
    cout << "Name of hero is => " << wife.heroName << endl;
    // cout << "Health is => " << wife.getHealth() << endl;
    // cout << "Level is => " << wife.getLevel() << endl << endl;
    wife.print();

    // h1.print();

    // char         1 byte 
// short int    2 bytes 
// int          4 bytes 
// double       8 bytes 
    cout << "Size of class => " << sizeof(h1) << endl;

    return 0;
}