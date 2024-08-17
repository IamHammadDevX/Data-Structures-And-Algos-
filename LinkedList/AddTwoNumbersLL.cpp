#include<iostream>
using namespace std;

// struct
struct Node
{
    int data;
    struct Node* nxt;

    Node(int data) {
        this->data = data;
        this->nxt = NULL;
    }
};

class System {



private:
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

    // insert at tail
    void inserAtTail(struct Node*& head, struct Node*& tail, int value) {
        Node* temp  new Node(value);
        // empty list
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->nxt = temp;
            temp = tail;
        }


    }


    // add
    struct Node* add(struct Node* first, struct Node* second) {
        int carry = 0;

        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0, val2 = 0;
            if (first != NULL)
                val1 = first->data;

            if (second != NULL)
                val2 = second->data;

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            // create a node and add it in answer LL
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if (first != NULL)
                first = first->nxt;

            if (second != NULL)
                second = second->nxt;



        }

        return ansHead
    }



public:
    struct Node* addTwoLists(struct Node* first, struct Node* second) {

        // 1- rev the input Linked list
        first = reverse(first);
        second = reverse(second);

        //2- add 2 LINKED LIST
        Node* ans = add(first, second);

        // backtrack the reverse ans
        ans = reverse(ans);

        return ans;
    }
};


int main()
{




    return 0;
}