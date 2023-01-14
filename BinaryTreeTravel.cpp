#include <iostream>
using namespace std;

// Узел бинарного дерева
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Создание узла
Node* create_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Префиксный обход
void preorder_traversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Инфиксный обход
void inorder_traversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

// Постфиксный обход
void postorder_traversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    cout << "Префиксный обход: ";
    preorder_traversal(root);
    cout << endl;

    cout << "Инфиксный обход: ";
    inorder_traversal(root);
    cout << endl;

    cout << "Постфиксный обход: ";
    postorder_traversal(root);
    cout << endl;

    return 0;
}