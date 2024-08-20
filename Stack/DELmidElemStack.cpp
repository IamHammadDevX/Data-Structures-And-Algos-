#include<iostream>
#include<stack>
using namespace std;

// solve func
void solve(stack<int>& ipStack, int count, int s) {

    // base case
    if (count == s)
    {
        // DEL the base case elem
        ipStack.pop();
        return;
    }

    // lastOut elem save
    int ans = ipStack.top();
    // remove from stack
    ipStack.pop();

    // Recursive Call
    solve(ipStack, count + 1, s);

    ipStack.push(ans);


}


void deleteMiddleElem(stack<int>& ipStack, int size) {
    int cnt = 0;

    solve(ipStack, cnt, size);

}

int main()
{

    stack<int> st;
    st.push(5);
    st.push(9);
    st.push(12); //elem to be DEL from stack
    st.push(4);
    st.push(8);

    deleteMiddleElem(st, st.size());



    return 0;
}