#include<iostream>
#include<stack>
using namespace std;

// solve functiion to push elem at bottom
void solve(stack<int>& ipStack, int x) {

    // base case
    if (ipStack.empty())
    {
        ipStack.push(x);
        return;
    }

    // elem to be save from stack in forward call
    int elem = ipStack.top();
    // bahir nikal do kch dair k lye elem ko
    ipStack.pop();

    // RECURSIVE CALL MAARDE
    solve(ipStack, x);

    // wapis call me save elem ko b lette jao
    ipStack.push(elem);
}



// insert elem at bottom of stack??
stack<int> pushAtBottom(stack<int>& ipStack, int num) {

    solve(ipStack, num);


    return ipStack;
}

int main()
{

    stack<int> st;
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);

    int numTobePushAtBottom = 9;

    stack<int> resultant = pushAtBottom(st, numTobePushAtBottom);

    cout << "Top elem is: " << resultant.top() << endl;
    resultant.pop();
    cout << "Top elem is: " << resultant.top() << endl;
    resultant.pop();
    cout << "Top elem is: " << resultant.top() << endl;
    resultant.pop();
    cout << "Top elem is: " << resultant.top() << endl;
    resultant.pop();
    cout << "Bottom elem is: " << resultant.top() << endl;

    return 0;
}