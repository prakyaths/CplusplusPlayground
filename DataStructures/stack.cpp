#include<iostream>
#include<string>
using namespace std;

// Class to represent a Stack with basic operations like push, pop, peek, and isEmpty
class Stack {
public:
    int *arr;  // Dynamic array to hold stack elements
    int size;  // Maximum size of the stack
    int top;   // Index of the top element in the stack

    // Constructor to initialize stack with given size
    Stack(int size) {
        this->size = size;
        arr = new int(size);  // Allocate memory for stack array
        top = -1;             // Initialize top to -1 (stack is initially empty)
    }

    // Pushes an element onto the stack
    void push(int data) {
        if (top >= size - 1) {
            // Stack overflow condition
            cout << "stack is full" << endl;
        } 
        else {
            arr[++top] = data;  // Increment top and add element at the new top
        }
    }

    // Pops the top element from the stack and returns it
    int pop() {
        if (top == -1) {
            // Stack underflow condition
            cout << "stack is empty, cannot pop" << endl;
            return -1;
        } 
        else {
            int element = arr[top];  // Retrieve the top element
            top--;                   // Decrement top to remove the element
            return element;
        }
    }

    // Returns the top element without removing it from the stack
    int peek() {
        if (top == -1) {
            // Stack is empty, no element to return
            return -1;
        } 
        else {
            return arr[top];  // Return the current top element
        }
    }

    // Checks if the stack is empty and prints a message
    void isEmpty() {
        if (top == -1) {
            cout << "stack is empty" << endl;
        } 
        else {
            cout << "stack is not empty" << endl;
        }
    }
};

int main() {
    Stack st(5);  // Initialize a stack of size 5

    st.push(1);  // Push element 1 onto the stack
    cout << "peek element: " << st.peek() << endl;  // Check the top element

    st.push(2);  // Push element 2 onto the stack
    cout << "peek element: " << st.peek() << endl;  // Check the top element

    cout << "popping element: " << st.pop() << endl;  // Pop the top element
    cout << "peek element: " << st.peek() << endl;    // Check the top element after pop

    st.isEmpty();  // Check if the stack is empty

    cout << "popping element: " << st.pop() << endl;  // Pop another element
    cout << "peek element: " << st.peek() << endl;    // Check the top element after pop

    st.isEmpty();  // Check if the stack is empty after all pops

    return 0;
}
