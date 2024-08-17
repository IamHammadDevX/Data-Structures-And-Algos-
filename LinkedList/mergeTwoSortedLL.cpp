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
// node
class Node2 {

public:
    int data;
    Node2* nxt;

    // constrcutor
    Node2(int data) {
        this->data = data;
        this->nxt = NULL;
    }

};

Node* solve(Node*& first, Node2*& second) {

    // if first list have only one node
    if (first->nxt == NULL)
    {
        first->nxt = second;
        return first;
    }


    // making nodes
    Node* curr1 = first;
    Node* next1 = curr1->nxt;
    Node2* curr2 = second;
    Node2* next2 = curr2->nxt;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // add node in between
            curr1->nxt = curr2;
            // keeping track of rem seconds nodes
            next2 = curr2->nxt;
            curr2->nxt = next1;
            // update ptrs
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->nxt;

            if (next1 == NULL)
            {
                curr1->nxt = curr2;
                return first;
            }

        }

    }


    return first;
}


// merge 2 sorted ll
Node* sortTwoLists(Node*& first, Node2*& second) {

    // base call
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }



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
void print2(Node2*& head) {

    Node2* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->nxt;
    }
    cout << endl;


}


int main()
{
    Node* first = new Node(1);
    first->nxt = new Node(3);
    first->nxt->nxt = new Node(5);

    cout << "Original 1st Linked List: ";
    print(first);
    cout << endl;
    Node2* second = new Node2(2);
    second->nxt = new Node2(4);
    second->nxt->nxt = new Node2(5);

    cout << "Original 2nd Linked List: ";
    print2(second);

    Node* merged = sortTwoLists(first, second);
    print(first);



    return 0;
}