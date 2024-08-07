#include<iostream>
using namespace std;


// Recursive Function
bool checkPalindrom(string str, int left, int right) {


    // base case
    if (left > right)
        return true;

    if (str[left] != str[right])
    {
        return false;
    }
    else
    {
        return checkPalindrom(str, left + 1, right - 1);
    }


}


int main() {


    string name = "abba";
    cout << "Original string is => " << name << endl;
    bool ans = checkPalindrom(name, 0, name.length() - 1);
    if (ans)
    {
        cout << "Palindrome!" << endl;
    }
    else
    {
        cout << "Not a Palindrome!" << endl;
    }




    return 0;
}