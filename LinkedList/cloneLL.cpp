#include<iostream>
#include<unordered_map>
using namespace std;

// NODE
class Node {

public:
    int data;
    Node* nxt;
    Node* rand;

    // Constructor
    Node(int data) {
        this->data = data;
        this->nxt = NULL;
        this->rand = NULL;
    }

};

// insert at tail
void insertAtTail(Node*& head, Node*& tail, int d) {

    Node* newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->nxt = newNode;
        tail = newNode;
    }
}


// clone logic => USING MAPPING LOGIC
// Node* cloneList(Node*& head) {

//     // 1 - create a clone list
//     Node* cloneHead = NULL;
//     Node* cloneTail = NULL;

//     Node* temp = head;

//     while (temp != NULL)
//     {
//         insertAtTail(cloneHead, cloneTail, temp->data);
//         temp = temp->nxt;
//     }

//     // 2 - create a map
//     unordered_map<Node*, Node*> mapping;

//     Node* originalNode = head;
//     Node* cloneNode = cloneHead;

//     while (originalNode != NULL)
//     {
//         mapping[originalNode] = cloneNode;
//         originalNode = originalNode->nxt;
//         cloneNode = cloneNode->nxt;
//     }

//     originalNode = head;
//     cloneNode = cloneHead;
//     while (originalNode != NULL)
//     {
//         cloneNode->rand = mapping[originalNode->rand];
//         originalNode = originalNode->nxt;
//         cloneNode = cloneNode->nxt;

//     }


//     return cloneHead;

// }


// LOGIC 2
// clone logic => USING STATIC MEMORY
Node* cloneList(Node*& head) {

    // 1 - create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->nxt;
    }

    // 2 - add cloneNode on-between originalNode

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node* next = originalNode->nxt;
        originalNode->nxt = cloneNode;
        originalNode = next;

        next = cloneNode->nxt;
        cloneNode->nxt = originalNode;
        cloneNode = next;
    }

    // 3 - copy random ptrs
    temp = head;

    while (temp != NULL)
    {
        if (temp->nxt != NULL)
        {
            temp->nxt->rand = temp->rand ? temp->rand->nxt : temp->rand;
        }
        temp = temp->nxt->nxt;
    }



    //4 - revert changes done in step 2
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->nxt = cloneNode->nxt;
        originalNode = originalNode->nxt;

        if (originalNode!- NULL)
        {
            cloneNode->nxt = originalNode->nxt;
        }
        cloneNode = cloneNode->nxt;
    }

    return cloneHead;

}


int main()
{



    // require to check from chatGPT
    Node* head = new Node(1);
    head->rand = new Node(3);
    head->nxt = new Node(2);
    head->nxt->nxt = new Node(3);
    head->nxt->nxt->rand = new Node(5);
    head->nxt->nxt->nxt = new Node(4);
    head->nxt->nxt->nxt->nxt = new Node(5);

    // cloned
    Node* cloneLL = cloneList(head);


    return 0;
}