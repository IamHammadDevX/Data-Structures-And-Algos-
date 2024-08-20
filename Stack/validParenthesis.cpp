#include<iostream>
#include<stack>
using namespace std;


// valid parenthesis
bool isValid(string expression) {

    // make a stack
    stack<char> st;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // if opening bracked push to stack
        if (ch == '{' || ch == '(' || ch == '[') //opening braces , {, [, (
        {
            st.push(ch);
        }
        // if closing bracket, stackTop check and pop ], } , )
        else
        {
            if (!st.empty())
            {
                char topCh = st.top();
                // compare with ch and topCh
                if ((ch == '}' && topCh == '{') ||
                    (ch == ')' && topCh == '(') ||
                    (ch == ']' && topCh == '[')) {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{

    string exp = "{()[])}";

    if (isValid(exp))
    {
        cout << " Valid Parenthesis! " << endl;
    }
    else
    {
        cout << " Not Valid Parenthesis! " << endl;
    }




    return 0;
}