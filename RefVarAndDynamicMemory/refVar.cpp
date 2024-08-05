#include<iostream>
using namespace std;


void update(int& n) {
    n++;
}


int main() {

    // Creation
    int i = 5;
    // int& j = i;
    // cout << "i => " << i << endl;
    // cout << "j => " << j << endl;
    // i++;
    // cout << "i => " << i << endl;
    // cout << "j => " << j << endl;
    // j++;
    // cout << "i => " << i << endl;
    // cout << "j => " << j << endl;

    cout << "Before => " << i << endl;
    update(i);
    cout << "After => " << i << endl;

    return 0;
}