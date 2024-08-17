#include<iostream>
using namespace std;

// node
class Node {

public:
    int data;
    Node* nxt;

    // constrcutor
    Node(int data) {
        this->data = data;
        this->nxt = NULL;
    }

};


// // Sort 0's, 1's, and 2's in LL
// Node* sortZOT(Node*& head) {

//     int zeroCnt = 0, oneCnt = 0, twoCnt = 0;


//     Node* temp = head;

//     while (temp != NULL)
//     {
//         if (temp->data == 0)
//         {
//             zeroCnt++;
//         }
//         else if (temp->data == 1)
//         {
//             oneCnt++;
//         }
//         else if (temp->data == 2)
//         {
//             twoCnt++;
//         }
//         temp = temp->nxt;
//     }

//     // replace the sorted LL
//     temp = head;
//     while (temp != NULL)
//     {
//         if (zeroCnt != 0)
//         {
//             temp->data = 0;
//             zeroCnt--;
//         }
//         else if (oneCnt != 0)
//         {
//             temp->data = 1;
//             oneCnt--;
//         }
//         else if (twoCnt != 0)
//         {
//             temp->data = 2;
//             twoCnt--;
//         }
//         temp = temp->nxt;
//     }

//     return head;
// }

void insertAtTail(Node*& tail, Node* curr) {
    tail->nxt = curr;
    tail = curr;
}
// Brute force approach = for data replacement prohibited condition
// Sort 0's, 1's, and 2's in LL
Node* sortZOT(Node*& head) {

    // dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);

        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);

        }
        curr = curr->nxt;
    }

    // merge 3 linkedlists
    // let 1s list is not empty
    if (oneHead->nxt != NULL)
    {
        zeroTail->nxt = oneHead->nxt;
    }
    else
    {
        // 1st list empty
        zeroTail->nxt = twoHead->nxt;
    }
    oneTail->nxt = twoHead->nxt;
    twoTail->nxt = NULL;

    // map the head at right place
    head = zeroHead->nxt;

    // DEL DUMMY'S
    delete zeroHead;
    delete oneHead;
    delete twoHead;



    return head;
}


// print Node
void print(Node*& head) {

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->nxt;
    }
    cout << endl;


}



int main()
{

    Node* head = new Node(1);
    head->nxt = new Node(0);
    head->nxt->nxt = new Node(1);
    head->nxt->nxt->nxt = new Node(2);
    head->nxt->nxt->nxt->nxt = new Node(1);
    head->nxt->nxt->nxt->nxt->nxt = new Node(0);
    head->nxt->nxt->nxt->nxt->nxt->nxt = new Node(2);

    cout << "Original Linked List: ";
    print(head);

    Node* sorted = sortZOT(head);
    cout << "Sorted Linked List: ";
    print(head);


    return 0;
}