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


int getLen(Node*& head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->nxt;
    }

    return len;
}

// optimised solution
Node* getMiddle(Node*& head) {

    // empty or one node case
    if (head == NULL || head->nxt == NULL)
    {
        return head;
    }
    // 2 nodes
    if (head->nxt->nxt == NULL)
    {
        return head->nxt;
    }


    // two pointer approach
    Node* slow = head;
    Node* fast = head->nxt;

    while (fast != NULL)
    {
        fast = fast->nxt;
        if (fast != NULL)
        {
            fast = fast->nxt;
        }

        slow = slow->nxt;
    }

    return slow;

}

// Main middle func
Node* findMiddle(Node*& head) {

    return getMiddle(head);


    // first approach ittrative
    // int len = getLen(head);
    // int ans = (len / 2);

    // Node* temp = head;
    // int cnt = 0;
    // while (cnt < ans)
    // {
    //     temp = temp->nxt;
    //     cnt++;
    // }
    // return temp;
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
    head->nxt->nxt->nxt->nxt->nxt = new Node(60);

    // Print original list
    cout << "Original Linked List: ";
    printList(head);


    Node* middle = findMiddle(head);
    if (middle != NULL) {
        cout << "Middle node of the Linked List: " << middle->data << endl;
    }
    else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}