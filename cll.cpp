#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* next; 
}; 
 
class CircularLinkedList { 
private: 
    Node* head; 
 
public: 
    CircularLinkedList() : head(nullptr) {} 
 
    void insertAtBeginning(int value) { 
        Node* newNode = new Node{value, nullptr}; 
        if (head == nullptr) { 
            head = newNode; 
            newNode->next = head; 
        } else { 
            Node* temp = head; 
            while (temp->next != head) { 
                temp = temp->next; 
            } 
            newNode->next = head; 
            temp->next = newNode; 
            head = newNode; 
        } 
    } 
 
    void insertAtEnd(int value) { 
        Node* newNode = new Node{value, nullptr}; 
        if (head == nullptr) { 
            head = newNode; 
            newNode->next = head; 
        } else { 
            Node* temp = head; 
            while (temp->next != head) { 
                temp = temp->next; 
            } 
            temp->next = newNode; 
            newNode->next = head; 
        } 
    } 
 
    void deleteByValue(int value) { 
        if (head == nullptr) return; 
        if (head->data == value && head->next == head) { 
            delete head; 
            head = nullptr; 
            return; 
        } 
        Node* curr = head; 
        Node* prev = nullptr; 
        do { 
            if (curr->data == value) { 
                if (prev != nullptr) { 
                    prev->next = curr->next; 
                } else { 
                    Node* temp = head; 
                    while (temp->next != head) { 
                        temp = temp->next; 
                    } 
                    head = curr->next; 
                    temp->next = head; 
                } 
                delete curr; 
                return; 
            } 
            prev = curr; 
            curr = curr->next; 
        } while (curr != head); 
    } 
 
    void display() { 
        if (head == nullptr) return; 
        Node* temp = head; 
        do { 
            cout << temp->data; 
            temp = temp->next; 
            if (temp != head) { 
                cout << " -> "; 
            } 
        } while (temp != head); 
        cout << endl; 
    } 
 
    bool search(int value) { 
        if (head == nullptr) return false; 
        Node* temp = head; 
        do { 
            if (temp->data == value) return true; 
            temp = temp->next; 
        } while (temp != head); 
        return false; 
    } 
}; 
 
int main() { 
    CircularLinkedList cll; 
    int choice, value; 
    cout << "\nMenu:\n"; 
    cout << "1. Insert at beginning\n"; 
    cout << "2. Insert at end\n"; 
    cout << "3. Delete by value\n"; 
    cout << "4. Display\n"; 
    cout << "5. Search\n"; 
    cout << "6. Exit\n"; 
 
    while (true) { 
        cout << "\nEnter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter value: "; 
                cin >> value; 
                cll.insertAtBeginning(value); 
                break; 
            case 2: 
                cout << "Enter value: "; 
                cin >> value; 
                cll.insertAtEnd(value); 
                break; 
            case 3: 
                cout << "Enter value to delete: "; 
                cin >> value; 
                cll.deleteByValue(value); 
                break; 
            case 4: 
                cout << "List: "; 
                cll.display(); 
                break; 
            case 5: 
                cout << "Enter value to search: "; 
                cin >> value; 
                if (cll.search(value)) { 
                    cout << "Value found in the list.\n"; 
                } else { 
                    cout << "Value not found in the list.\n"; 
                } 
                break; 
            case 6: 
                cout << "Exiting...\n"; 
                return 0; 
            default: 
                cout << "Invalid choice! Please try again.\n"; 
        } 
    } 
    return 0; 
}
