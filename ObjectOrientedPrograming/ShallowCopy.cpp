#include<iostream>
#include <cstring>
using namespace std;

// class
class Hero {

    // data members
private:
    int health;
public:
    char* name;
    char level;

    // default Cons
    Hero() {
        cout << "Default Constructor called!" << endl;
        name = new char[100];
    }
    // params cons
    Hero(int health, char level) {
        this->health = health;
        this->level = level;
    }


    void print() {
        cout << endl;
        cout << "[ Name: " << this->name << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Level: " << this->level << " ]";
        cout << endl << endl;
    }


    // getter / setter functions
    int getHealth() {
        return health;
    }
    char getLevel() {
        return level;
    }
    // set health and level
    void setHealth(int h) {
        this->health = h;
    }
    void setLevel(char l) {
        this->level = l;
    }
    void setName(char name[]) {
        strcpy(this->name, name);
    }


};


// Box Class implementation
// class Box {
//     // data members
// private:
//     int length;
//     int breadth;
//     int height;

// public:
//     // member functions
//     void setValues(int length, int breadth, int height) {
//         this->length = length;
//         this->breadth = breadth;
//         this->height = height;
//     }
//     // Show data
//     void printData() {
//         cout << endl;
//         cout << "[ length: " << this->length << ", ";
//         cout << "breadth: " << this->breadth << ", ";
//         cout << "height: " << this->height << " ]";
//         cout << endl << endl;
//     }
// 
// 
// };

int main() {

    Hero hero1;
    hero1.setLevel('B');
    hero1.setHealth(70);
    char name[6] = "Virat";
    hero1.setName(name);
    hero1.print();

    // using default copy constructor
    Hero hero2(hero1);
    hero2.print();

    // modifying the values;
    hero1.name[0] = 'K';
    hero1.print();

    hero2.print();



    // Box class
    // Box b1;
    // cout << "Address Box1: " << &b1 << endl;
    // b1.setValues(5, 10, 15);
    // b1.printData();

    // Box b2 = b1;
    // cout << "Address Box2: " << &b2 << endl;
    // b2.printData();

    // Box b3 = b2;
    // cout << "Address Box3: " << &b3 << endl;
    // b3.printData();

    return 0;
}