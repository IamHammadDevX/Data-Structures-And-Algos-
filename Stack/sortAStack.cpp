#include<iostream>
#include<stack>
using namespace std;

// sortedInsert Intuition
void sortedInsert(stack<int>& st, int x) {

    // baseCase
    if (st.empty() || (!st.empty() && st.top() < x))
    {
        st.push(x);
        return;
    }

    // top elem ko save kerle 
    int num = st.top();
    st.pop();

    sortedInsert(st, x);

    st.push(num);

}

// Sort a Stack
void sortStack(stack<int>& st) {

    // base case
    if (st.empty())
    {
        return;
    }


    // top elem ko save kerle 
    int num = st.top();
    st.pop();

    // recursive call
    sortStack(st);

    sortedInsert(st, num);
}

int main()
{

    stack<int> st;
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);

    // cout << "Before Sorting the Stack top elem is: " << st.top() << endl;
    // st.pop();
    // cout << "Before Sorting the Stack top elem is: " << st.top() << endl;
    // st.pop();
    // cout << "Before Sorting the Stack top elem is: " << st.top() << endl;
    // st.pop();
    // cout << "Before Sorting the Stack top elem is: " << st.top() << endl;

    sortStack(st);

    cout << "After Sorting the Stack top elem is: " << st.top() << endl;
    st.pop();
    cout << "After Sorting the Stack top elem is: " << st.top() << endl;
    st.pop();
    cout << "After Sorting the Stack top elem is: " << st.top() << endl;
    st.pop();
    cout << "After Sorting the Stack top elem is: " << st.top() << endl;

    return 0;
}