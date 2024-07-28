#include<iostream>
#include<vector>
using namespace std;

int main() {
    cout << " CPP STL vector " << endl;
    vector<int> vec;
    cout << "Capacity => " << vec.capacity() << endl;
    vec.push_back(1);
    cout << "Capacity => " << vec.capacity() << endl;
    vec.push_back(2);
    cout << "Capacity => " << vec.capacity() << endl;
    vec.push_back(3);
    cout << "Capacity => " << vec.capacity() << endl;
    vec.push_back(4);
    cout << "Capacity => " << vec.capacity() << endl;
    vec.push_back(5);
    cout << "Capacity => " << vec.capacity() << endl;
    cout << "size => " << vec.size() << endl;
    cout << "elem at idx 3: => " << vec.at(3) << endl;
    cout << "elem at idx first: => " << vec.front() << endl;
    cout << "elem at idx last: => " << vec.back() << endl;


    cout << "Before Pop(): " << endl;
    for (int i : vec) {
        cout << i << " ";
    }cout << endl;

    vec.pop_back();

    cout << "After Pop(): " << endl;
    for (int i : vec) {
        cout << i << " ";
    }cout << endl;
    

    cout << "Printing Static Vector: " << endl;
    vector<int> vec1(5,3);
    for (int i : vec1) {
        cout << i << " ";
    }cout << endl;


    return 0;
}