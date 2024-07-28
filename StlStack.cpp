#include<iostream>
#include<stack>
using namespace std;

int main() {
    cout << " CPP STL stack " << endl;
    stack<string> s;
    s.push("Python");
    s.push("C");
    s.push("C++");
    s.push("Java");
    s.push("C#");
    s.push("JavaScript");
    cout << "Top Element of stack is: " << s.top() << endl;
    cout << "Size of stack is: " << s.size() << endl;
    




    return 0;
}