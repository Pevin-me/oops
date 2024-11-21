Code: 
#include <iostream> 
using namespace std; 
 
class Node { 
public: 
    int data; 
    Node* left; 
    Node* right; 
 
    Node(int value) : data(value), left(nullptr), right(nullptr) {} 
}; 
 
class BinarySearchTree { 
public: 
    BinarySearchTree() : root(nullptr) {} 
 
    void insert(int value) { 
        root = insertRec(root, value); 
    } 
 
    bool search(int value) { 
        return searchRec(root, value); 
    } 
 
    void inorder() { 
        inorderRec(root); 
        cout << endl; 
    } 
 
private: 
    Node* root; 
 
    Node* insertRec(Node* node, int value) { 
        if (node == nullptr) { 
            return new Node(value); 
        } 
        if (value < node->data) { 
            node->left = insertRec(node->left, value); 
        } else if (value > node->data) { 
            node->right = insertRec(node->right, value); 
        } 
        return node; 
    } 
 
    bool searchRec(Node* node, int value) { 
        if (node == nullptr) { 
            return false; 
        } 
        if (value == node->data) { 
            return true; 
        } else if (value < node->data) { 
            return searchRec(node->left, value); 
        } else { 
            return searchRec(node->right, value); 
        } 
    } 
 
    void inorderRec(Node* node) { 
        if (node != nullptr) { 
            inorderRec(node->left); 
            cout << node->data << " "; 
            inorderRec(node->right); 
        } 
    } 
}; 
 
int main() { 
    BinarySearchTree bst; 
    int choice, value; 
    cout << "Menu:\n"; 
    cout << "1. Insert\n"; 
    cout << "2. Search\n"; 
    cout << "3. Inorder Traversal\n"; 
    cout << "4. Exit\n"; 
 
    while (true) { 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                cout << "Enter value to insert: "; 
                cin >> value; 
                bst.insert(value); 
                break; 
            case 2: 
                cout << "Enter value to search: "; 
                cin >> value; 
                cout<<(bst.search(value) ? "Found" : "Not Found")<<endl; 
                break; 
            case 3: 
                cout << "Inorder traversal: "; 
                bst.inorder(); 
                break; 
            case 4: 
                return 0; 
            default: 
                cout << "Invalid choice! \n"; 
        } 
    } 
    return 0; 
}
