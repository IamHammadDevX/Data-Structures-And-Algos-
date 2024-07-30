#include<iostream>
using namespace std;

// LowerCase Conversion
char lowerCase(char ch) {
    if (ch >= 'a' && ch <= 'z')
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
// LowerCase Conversion
char UpperCase(char ch) {
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch;
    }
    else
    {
        // ch = 'c' => lowerTemp = 'c' - 'a' = 3-1 = 2+'A' = 'C'
        char upperTemp = ch - 'a' + 'A';
        return upperTemp;
    }


}


// Palindrome
bool checkPalindrome(char name[], int n) {
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (lowerCase(name[s]) != lowerCase(name[e]))
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

// Reverse the string
void revStr(char name[], int n) {
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(name[s++], name[e--]);
    }

}


// String length lOGIC
int getLength(char name[]) {
    int ans = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        ans++;
    }

    return ans;
}


int main() {

    char name[100];
    cout << " Enter your name here: ";
    cin >> name;
    int len = getLength(name);
    cout << " Length of your name is: " << len << endl;
    revStr(name, len);
    cout << " Your Reverse String: " << name << endl;
    bool check = checkPalindrome(name, len);
    if (check)
    {
        cout << " Palindrome! " << name << endl;
    }
    else {
        cout << " Not a Palindrome! " << name << endl;
    }

    cout << " LowerCase conversion: " << lowerCase('H') << endl;
    cout << " UpperCase conversion: " << UpperCase('k') << endl;





    return 0;
}