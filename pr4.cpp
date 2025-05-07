#include <iostream>
#include <stack>
using namespace std;

// Structure of tree node
struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

// Check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Build Expression Tree from prefix
Node* constructTree(string prefix) {
    stack<Node*> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        Node* node = new Node(c);
        
        if (isOperator(c)) {
            // Pop two nodes for operator
            node->left = st.top();
            st.pop();
            node->right = st.top();
            st.pop();
        }
        
        // Push current node
        st.push(node);
    }
    // Final node is root
    return st.top();
}

// Non-recursive Postorder Traversal
void postOrderNonRecursive(Node* root) {
    if (root == nullptr)
        return;
    
    stack<Node*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        
        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }
    
    // Print postorder
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

// Delete entire tree using postorder
void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    cout << "Deleting node: " << root->data << endl;
    delete root;
}

void displayTree(Node* root, int space = 0, int height = 10) {
    if (root == nullptr)
        return;

    // Increase distance between levels
    space += height;

    // Print right child first
    displayTree(root->right, space);

    // Print current node after space
    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    // Print left child
    displayTree(root->left, space);
}

// Main function
int main() {
    string prefix;
    
    cout << "Enter Prefix Expression: ";
    cin >> prefix;
    
    Node* root = constructTree(prefix);
    cout << "\nExpression Tree (sideways):\n";
    displayTree(root);

    
    cout << "\nPostorder Traversal (non-recursive): ";
    postOrderNonRecursive(root);
    cout << endl;
    
    cout << "\nDeleting tree:" << endl;
    deleteTree(root);
    
    return 0;
}
