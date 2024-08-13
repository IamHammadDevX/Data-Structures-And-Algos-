#include<iostream>
using namespace std;

// Node for Doubly LinkedList
class Node {

public:
    int data;
    Node* prevAdd;
    Node* nxtAdd;

    // constructor
    Node(int data) {
        this->data = data;
        this->prevAdd = NULL;
        this->nxtAdd = NULL;
    }

    // destructor
    ~Node() {
        int value = this->data;
        // memory free
        if (this->nxtAdd != NULL)
        {
            delete nxtAdd;
            this->nxtAdd = NULL;
        }
        cout << "Memory is free for node: " << value << endl;

    }


};


// traversing Doubly linked list
void print(Node*& head) {
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->nxtAdd;
    }
    cout << endl;

}

// get linked list length
int getLen(Node*& head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->nxtAdd;
    }

    return len;

}

// insertion at head
void insertAtHead(Node*& head, Node*& tail, int data) {

    // empty list
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        // new node
        Node* temp = new Node(data);
        temp->nxtAdd = head;
        head->prevAdd = temp;
        head = temp;
    }
}

// tail insertion
void insertAtTail(Node*& tail, Node*& head, int data) {

    // empty list
    if (tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        // new node
        Node* temp = new Node(data);
        tail->nxtAdd = temp;
        temp->prevAdd = tail;
        tail = temp;
    }
}


// insertion at nth place
void insertAtPosition(Node*& head, Node*& tail, int position, int data) {

    // insert at first
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }


    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->nxtAdd;
        cnt++;
    }
    // insert at last
    if (temp->nxtAdd == NULL)
    {
        insertAtTail(tail, head, data);
        return;
    }




    // Node to insert
    Node* nodeToInsert = new Node(data);
    nodeToInsert->nxtAdd = temp->nxtAdd;
    temp->nxtAdd->prevAdd = nodeToInsert;
    temp->nxtAdd = nodeToInsert;
    nodeToInsert->prevAdd = temp;



}

void deleteNode(Node*& head, int position) {

    // first node
    if (position == 1)
    {
        Node* temp = head;
        temp->nxtAdd->prevAdd = NULL;

        head = temp->nxtAdd;
        temp->nxtAdd = NULL;
        // memory free
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            // Traversing to next node
            prev = curr;
            curr = curr->nxtAdd;
            cnt++;
        }

        curr->prevAdd = NULL;
        prev->nxtAdd = curr->nxtAdd;
        curr->nxtAdd = NULL;
        delete curr;
    }

}



int main()
{

    Node* node1 = new Node(20);
    // head points to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout << "Length: " << getLen(head) << endl;

    cout << "Head of node list: " << head->data << endl;
    cout << "tail of node list: " << tail->data << endl;



    cout << "Insertion at begining / Head of Node!" << endl;
    cout << "Old Node: ";
    print(head);
    insertAtHead(head, tail, 19);
    insertAtHead(head, tail, 18);
    cout << "New Node: ";
    print(head);

    cout << "Head of node list: " << head->data << endl;
    cout << "tail of node list: " << tail->data << endl;

    // tail point to node1

    cout << "Insertion at END / TAIL of Node!" << endl;
    cout << "Old Node: ";
    print(head);

    insertAtTail(tail, head, 21);
    insertAtTail(tail, head, 22);

    cout << "New Node: ";
    print(head);

    cout << "Head of node list: " << head->data << endl;
    cout << "tail of node list: " << tail->data << endl;

    cout << "Insertion at Any of Node List!" << endl;
    cout << "Old Node: ";
    print(head);
    insertAtPosition(head, tail, 6, 30);
    cout << "New Node: ";
    print(head);

    cout << "Head of node list: " << head->data << endl;
    cout << "tail of node list: " << tail->data << endl;

    cout << "Deleting first node: " << endl;
    cout << "Old Node: ";
    print(head);
    deleteNode(head, 1);
    cout << "New Node: ";
    print(head);
    // cout << "Deleting from any middle to end node: " << endl;
    // cout << "Old Node: ";
    // print(head);
    // deleteNode(head, 3);
    // cout << "New Node: ";
    // print(head);

    cout << "Head of node list: " << head->data << endl;
    cout << "tail of node list: " << tail->data << endl;

    return 0;
}