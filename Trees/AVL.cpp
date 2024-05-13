#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int getheight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int balancingFactor(Node* root) {
    return getheight(root->left) - getheight(root->right);
}

Node* rightRotate(Node* root) {
    Node* child = root->left;
    Node* rightChild = child->right;

    child->right = root;
    root->left = rightChild;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

Node* leftRotate(Node* root) {
    Node* child = root->right;
    Node* leftChild = child->left;

    child->left = root;
    root->right = leftChild;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->data = key;
        temp->left = temp->right = NULL;
        temp->height = 1;  // Initialize height
        return temp;
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    else {
        return root;
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    int balance = balancingFactor(root);

    if (balance > 1 && key < root->left->data) {
        return rightRotate(root);
    }
    else if (balance < -1 && key > root->right->data) {
        return leftRotate(root);
    }
    else if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 100);
    root = insert(root, 170);
    root = insert(root, 150);
    root = insert(root, 55);
    root = insert(root, 98);
    root = insert(root, 65);
    root = insert(root, 70);
    root = insert(root, 120);
    root = insert(root, 11);
    root = insert(root, 59);
    root = insert(root, 86);
    root = insert(root, 75);

    cout << "Preorder traversal:" << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder traversal:" << endl;
    postorder(root);
    cout << endl;

    return 0;
}
