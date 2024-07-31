#include<iostream>
using namespace std;


// Valid Character
bool valid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}
// LowerCase Conversion
char lowerCase(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        // ch = 'C' => lowerTemp = 'C' - 'A' = 3-1 = 2+'a' = 'c'
        char lowerTemp = ch - 'A' + 'a';
        return lowerTemp;
    }
}
// Palindrome
bool checkPalindrome(string str) {
    int s = 0;
    int e = str.length() - 1;
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        else {
            s++;
            e--;
        }

    }
    return true;
}
// String Palindrome
bool isPalindrome(string str) {
    string strTemp = "";
    // remove chars accept alphanumeric values
    for (int i = 0; i < str.length(); i++)
    {
        if (valid(str[i]))
        {
            strTemp.push_back(str[i]);
        }

    }
    // lowercase conversion
    for (int i = 0; i < strTemp.length(); i++)
    {
        strTemp[i] = lowerCase(str[i]);
    }

    return checkPalindrome(strTemp);
}


int main() {
    string str = "A man, a plan, a canal: Panama";
    bool palindrome = isPalindrome(str);
    if (palindrome)
    {
        cout << " String is Palindrome " << endl;
        cout << str;
    }
    else {
        cout << " String is not a Palindrome " << endl;
        cout << str;

    }
    cout << endl;




    return 0;
}