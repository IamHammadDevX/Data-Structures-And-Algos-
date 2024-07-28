#include<iostream>
#include<deque>
using namespace std;

int main() {
    cout << " CPP STL deque " << endl;
    deque<int> d;
    d.push_back(2);
    d.push_front(1);
    for (int i = 3; i <= 10; i++)
    {
        d.push_back(i);
    }
    cout << "Printing Deque: " << endl;
    for (int i : d) {
        cout << i << " ";
    }cout << endl;

    cout << "Size-> Before Erase: " << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);
    cout << "Size-> After Erase: " << d.size() << endl;
    cout << "Printing Deque After erasing: " << endl;
    for (int i : d) {
        cout << i << " ";
    }cout << endl;




    return 0;
}