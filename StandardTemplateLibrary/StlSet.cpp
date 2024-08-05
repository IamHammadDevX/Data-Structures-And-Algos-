#include<iostream>
#include<set>
using namespace std;

int main() {
    cout << " CPP STL set " << endl;
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(1);
    s.insert(1);
    s.insert(3);
    cout << "Set Elements Before Erasing: " << endl;
    for (auto i : s) {
        cout << i << " ";
    }cout << endl;

    set<int>::iterator itr = s.begin();
    itr++;
    s.erase(itr);
    cout << "Set Elements After Erasing: " << endl;
    for (auto i : s) {
        cout << i << " ";
    }cout << endl;
    cout << "Set Elements 5 present??: " << s.count(5) << endl;
    // set<int>::iterator it = s.find(5);
    // for (auto i=it; i!=s.end(); i++) {
    //     cout << i << " ";
    // }cout << endl;
    



    return 0;
}