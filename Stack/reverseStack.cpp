#include<iostream>
#include<stack>
using namespace std;


// insert at bottom
void inserArBottom(stack<int>& stack, int num) {

    // base case
    if (stack.empty())
    {
        stack.push(num);
        return;
    }

    // top elem save kerke paas rakhle
    int x = stack.top();
    stack.pop();

    // recursive call
    inserArBottom(stack, num);

    stack.push(x);

}

// reverse stack
void reverseStack(stack<int>& stack) {

    // base case
    if (stack.empty())
    {
        return;
    }

    // top elem save kerke paas rakhle
    int num = stack.top();
    stack.pop();

    // baki recursion sambhal legi
    // recursive call
    reverseStack(stack);

    inserArBottom(stack, num);

}


int main()
{

    stack<int> st;
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);

    cout << "Before Reversing Stack top elem is: " << st.top() << endl;
    reverseStack(st);
    cout << "After Reversing Stack top elem is: " << st.top() << endl;

    return 0;
}