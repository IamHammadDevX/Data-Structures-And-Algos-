#include<iostream>
using namespace std;

// Implementation of Stack using SINGLY LINKED LIST???

// Class representing a node in the linked list = [data | next-Node-Address];
class Node {
public:
    int data;
    Node* nxtNodeAdd;

    // constructor to initialize LL
    Node(int data) {
        this->data = data;
        this->nxtNodeAdd = NULL;
    }
};

// class to implement a stack using LL [data]
class CStack {
    // head or top of the linked list will contain the address only, of the 1st node
    Node* head;
    // to get the size of stack
    int size;
    // max size has been reached
    int maxSizeLimit;

public:
    // constructor to initialize the stack
    CStack(int maxSize) {
        // in the start head point to null
        this->head = NULL;
        this->size = 0;
        this->maxSizeLimit = maxSize;
    }
    // destructor
    ~CStack() {
        clear();
    }

    // isEmpty() = to check whether stack is empty
    bool isEmtpy() {
        // if head == null return true
        return head == NULL;
    }

    // isFull()= to check whether stack full or not
    bool isFull() {
        // maxSize =3, size =0,1,2,3
        return size >= maxSizeLimit;
    }

    // push() = push element
    void push(int val) {
        // base case
        if (isFull())
        {
            cout << "Stack Overflows! Maximum Size Limit reached!" << endl;
            return;
        }

        Node* newNode = new Node(val);

        // newNode ka nxt head
        newNode->nxtNodeAdd = head;
        head = newNode;
        // increase the size as element pushed
        size++;
    }
    // pop() = remove elems from stack
    int pop() {
        // Check for stack underflow
        // base case
        if (isEmtpy())
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        // take a temp node which points to head
        // 2 ptrs head and temp, del temp, move head
        Node* temp = head;
        int popedVal = temp->data;

        // step1: move the head to next node
        head = head->nxtNodeAdd;
        delete temp;
        size--;
        return popedVal;
    }
    // peak() = print the top elems
    int peek() {
        // base case
        if (isEmtpy())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        // if some data in stack then the top head element will be the top element
        return head->data;
    }

    // Clear()= clear all the stack untill null reached
    void clear() {
        while (!isEmtpy())
        {
            pop();
        }
        cout << "Stack has been cleared!" << endl;
    }

    // print()
    void print() {

        Node* temp = head;
        // base case
        if (isEmtpy())
        {
            cout << "Stack is Empty!" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->nxtNodeAdd;
        }
        cout << "X" << endl;
    }

    // getSize() = return the size
    int getSize() {
        return size;
    }
};

int main() {
    int maxSize, choice, value;

    // Set the maximum size for the stack
    cout << "Enter the maximum size of the stack: ";
    cin >> maxSize;

    CStack stack(maxSize);

    // Menu-driven interface
    do {
        cout << endl << "*********Stack Implementation Using Linked List Menu*********:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Clear Stack" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            cout << "Top element is: " << stack.peek() << endl;
            break;
        case 4:
            stack.print();  // Correct function call for displaying the stack
            break;
        case 5:
            stack.clear();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
