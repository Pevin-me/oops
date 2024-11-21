#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* left; 
    Node* right; 
    Node(int value) : data(value), left(nullptr), right(nullptr) {} 
}; 
 
class BST { 
public: 
    Node* root; 
    BST() : root(nullptr) {} 
    void insert(int value) { 
        root = insertRec(root, value); 
    } 
     
    void deleteNode(int value) { 
        root = deleteRec(root, value); 
    } 
     
    void inOrderTraversal() { 
        inOrderRec(root); 
        cout << endl; 
    } 
     
private: 
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
     
    Node* deleteRec(Node* root, int key) { 
        if (root == nullptr) return root; 
         
        if (key < root->data) { 
            root->left = deleteRec(root->left, key); 
        } else if (key > root->data) { 
            root->right = deleteRec(root->right, key); 
        } else { 
            if (root->left == nullptr) { 
                Node* temp = root->right; 
                delete root; 
                return temp; 
            } else if (root->right == nullptr) { 
                Node* temp = root->left; 
                delete root; 
                return temp; 
            } 
             
            Node* temp = minValueNode(root->right); 
            root->data = temp->data; 
            root->right = deleteRec(root->right, temp->data); 
        } 
        return root; 
    } 
     
    Node* minValueNode(Node* node) { 
        Node* current = node; 
        while (current && current->left != nullptr) { 
            current = current->left; 
        } 
        return current; 
    } 
     
    void inOrderRec(Node* root) { 
        if (root != nullptr) { 
            inOrderRec(root->left); 
            cout << root->data << " "; 
            inOrderRec(root->right); 
        } 
    } 
}; 
 
int main() { 
    BST tree; 
    tree.insert(50); 
    tree.insert(30); 
    tree.insert(20); 
    tree.insert(40); 
    tree.insert(70); 
    tree.insert(60); 
    tree.insert(80); 
     
    cout << "In-order traversal: "; 
    tree.inOrderTraversal(); 
    cout << "\nDelete 20 (leaf node)\nInorder Traversal:"; 
    tree.deleteNode(20); 
    tree.inOrderTraversal(); 
    cout << "\nDelete 30 (node with one child)\nInorder Traversal:"; 
    tree.deleteNode(30); 
    tree.inOrderTraversal(); 
    cout << "\nDelete 50 (node with two children)\nInorder Traversal: "; 
    tree.deleteNode(50); 
    tree.inOrderTraversal(); 
    return 0; 
}
