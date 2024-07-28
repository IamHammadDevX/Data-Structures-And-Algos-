#include<iostream>
#include<map>
using namespace std;

int main() {
    cout << " CPP STL map " << endl;
    map<int, string> m;
    m[1] = "Python";
    m[2] = "C++";
    m.insert({ 3, "C" });
    m.insert({ 4, "C#" });
    m.insert({ 5, "Java" });
    m.insert({ 6, "JavaScript" });
    cout << "Map Elems before Erase: " << endl;
    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }


    cout << "Finding Element 3: " << m.count(3) << endl;

    m.erase(5);
    cout << "Map Elems After Erase: " << endl;
    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }



    return 0;
}