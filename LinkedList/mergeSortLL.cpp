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


// print
void print(Node*& head) {

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->nxt;
    }
    cout << endl;


}


// find Mid
Node* findMid(Node*& head) {

    Node* slow = head;
    Node* fast = head->nxt;

    while (fast != NULL && fast->nxt != NULL)
    {
        slow = slow->nxt;
        fast = fast->nxt->nxt;
    }


    return slow;
}


// merge 2 sorted linked list
Node* merge(Node*& left, Node*& right) {

    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    // mask node 
    Node* ans = new Node(-1);
    Node* temp = ans;

    // merging
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->nxt = left;
            temp = left;
            left = left->nxt;
        }
        else
        {
            temp->nxt = right;
            temp = right;
            right = right->nxt;
        }
    }

    while (left != NULL)
    {
        temp->nxt = left;
        temp = left;
        left = left->nxt;
    }
    while (right != NULL)
    {
        temp->nxt = right;
        temp = right;
        right = right->nxt;
    }


    ans = ans->nxt;

    return ans;
}



// merge Sort algo in LL
Node* mergeSort(Node*& head) {

    // base call
    if (head == NULL || head->nxt == NULL)
    {
        return head;
    }

    // step1 - find mid
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->nxt;
    mid->nxt = NULL;
    // step2 - recursively sort
    left = mergeSort(left);
    right = mergeSort(right);

    // step3 - merge both halves
    Node* result = merge(left, right);

    return result;
}

int main()
{
    // require to check from chatGPT
    Node* head = new Node(9);
    head->nxt = new Node(3);
    head->nxt->nxt = new Node(5);
    head->nxt->nxt->nxt = new Node(2);
    head->nxt->nxt->nxt->nxt = new Node(1);

    cout << "Original Linked List before sorting: ";
    print(head);

    Node* mer = mergeSort(head);
    cout << "Merged Sorted Linked List: ";
    print(mer);



    return 0;
}