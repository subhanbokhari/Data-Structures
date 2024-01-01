#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree
{
private:
    Node *root;

    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }
        else
        {
            return node; // Duplicate values are not allowed
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && value < node->left->data)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balanceFactor < -1 && value > node->right->data)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balanceFactor > 1 && value > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balanceFactor < -1 && value < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void displayInorder()
    {
        inorderTraversal(root);
    }
};

int main()
{
    AVLTree avlTree;

    avlTree.insert(10);
    avlTree.insert(5);
    avlTree.insert(15);
    avlTree.insert(3);
    avlTree.insert(7);
    avlTree.insert(20);

    cout << "Inorder traversal of AVL tree: ";
    avlTree.displayInorder();

    return 0;
}