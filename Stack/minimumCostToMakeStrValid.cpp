#include<iostream>
#include<stack>
using namespace std;


// minimum cost to make string valid
int findMinimumCost(string& str) {

    // odd case return -1
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    // even case
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{' || ch == '(')
        {
            s.push(ch);
        }
        // closing brace wala case
        else
        {
            if (!s.empty() && (s.top() == '{' || s.top() == '('))
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    // stack invalid expression hoga
    int a = 0, b = 0;

    while (!s.empty())
    {
        if (s.top() == '{' || s.top() == '(')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();

    }


    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;


}

int main()
{

    string str = "{{}{}{}{}{}{}{}{}{{{(()(";

    int res = findMinimumCost(str);
    cout << "Minimum cost to make braces valid: " << res << endl;


    return 0;
}