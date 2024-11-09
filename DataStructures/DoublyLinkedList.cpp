#include<iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;      // Stores the data of the node
    Node* next;    // Pointer to the next node
    Node* prev;    // Pointer to the previous node

    // Constructor to initialize a new node with given data
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a new node at the front of the list
void insertAtFront(Node*& head, Node*& rear, int data) {
    Node* temp = new Node(data); // Create a new node
    if (head == NULL) { // If the list is empty
        head = temp;    // Set the new node as head
        rear = head;    // Rear also points to this first node
    } else { // If the list is not empty
        temp->next = head;    // Link new node to the current head
        head->prev = temp;    // Set current head's previous to new node
        head = temp;          // Update head to the new node
    }
}

// Function to insert a new node at the rear (end) of the list
void insertAtRear(Node*& head, Node*& rear, int data) {
    Node* temp = new Node(data); // Create a new node
    if (head == NULL) { // If the list is empty
        head = temp;    // Initialize head and rear to the new node
        rear = head;
    } else { // If the list has elements
        rear->next = temp;    // Attach the new node to the end of the list
        temp->prev = rear;    // Set new node's previous to the current rear
        rear = temp;          // Update rear to the new node
    }
}

// Function to insert a node at any given position in the list
void insertAtAnyPos(Node*& head, Node*& rear, int data, int pos) {
    if (pos < 1) { // Invalid position if less than 1
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) { // Insert at the beginning
        insertAtFront(head, rear, data);
    } else {
        int count = 1;
        Node* t1 = head;
        Node* temp = new Node(data);

        // Traverse list to find the node before the desired position
        while (count < pos - 1 && t1 != NULL) {
            t1 = t1->next;
            count++;
        }

        // Check if the position is out of range
        if (t1 == NULL) {
            cout << "Position out of range!" << endl;
            delete temp; // Avoid memory leak
        } else {
            temp->next = t1->next; // Link new node to the next node in position
            if (t1->next != NULL) {
                t1->next->prev = temp; // Update next node's previous link
            }
            t1->next = temp;       // Link previous node to new node
            temp->prev = t1;       // Set new node's previous to t1
            if (temp->next == NULL) rear = temp; // Update rear if inserted at end
        }
    }
}

// Function to delete a node at any given position in the list
void deleteAtAnyPos(Node*& head, Node*& rear, int pos) {
    if (head == NULL || pos < 1) { // Check if the list is empty or invalid position
        cout << "Invalid position or list empty" << endl;
        return;
    }
    
    if (pos == 1) { // Special case: delete the first node
        Node* temp = head;
        head = head->next; // Move head to the next node
        if (head != NULL) {
            head->prev = NULL; // Set new head's prev to NULL
        } else {
            rear = NULL; // If list becomes empty, set rear to NULL
        }
        delete temp; // Delete the old head node
    } else { // For deleting nodes other than the first
        int count = 1;
        Node* t1 = head;

        // Traverse to the node at the specified position
        while (count < pos && t1 != NULL) {
            t1 = t1->next;
            count++;
        }

        // Check if the position is out of range
        if (t1 == NULL) {
            cout << "Position is invalid!" << endl;
            return;
        }

        // Update links and delete the target node
        t1->prev->next = t1->next; // Link previous node to next node
        if (t1->next != NULL) {
            t1->next->prev = t1->prev; // Link next node back to previous node
        } else {
            rear = t1->prev; // Update rear if the last node was deleted
        }
        delete t1; // Delete the target node
    }
}

// Function to print all nodes in the list from head to rear
void printLinkedList(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        Node* t1 = head;
        while (t1 != NULL) {
            cout << t1->data << " ";
            t1 = t1->next;
        }
        cout << endl;
    }
}

// Function to print all nodes in reverse order from rear to head
void printReverseList(Node* rear) {
    if (rear == NULL) {
        cout << "List is empty" << endl;
    } else {
        Node* t1 = rear;
        while (t1 != NULL) {
            cout << t1->data << " ";
            t1 = t1->prev;
        }
        cout << endl;
    }
}

int main() {
    Node* head = NULL; // Initialize an empty list
    Node* rear = NULL; // Rear pointer also points to NULL initially

    // Insert nodes and display the list after each insertion
    insertAtFront(head, rear, 10);
    insertAtRear(head, rear, 20);
    insertAtRear(head, rear, 30);
    printLinkedList(head);
    printReverseList(rear);

    insertAtFront(head, rear, 50);
    printLinkedList(head);
    printReverseList(rear);

    // Test inserting at an arbitrary position
    insertAtAnyPos(head, rear, 60, 2);
    printLinkedList(head);
    printReverseList(rear);

    // Test deletion operations
    cout << "Deletion test" << endl;
    deleteAtAnyPos(head, rear, 1); // Delete first node
    printLinkedList(head);
    printReverseList(rear);

    deleteAtAnyPos(head, rear, 2); // Delete second node
    printLinkedList(head);
    printReverseList(rear);

    deleteAtAnyPos(head, rear, 4); // Attempt deletion at an out-of-range position

    return 0;
}
