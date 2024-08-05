#include<iostream>
#include<list>
using namespace std;

int main() {
    cout << " CPP STL list " << endl;
    list<int> l;
    for (int i = 1; i <= 10; i++)
    {
        l.push_back(i);
    }
    cout << "Printing List: " << endl;
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Printing List size => " << l.size() << endl;



    return 0;
}