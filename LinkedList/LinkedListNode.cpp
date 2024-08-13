#include<iostream>
using namespace std;

// Creation of Node
class Node {
public:
    int data;
    Node* nextAdd;

    // constructor
    Node(int data) {
        this->data = data;
        this->nextAdd = NULL;
    }
};


int main() {

    Node* node1 = new Node(37);
    cout << node1->data << endl;
    cout << node1->nextAdd << endl;


    return 0;
}