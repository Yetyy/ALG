#include <iostream>
using namespace std;

// ���� ��������� ������
struct Node {
    int data;
    Node* left;
    Node* right;
};

// �������� ����
Node* create_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// ���������� �����
void preorder_traversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// ��������� �����
void inorder_traversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

// ����������� �����
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

    cout << "���������� �����: ";
    preorder_traversal(root);
    cout << endl;

    cout << "��������� �����: ";
    inorder_traversal(root);
    cout << endl;

    cout << "����������� �����: ";
    postorder_traversal(root);
    cout << endl;

    return 0;
}