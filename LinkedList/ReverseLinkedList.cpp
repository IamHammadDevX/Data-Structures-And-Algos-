#include<iostream>
using namespace std;

// Linked List Node
class Node {

public:
    int data;
    Node* nxt;

    // constructor
    Node(int data) {
        this->data = data;
        this->nxt = NULL;
    }

};

// recursive case
Node* reverse(Node*& head) {

    // base case
    if (head == NULL || head->nxt == NULL)
    {
        return head;
    }


    Node* smallProblem = reverse(head->nxt);

    head->nxt->nxt = head;
    head->nxt = NULL;

    return smallProblem;

}


// Itrative way
Node* reverseLinkedList(Node*& head) {

    return reverse(head);

    // empty or 1 case
    // if (head == NULL || head->nxt == NULL)
    // {
    //     return head;
    // }



    // Node* prev = NULL;
    // Node* curr = head;
    // Node* forward = NULL;
    // while (curr != NULL)
    // {
    //     forward = curr->nxt;
    //     curr->nxt = prev;
    //     prev = curr;
    //     curr = forward;
    // }


    // return prev;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->nxt;
    }
    cout << endl;
}


int main()
{

    // Creating a linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->nxt = new Node(20);
    head->nxt->nxt = new Node(30);
    head->nxt->nxt->nxt = new Node(40);
    head->nxt->nxt->nxt->nxt = new Node(50);

    // Print original list
    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print reversed list
    cout << "Reversed Linked List: ";
    printList(head);



    return 0;
}




// doubly linked list
/*#include<iostream>
using namespace std;

// Doubly Linked List Node
class Node {

public:
    int data;
    Node* nxt;
    Node* prev;

    // constructor
    Node(int data) {
        this->data = data;
        this->nxt = NULL;
        this->prev = NULL;
    }

};

// Function to reverse the doubly linked list recursively
Node* reverse(Node*& head) {

    // base case
    if (head == NULL || head->nxt == NULL)
    {
        return head;
    }

    Node* smallProblem = reverse(head->nxt);

    head->nxt->prev = head->nxt;
    head->nxt->nxt = head;
    head->prev = head->nxt;
    head->nxt = NULL;

    return smallProblem;
}

// Iterative way to reverse the doubly linked list
Node* reverseLinkedList(Node*& head) {
    if (head == NULL || head->nxt == NULL) {
        return head;
    }

    Node* curr = head;
    Node* temp = NULL;

    while (curr != NULL) {
        // Swap next and prev for each node
        temp = curr->prev;
        curr->prev = curr->nxt;
        curr->nxt = temp;

        // Move to the previous node, which is the next node in the original list
        curr = curr->prev;
    }

    // Adjust the head of the reversed list
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->nxt;
    }
    cout << endl;
}

int main() {

    // Creating a doubly linked list: 10 <-> 20 <-> 30 <-> 40 <-> 50
    Node* head = new Node(10);
    head->nxt = new Node(20);
    head->nxt->prev = head;
    head->nxt->nxt = new Node(30);
    head->nxt->nxt->prev = head->nxt;
    head->nxt->nxt->nxt = new Node(40);
    head->nxt->nxt->nxt->prev = head->nxt->nxt;
    head->nxt->nxt->nxt->nxt = new Node(50);
    head->nxt->nxt->nxt->nxt->prev = head->nxt->nxt->nxt;

    // Print original list
    cout << "Original Doubly Linked List: ";
    printList(head);

    // Reverse the doubly linked list
    head = reverseLinkedList(head);

    // Print reversed list
    cout << "Reversed Doubly Linked List: ";
    printList(head);

    return 0;
}
*/