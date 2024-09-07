#include<iostream>
using namespace std;

struct smartPhone
{
    string name;
    int storageSpace;
    string color;
    float price;
};

// nested struct
struct person
{
    string name;
    int age;
    string gender;
    smartPhone mobile;
};


// function to print
void printSmartPhInfo(smartPhone smPh) {
    cout << "Phone Name: " << smPh.name << endl;
    cout << "Storage: " << smPh.storageSpace << " GB" << endl;
    cout << "Color: " << smPh.color << endl;
    cout << "Price: " << smPh.price << endl;
}

// person info
void personInfo(person per) {
    cout << "Name: " << per.name << endl;
    cout << "Age: " << per.age << endl;
    cout << "Gender: " << per.gender << endl;
    printSmartPhInfo(per.mobile);
}

int main()
{

    smartPhone iPh;
    iPh.name = "I-phone 12";
    iPh.storageSpace = 32;
    iPh.color = "Black";
    iPh.price = 999.99;


    smartPhone aPh;
    aPh.name = "Vivo VY100";
    aPh.storageSpace = 64;
    aPh.color = "grey";
    aPh.price = 6998.9;

    // printSmartPhInfo(iPh);
    // cout << endl;
    // printSmartPhInfo(aPh);

    person p;
    p.name = "Virat";
    p.age = 35;
    p.gender = "male";
    p.mobile = aPh;

    personInfo(p);

    return 0;
}