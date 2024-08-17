#include<iostream>
using namespace std;


// class node
class Node {

public:
    int data;
    Node* nxtNodeAdd;

    // Constructor to initialize node
    Node(int data) {
        this->data = data;
        this->nxtNodeAdd = NULL;
    }


    // De structor
    ~Node() {

        int value = this->data;
        if (nxtNodeAdd != NULL)
        {
            delete nxtNodeAdd;
            nxtNodeAdd = NULL;
        }

        cout << "Memory is free for node: " << value << endl;

    }


};



// insertion
void insertion(Node*& tail, int element, int data) {

    // empty case
    if (tail == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->nxtNodeAdd = newNode;
    }
    else
    {
        // non-empty
        // assuming that element is present!
        Node* curr = tail;
        while (curr->data != element)
        {
            curr = curr->nxtNodeAdd;
        }

        // element found embed
        Node* temp = new Node(data);
        temp->nxtNodeAdd = curr->nxtNodeAdd;
        curr->nxtNodeAdd = temp;

    }
}

// traversing
void print(Node*& tail) {

    Node* temp = tail;

    if (tail == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }


    do
    {
        cout << tail->data << " ";
        tail = tail->nxtNodeAdd;
    } while (tail != temp);
    cout << endl;


}

// deleting node
void deleteNode(Node*& tail, int value) {
    // empty case
    if (tail == NULL)
    {
        cout << "List is empty, please! check again" << endl;
        return;
    }
    else
    {
        // non-empty
        // assume value found
        Node* prev = tail;
        Node* curr = prev->nxtNodeAdd;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->nxtNodeAdd;

            // value not found
            if (curr == tail->nxtNodeAdd)
            {
                cout << "Value " << value << " not found in the list." << endl;
                return;
            }

        }


        prev->nxtNodeAdd = curr->nxtNodeAdd;
        // 1 node case
        if (curr == prev)
        {
            tail = NULL;
        }


        // >=2 node case
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->nxtNodeAdd = NULL;
        delete curr;
    }
}

bool isCircular(Node*& head) {

    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node* temp = head->nxtNodeAdd;

    while (temp != NULL && temp != head)
    {
        temp = temp->nxtNodeAdd;
    }



    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }




}



int main()
{

    Node* tail = NULL;
    insertion(tail, 5, 3);
    cout << "Old node list: ";
    print(tail);
    insertion(tail, 3, 5);
    cout << "New node list: ";
    print(tail);
    insertion(tail, 5, 7);
    cout << "New node list: ";
    print(tail);
    insertion(tail, 7, 9);
    cout << "New node list: ";
    print(tail);
    insertion(tail, 9, 11);
    cout << "New node list: ";
    print(tail);
    insertion(tail, 3, 4);
    cout << "New node list: ";
    print(tail);
    insertion(tail, 11, 13);
    cout << "New node list: ";
    print(tail);

    // deleteNode(tail, 3);
    // cout << "New node list: ";
    // print(tail);
    // deleteNode(tail, 11);
    // cout << "New node list: ";
    // print(tail);
    // deleteNode(tail, 13);
    // cout << "New node list: ";
    // print(tail);
    // deleteNode(tail, 100);
    // cout << "New node list: ";
    // print(tail);

    if (isCircular(tail))
    {
        cout << "Linked List is circular" << endl;
    }
    else
    {
        cout << "Linked List is not circular" << endl;
    }




    return 0;
}