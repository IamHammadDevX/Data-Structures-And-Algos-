#include<iostream>
using namespace std;

// Creation of Node
class Node {



public:
    int data;
    Node* nxtNodeAdd;


    // constructor
    Node(int data) {
        this->data = data;
        this->nxtNodeAdd = NULL;
    }



};

// Insertion at head
void insertAtHead(Node*& head, int data) {

    Node* temp = new Node(data);
    temp->nxtNodeAdd = head;
    head = temp;


}

// insert at tail
void insertAtTail(Node*& tail, int data) {

    Node* temp = new Node(data);
    tail->nxtNodeAdd = temp;
    tail = temp;


}

// insert at nth position
void insertAtPosition(Node*& head, Node*& tail, int position, int data) {

    // first position
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->nxtNodeAdd;
        cnt++;
    }

    // last position
    if (temp->nxtNodeAdd == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // position node insert
    Node* nodeToInsert = new Node(data);
    nodeToInsert->nxtNodeAdd = temp->nxtNodeAdd;
    temp->nxtNodeAdd = nodeToInsert;

}

// Print
void print(Node*& head) {

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->nxtNodeAdd;
    }
    cout << endl;



}


int main() {

    // node1
    Node* node1 = new Node(12);
    // cout << node1->data << " ";
    // cout << node1->nxtNodeAdd << endl;


    // head pointed to node1
    cout << "Insertion at begining / Head of Node!" << endl;
    Node* head = node1;
    cout << "Old Node: ";
    print(head);
    insertAtHead(head, 11);
    insertAtHead(head, 10);
    cout << "New Node: ";
    print(head);


    // tail point to node1
    Node* tail = node1;

    cout << "Insertion at END / TAIL of Node!" << endl;
    cout << "Old Node: ";
    print(head);

    insertAtTail(tail, 13);
    insertAtTail(tail, 14);

    cout << "New Node: ";
    print(head);

    cout << "Insertion at Any of Node List!" << endl;
    cout << "Old Node: ";
    print(head);
    insertAtPosition(head, tail, 3, 22);
    cout << "New Node: ";
    print(head);

    cout << "Head of node list: " << head->data << endl;
    cout << "tail of node list: " << tail->data << endl;


    return 0;
}