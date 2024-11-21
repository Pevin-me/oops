#include <iostream>
using namespace std;

// Node structure to represent a node in the doubly linked list
class Node {
public:
    int value;       // Stores the data of the node
    Node* next;      // Pointer to the next node in the list
    Node* prev;      // Pointer to the previous node in the list

    // Constructor to initialize the node
    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;   // Pointer to the first node in the list
    Node* tail;   // Pointer to the last node in the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert a node at the beginning of the list
    void insertBegin(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {   // If the list is empty
            head = tail = newNode;  // Both head and tail point to the new node
        } else {
            newNode->next = head;   // Set the new node's next to the current head
            head->prev = newNode;   // Set the current head's prev to the new node
            head = newNode;         // Move head to point to the new node
        }
    }

    // Insert a node at the end of the list
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {    // If the list is empty
            head = tail = newNode;  // Both head and tail point to the new node
        } else {
            tail->next = newNode;    // Set the current tail's next to the new node
            newNode->prev = tail;    // Set the new node's prev to the current tail
            tail = newNode;          // Move tail to point to the new node
        }
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) return;  // If the list is empty, do nothing

        Node* current = head;
        // Traverse the list to find the node with the given value
        while (current != nullptr && current->value != value) {
            current = current->next;
        }

        if (current == nullptr) return;  // Value not found in the list

        // If the node to delete is the head
        if (current == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;  // Update the head's prev pointer
        } 
        // If the node to delete is the tail
        else if (current == tail) {
            tail = tail->prev;
            if (tail != nullptr) tail->next = nullptr;  // Update the tail's next pointer
        } 
        // If the node to delete is in the middle
        else {
            current->prev->next = current->next;  // Update previous node's next pointer
            current->next->prev = current->prev;  // Update next node's prev pointer
        }

        delete current;  // Free the memory of the deleted node
    }

    // Search for a node by value
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                return true;  // Value found in the list
            }
            current = current->next;
        }
        return false;  // Value not found
    }

    // Display the list from head to tail (forward traversal)
    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " <-> ";
            current = current->next;
        }
        cout << "null" << endl;  // Indicate the end of the list
    }

    // Display the list from tail to head (backward traversal)
    void displayBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->value << " <-> ";
            current = current->prev;
        }
        cout << "null" << endl;  // Indicate the end of the list
    }

    // Destructor to clean up dynamically allocated memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Main function to test the Doubly Linked List
int main() {
    DoublyLinkedList list;

    // Inserting nodes at the beginning
    list.insertBegin(10);
    list.insertBegin(20);
    list.insertBegin(30);
    
    cout << "List after inserting at the beginning: ";
    list.displayForward();

    // Inserting nodes at the end
    list.insertEnd(40);
    list.insertEnd(50);
    
    cout << "List after inserting at the end: ";
    list.displayForward();

    // Deleting a node by value
    list.deleteNode(30);  // Delete node with value 30
    
    cout << "List after deleting 30: ";
    list.displayForward();

    // Searching for a node by value
    if (list.search(40)) {
        cout << "Node with value 40 found!" << endl;
    } else {
        cout << "Node with value 40 not found!" << endl;
    }

    // Display list in reverse order (backward traversal)
    cout << "List in reverse order: ";
    list.displayBackward();

    return 0;
}
