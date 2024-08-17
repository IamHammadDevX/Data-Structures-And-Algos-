#include<iostream>
using namespace std;

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


// reverse in K-group
Node* Kreverse(Node*& head, int k) {
    // base case
    if (head == NULL)
    {
        return head;
    }

    // step1: reve first k-node => k=2
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->nxt;
        // reverse two kth node logic
        curr->nxt = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: recursive call
    if (next != NULL)
    {
        head->nxt = Kreverse(next, k);
    }


    return prev;
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


    Node* head = new Node(10);
    head->nxt = new Node(20);
    head->nxt->nxt = new Node(30);
    head->nxt->nxt->nxt = new Node(40);
    head->nxt->nxt->nxt->nxt = new Node(50);
    head->nxt->nxt->nxt->nxt->nxt = new Node(60);

    cout << "Original Linked List: ";
    printList(head);

    int k = 3;
    Node* kthGroupRev = Kreverse(head, k);
    cout << "Kth group reversed Linked List: ";
    printList(kthGroupRev);

    return 0;
}