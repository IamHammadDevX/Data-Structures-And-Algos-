#include<iostream>
#include<map>
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

// delete the duplicate node and return unique LL
Node* uniqueSortedList(Node*& head) {
    // empty list
    if (head == NULL)
    {
        return NULL;
    }

    // non-empty list

    Node* curr = head;

    while (curr != NULL)
    {
        if ((curr->nxt != NULL) && curr->data == curr->nxt->data)
        {
            // node to delete matching case
            // store the add for not matching node
            Node* notMatchNode = curr->nxt->nxt;
            // add for node to delete
            Node* nodeToDel = curr->nxt;
            delete(nodeToDel);
            curr->nxt = notMatchNode;
        }
        else
        {
            // not matching case
            curr = curr->nxt;
        }


    }

    return head;

}

// Unique unsorted list
// Node* uniqueUnsortedList(Node*& head) {
//     if (head == NULL) {
//         return NULL;
//     }

//     Node* curr = head;

//     while (curr != NULL) {
//         Node* prev = curr;
//         Node* temp = curr->nxt;

//         while (temp != NULL) {
//             if (curr->data == temp->data) {
//                 // Node to delete
//                 Node* nodeToDel = temp;
//                 prev->nxt = temp->nxt;
//                 temp = temp->nxt;
//                 delete nodeToDel;
//             }
//             else {
//                 // Not matching case
//                 prev = temp;
//                 temp = temp->nxt;
//             }
//         }

//         curr = curr->nxt;
//     }

//     return head;
// }


// using map
Node* uniqueUnsortedList(Node*& head) {
    if (head == NULL) {
        return NULL;
    }

    map<int, bool> visited;  // Use int (data) instead of Node* as key
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (visited[curr->data]) {  // Check if the value is already visited
            // Node is a duplicate
            Node* nodeToDel = curr;
            prev->nxt = curr->nxt;
            curr = curr->nxt;
            delete(nodeToDel);
        }
        else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->nxt;
        }
    }

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
    head->nxt = new Node(3);
    head->nxt->nxt = new Node(2);
    head->nxt->nxt->nxt = new Node(3);
    head->nxt->nxt->nxt->nxt = new Node(4);
    head->nxt->nxt->nxt->nxt->nxt = new Node(2);
    head->nxt->nxt->nxt->nxt->nxt->nxt = new Node(5);

    cout << "Original Linked List: ";
    print(head);

    // Node* uniquelinkedList = uniqueSortedList(head);
    // cout << "Unique Sorted Linked List: ";
    // print(head);
    Node* uniquelinkedList = uniqueUnsortedList(head);
    cout << "Unique Unsorted Linked List: ";
    print(head);


    return 0;
}