#include<iostream>
#include<stack>
using namespace std;




int main()
{

    string str = "virat";

    // make a stack obj
    stack<char> s;

    // push every elem of str
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }

    // Now print the str
    string ans = "";

    while (!s.empty())
    {
        char topChar = s.top();
        ans.push_back(topChar);

        s.pop();
    }

    cout << "Answer is: " << ans << endl;

    return 0;
}