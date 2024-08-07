#include<iostream>
using namespace std;


// Recursive Function
void reverse(string& str, int i, int j) {
    cout << "Call received for string => " << str << endl;
    // base case
    if (i > j)
    {
        return;
    }


    swap(str[i++], str[j--]);

    // recursive relation
    reverse(str, i, j);


}


int main() {

    // n-i-1 = 5 - 0 - 1 = 4
    string name = "abcde";
    cout << "Original string is => " << name << endl;
    reverse(name, 0, name.length() - 1);
    cout << "Reverse of string => " << name << endl;

    return 0;
}