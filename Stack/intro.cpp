#include<iostream>
#include<stack>
using namespace std;

class Stack {

    // properties
public:
    int* arr;
    int size;
    int top;

    // behaviours

    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push()
    void push(int element) {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }

    }

    // POP()
    void pop() {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflows" << endl;
        }
    }

    // peek()
    int peek() {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }


    }

    // isEmpty()
    bool isEmpty() {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }


    }


};


int main()
{

    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Peek elem is " << st.peek() << endl;
    st.pop();
    cout << "Peek elem is " << st.peek() << endl;
    st.pop();
    cout << "Peek elem is " << st.peek() << endl;
    st.pop();
    cout << "Peek elem is " << st.peek() << endl;
    st.pop();
    cout << "Peek elem is " << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "Stack is not empty!" << endl;
    }



    /*
    // stack creation using STL
    stack<int> s;

    // insert op
    s.push(2);
    s.push(3);

    // Pop operation
    s.pop();

    cout << " Printing the top element " << s.top() << endl;

    if (s.empty())
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "Stack is not empty!" << endl;

    }

    cout << "Size of stack is " << s.size() << endl;
    */

    return 0;
}