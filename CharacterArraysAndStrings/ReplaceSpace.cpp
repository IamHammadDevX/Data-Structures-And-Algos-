#include<iostream>
using namespace std;

// Replace White Spaces with @40
string replaceWhiteSpaces(string str) {
    string tempStr = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            tempStr.push_back('@');
            tempStr.push_back('4');
            tempStr.push_back('0');
        }
        else {
            tempStr.push_back(str[i]);
        }

    }


    return tempStr;
}


int main() {

    string str = "Hi There Myself DevX.";
    cout << " Original String: " << str << endl;
    cout << " Replaced White Space String: " << replaceWhiteSpaces(str) << endl;

    return 0;
}