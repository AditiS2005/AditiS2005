#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    void insert();
    void inorder(Node *root);
    void display(Node *root);
    void smallest();
    void highest();
    void mirror(Node *root);
    int height(Node *root);
    bool search(Node *root, int key);
};

void BST::insert() {
    Node *nn, *temp;
    int flag = 0;
    nn = new Node();
    cout << "\nEnter Data: ";
    cin >> nn->data;
    nn->left = NULL;
    nn->right = NULL;
    if (root == NULL) {
        root = nn;
    } else {
        temp = root;
        while (flag == 0) {
            if (nn->data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = nn;
                    flag++;
                } else {
                    temp = temp->left;
                }
            } else if (nn->data > temp->data) {
                if (temp->right == NULL) {
                    temp->right = nn;
                    flag++;
                } else {
                    temp = temp->right;
                }
            } else {
                cout << "\nNode already exists.";
                flag++;
            }
        }
    }
}

void BST::inorder(Node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

void BST::smallest() {
    if (root == NULL) {
        cout << "\nThe tree is empty.";
        return;
    }
    Node *temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    cout << "\nSmallest: " << temp->data;
}

bool BST::search(Node *temp, int key) {
    if (temp == NULL) {
        return false;
    }
    if (temp->data == key) {
        return true;
    } else if (key < temp->data) {
        return search(temp->left, key);
    } else {
        return search(temp->right, key);
    }
}

void BST::highest() {
    if (root == NULL) {
        cout << "\nThe tree is empty.";
        return;
    }
    Node *temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    cout << "\nLargest: " << temp->data;
}

void BST::display(Node *root) {
    cout << "\nInorder sequence: ";
    if (root == NULL) {
        cout << "The tree is empty.";
        return;
    }
    inorder(root);
}

void BST::mirror(Node *root) {
    if (root != NULL) {
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }
}

int BST::height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    BST obj;
    int choice, n,key;

    do {
        cout << "\n\n--------MENU--------";
        cout << "\n1. Insert Elements";
        cout << "\n2. Display Inorder Sequence";
        cout << "\n3. Find Smallest Element";
        cout << "\n4. Find Largest Element";
        cout << "\n5. Mirror the Tree";
        cout << "\n6. Display Height of Tree";
        cout << "\n7. Search Node ";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the number of elements you want to insert: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    obj.insert();
                }
                break;

            case 2:
                obj.display(obj.root);
                break;

            case 3:
                obj.smallest();
                break;

            case 4:
                obj.highest();
                break;

            case 5:
                obj.mirror(obj.root);
                cout << "\nTree mirrored successfully. Inorder sequence of mirrored tree:";
                obj.display(obj.root); // Show the mirrored tree
                break;

            case 6:
                cout << "\nHeight of the tree: " << obj.height(obj.root);
                break;
            
            case 7:
                cout << "\nEnter element to search: ";
                cin >>key;
                if (obj.search(obj.root, key)) {
                    cout << key << " found in the tree.";
                } else {
                    cout << key << " not found in the tree.";
                }
                break;
            case 8:
                cout << "\nExiting program.";
                break;

            default:
                cout << "\nInvalid choice. Please try again.";
                break;
        }
    } while (choice != 8);

    return 0;
}
