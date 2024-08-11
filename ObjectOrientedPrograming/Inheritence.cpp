#include<iostream>
using namespace std;

// Inheritence
class Human {

    // public:
    //     int height;
    //     int age;
    //     int weight;

protected:
    int height;
    int age;
    int weight;

    // private:
    //     int height;
    //     int age;
    //     int weight;



};

// derived class
class Male :public Human {

public:
    string name;
    string color;

    void sleep() {

        cout << "Name: " << this->name << endl;
        cout << "color: " << this->color << endl;
        cout << "Age: " << this->age << endl;
        cout << "Weight: " << this->weight << endl;
        cout << "Height: " << this->height << endl;
        cout << "Male is sleeping...." << endl;
    }


};



int main() {

    Male m1;
    // cout << m1.height << endl;
    // cout << m1.weight << endl;
    // cout << m1.age << endl;
    cout << m1.color << endl;
    cout << m1.name << endl;
    m1.sleep();


    return 0;
}
