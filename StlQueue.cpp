#include<iostream>
#include<queue>
using namespace std;

int main() {
    cout << " CPP STL queue " << endl;
    queue<string> q;
    q.push("Python");
    q.push("C");
    q.push("C++");
    q.push("Java");
    q.push("C#");
    q.push("JavaScript");
    cout << "Top Element of stack is: " << q.front() << endl;
    cout << "Size of stack is: " << q.size() << endl;



    return 0;
}