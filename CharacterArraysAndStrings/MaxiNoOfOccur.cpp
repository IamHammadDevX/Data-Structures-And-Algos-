#include<iostream>
using namespace std;


// maximum number of occuring character
char getMaxOccurChar(string str) {

    int arr[26] = { 0 };
    // Create array for abc...z
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int num = 0;
        num = ch - 'a';
        arr[num]++;
    }
    // getting maxi char
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }

    }


    return 'a' + ans;
}

int main() {

    string str;
    cout << " Enter String: ";
    cin >> str;
    cout << "Maximum occuring character in the string is: " << getMaxOccurChar(str) << endl;
    return 0;
}