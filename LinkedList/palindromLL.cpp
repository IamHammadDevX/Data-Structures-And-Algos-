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



// get middle
Node* getMid(Node*& head) {


    if (head == NULL || head->nxt == NULL)
    {
        return head;
    }
    // 2 nodes
    if (head->nxt->nxt == NULL)
    {
        return head->nxt;
    }

    Node* slow = head;
    Node* fast = head->nxt;

    while (fast != NULL && fast->nxt != NULL)
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

// reverse function
Node* reverse(Node*& head) {

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = next;
    }

    return prev;

}


// check palindrome from liked list 
bool isPalindrome(Node*& head) {

    if (head->nxt == NULL)
    {
        return true;
    }
    // 1 - find mid
    Node* middle = getMid(head);
    //2 - reverse mid->nxt part [1, 2, 3, 3, 2, 1]
    Node* temp = middle->nxt;
    middle->nxt = reverse(temp);
    // 3 - compare both halves
    Node* head1 = head;
    Node* head2 = middle->nxt;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->nxt;
        head2 = head2->nxt;

    }

    // backtrack = optional
    temp = middle->nxt;
    middle->nxt = reverse(temp);


    return true;
}



// print ll
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
    head->nxt = new Node(2);
    head->nxt->nxt = new Node(3);
    head->nxt->nxt->nxt = new Node(1);
    head->nxt->nxt->nxt->nxt = new Node(2);
    head->nxt->nxt->nxt->nxt->nxt = new Node(1);
    cout << "Original Linked List: ";
    print(head);

    if (isPalindrome(head))
    {
        cout << "LL is palindrome!" << endl;
    }
    else
    {
        cout << "LL is not a palindrome!" << endl;

    }




    return 0;
}