#include<iostream>
using namespace std;

// Encapsulation -> Capsule - Information hiding
class Box {
private:
    int height;
    int length;
    int breadth;

    // getters
    int getHeight() {
        return this->height;
    }
    int getLength() {
        return this->length;
    }
    int getBreadth() {
        return this->breadth;
    }
    // setters
    void setHeight(int height) {
        this->height = height;
    }
    void setLength(int length) {
        this->length = length;
    }
    void setBreadth(int breadth) {
        this->breadth = breadth;
    }

};




int main() {

    Box b1;
    cout << "Everything is working nyc...." << endl;



    return 0;
}
