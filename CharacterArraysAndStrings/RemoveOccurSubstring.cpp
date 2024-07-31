#include<iostream>
using namespace std;

// Remove all parts of a substring
string removeOccurPart(string str, string part) {

    while (str.length() > 0 && str.find(part) < str.length())
    {
        str.erase(str.find(part), part.length());
    }


    return str;
}


int main() {

    string str = "daabcbaabcbc", part;
    cout << " Enter the part to remove: ";
    cin >> part;
    cout << " Original String: " << str << endl;
    cout << " Modified String after removing: " << part << " => " << removeOccurPart(str, part) << endl;


    return 0;
}