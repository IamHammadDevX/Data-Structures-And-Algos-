#include<iostream>
using namespace std;


// stack implementation
class Stack {

    // properties
public:
    int* arr;
    int size;
    int top1;
    int top2;

    // behaviours

    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // push1()
    void push1(int elem) {
        // check whether space is avalable
        // 5 - 3 = 5 - 3 = 2 > 1
        // 2 - 7 = -5 > 1 ?? false
        // 4 - 3 = 1 > 1
        // atleast one space is avalable
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = elem;
        }
        else
        {
            cout << "Stack overflow in case of push1" << endl;
        }
    }



    // push2()
    void push2(int elem) {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = elem;
        }
        else
        {
            cout << "Stack overflow in case of push2" << endl;
        }
    }


    // pop1()
    int pop1() {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            cout << "Stack Underflows" << endl;
            return -1;
        }
    }


    // pop2()
    int pop2() {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "Stack Underflows" << endl;
            return -1;
        }
    }

    // peek1()
    int peek1() {
        // top = -1, top = 0 mean elem is available
        if (top1 >= 0)
        {
            return arr[top1];
        }
        else
        {
            cout << "Stack1 is empty!" << endl;
            return -1;
        }
    }


    // peek2()
    int peek2() {
        // top = -1, top = 0 mean elem is available
        if (top2 < size)
        {
            return arr[top2];
        }
        else
        {
            cout << "Stack2 is empty!" << endl;
            return -1;
        }
    }


};




int main()
{

    Stack st(5);

    st.push1(11);
    st.push1(12);
    st.push2(13);
    st.push2(14);
    st.push2(15);
    cout << "Before poping elem!" << endl;
    cout << "peek elem of stack 1: " << st.peek1() << endl;
    cout << "peek elem of stack 2: " << st.peek2() << endl;
    st.pop1();
    st.pop2();
    cout << "After poping elem!" << endl;
    cout << "peek elem of stack 1: " << st.peek1() << endl;
    cout << "peek elem of stack 2: " << st.peek2() << endl;



    return 0;
}