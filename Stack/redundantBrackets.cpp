#include<iostream>
#include<stack>
using namespace std;


// Redundant Brackets
bool isRedundantBracketExist(string& str) {

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // ab ya toh clossing bracket hai yn koi letter
            if (ch == ')')
            {
                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char topChar = st.top();
                    if (topChar == '+' || topChar == '-' || topChar == '*' || topChar == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (isRedundant == true)

                    return true;
                st.pop();
            }
        }

    }


    return false;
}


int main()
{

    string str = "(a+b)";

    if (isRedundantBracketExist(str)) {
        cout << "It's a Redundant Bracket!" << endl;
    }
    else
    {
        cout << "Not a Redundant Bracket!" << endl;
    }



    return 0;
}