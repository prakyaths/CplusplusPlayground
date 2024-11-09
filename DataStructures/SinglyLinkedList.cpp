#include<iostream>
using namespace std;

class Node {
public:
    int data; // Stores the data of the node
    Node* next; // Pointer to the next node in the list

    // Constructor to initialize a new node with given data
    Node(int data) {
        this->data = data;
        this->next = NULL; // Set the next pointer to NULL initially
    }
};

// Function to insert a new node at the front of the list
void insertAtFront(Node*& head, Node*& rear, int data) {
    if (head == NULL) { // If the list is empty
        Node* temp = new Node(data);
        head = temp; // Set the new node as the head
        rear = head; // Rear also points to this first node
    } 
    else { // If the list is not empty
        Node* temp = new Node(data);
        temp->next = head; // Point new node to the current head
        head = temp; // Update head to the new node
    }
}

// Function to insert a new node at the rear (end) of the list
void insertAtRear(Node*& head, Node*& rear, int data) {
    if (head == NULL) { // If the list is empty
        Node* temp = new Node(data);
        head = temp; // Initialize head and rear to the new node
        rear = head;
    } 
    else { // If the list has elements
        Node* temp = new Node(data);
        rear->next = temp; // Attach the new node to the end of the list
        rear = temp; // Update rear to the new node
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
    } 
    else {
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
        } 
        else {
            temp->next = t1->next; // Link new node to the next node in position
            t1->next = temp; // Link the previous node to the new node
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
        delete temp; // Delete the old head node

        if (head == NULL) { // If list becomes empty, set rear to NULL
            rear = NULL;
        }
    } 
    else { // For deleting nodes other than the first
        int count = 1;
        Node* t1 = head;
        Node* t2 = NULL;

        // Traverse to the node just before the position to delete
        while (count < pos && t1 != NULL) {
            t2 = t1;
            t1 = t1->next;
            count++;
        }

        // Check if the position is out of range
        if (t1 == NULL) {
            cout << "Position is invalid!" << endl;
            return;
        }

        // Link previous node to next node, effectively removing target node
        t2->next = t1->next;
        delete t1; // Delete the target node

        // If deleted node was the last node, update rear
        if (t2->next == NULL) {
            rear = t2;
        }
    }
}

// Function to print all nodes in the list
void printLinkedList(Node*& head) {
    if (head == NULL) { // Check if list is empty
        cout << "list empty" << endl;
    } 
    else {
        Node* t1 = head;
        while (t1 != NULL) { // Traverse and print each node's data
            cout << t1->data << " ";
            t1 = t1->next;
        }
    }
}

Node* reverseLinkedList(Node*& head) {
    if (head == NULL) { // Check if list is empty
        return head;
    } 
    else {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) { // Traverse and print each node's data
            Node* Next=curr->next;
            curr->next = prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
}

Node* reverseLinkedListKGroups(Node*& head, int k) {
    if (head == NULL) { // Check if list is empty
        return head;
    } 
    else {
        Node* t1 = head;
        Node* prev = NULL;
        Node* Next = NULL;
        int count = 0;
        while (t1 != NULL && count < k) { // Traverse and print each node's data
            Next=t1->next;
            t1->next = prev;
            prev=t1;
            t1=Next;
            count++;
        }

        if(Next!=NULL)
            head->next = reverseLinkedListKGroups(Next, k);
        return prev;
    }
}

// Main function to test the linked list operations
int main() {
    Node* head = NULL; // Initialize an empty list
    Node* rear = head; // Rear pointer also points to head initially

    // Insert nodes and display the list after each insertion
    insertAtFront(head, rear, 10);
    insertAtRear(head, rear, 20);
    insertAtRear(head, rear, 30);
    insertAtRear(head, rear, 70);
    printLinkedList(head);
    cout << endl;

    insertAtFront(head, rear, 50);
    printLinkedList(head);
    cout << endl;

    // Test inserting at an arbitrary position
    insertAtAnyPos(head, rear, 60, 5);
    printLinkedList(head);
    cout << endl;

    // Test deletion operations
    cout << "Deletion test" << endl;
    deleteAtAnyPos(head, rear, 1); // Delete first node
    printLinkedList(head);
    cout << endl;

    deleteAtAnyPos(head, rear, 2); // Delete second node
    printLinkedList(head);
    cout << endl;

    deleteAtAnyPos(head, rear, 5); // Attempt deletion at an out-of-range position
    cout <<"Reversing the linked list"<< endl;
    Node* ans=reverseLinkedList(head);
    printLinkedList(ans);

    cout <<"Reversing the linked list in k groups"<< endl;
    Node* kReversedAns = reverseLinkedListKGroups(ans, 2);
    printLinkedList(kReversedAns);
    return 0;
}
