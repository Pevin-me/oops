#include <iostream> 
using namespace std; 
 
class Node { 
public: 
    int data; 
    Node* next; 
 
    Node(int data) { 
        this->data = data; 
        this->next = nullptr; 
    } 
}; 
 
class Stack { 
private: 
    Node* top; 
public: 
    Stack() { 
        top = nullptr; 
    } 
 
    void push(int data) { 
        Node* newNode = new Node(data); 
        newNode->next = top; 
        top = newNode; 
    } 
 
    void pop() { 
        if (top == nullptr) { 
            cout << "Stack underflow" << endl; 
            return; 
        } 
        Node* temp = top; 
        top = top->next; 
        delete temp; 
    } 
    int peek() { 
        if (top == nullptr) { 
            cout << "Stack is empty" << endl; 
            return -1; // Return sentinel value indicating stack is empty 
        } 
        return top->data; 
    } 
 
    bool isEmpty() { 
        return top == nullptr; 
    } 
}; 
int main() { 
    Stack stack; 
 
    stack.push(10); 
    stack.push(20); 
    stack.push(30); 
 
    cout << "Top element is: " << stack.peek() << endl; 
 
    stack.pop(); 
    cout << "Top element after pop is: " << stack.peek() << endl; 
 
    stack.pop(); 
    stack.pop(); 
    stack.pop(); // shows "Stack underflow" 
    return 0; 
}
