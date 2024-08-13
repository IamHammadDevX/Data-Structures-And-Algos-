#include<iostream>
using namespace std;

// Linked List Node
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


// Insertion at begining or head = //head node already creat
//          temp[2,0]->[4,0]head
void insertAtHead(Node*& head, int d) {

    // create new node
    Node* temp = new Node(d);
    temp->nxtNodeAdd = head;
    head = temp;

}


// Insertion at End
void insertAtTail(Node*& tail, int d) {

    // create new node
    Node* temp = new Node(d);
    tail->nxtNodeAdd = temp;
    tail = temp;

}

// insertion at nth position
void insertAtPosition(Node*& head, Node*& tail, int position, int data) {

    // insert at first
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
    // insert at last
    if (temp->nxtNodeAdd == NULL)
    {
        insertAtTail(tail, data);
        return;
    }




    // Node to insert
    Node* nodeToInsert = new Node(data);
    nodeToInsert->nxtNodeAdd = temp->nxtNodeAdd;
    temp->nxtNodeAdd = nodeToInsert;


}


// print Node
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

    // CREATE NODE1
    Node* node1 = new Node(19);
    // cout << node1->data << " ";
    // cout << node1->nxtNodeAdd << endl;

    // head pointed to node1
    cout << "Insertion at begining / Head of Node!" << endl;
    Node* head = node1;
    cout << "Old Node: ";
    print(head);
    insertAtHead(head, 18);
    insertAtHead(head, 17);
    cout << "New Node: ";
    print(head);


    // tail point to node1
    Node* tail = node1;

    cout << "Insertion at END / TAIL of Node!" << endl;
    cout << "Old Node: ";
    print(head);

    insertAtTail(tail, 20);
    insertAtTail(tail, 21);

    cout << "New Node: ";
    print(head);


    cout << "Insertion at Any of Node List!" << endl;
    cout << "Old Node: ";
    print(head);
    insertAtPosition(head, tail, 6, 22);
    cout << "New Node: ";
    print(head);

    cout << "Head of node list: " << head->data << endl;
    cout << "tail of node list: " << tail->data << endl;


    return 0;
}