#include <iostream>

using namespace std;

class AVLNode
{
public:
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

int getHeight(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalanceFactor(AVLNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
        return getHeight(node->left) - getHeight(node->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode *rotateRight(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode *rotateLeft(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode *insert(AVLNode *root, int data)
{
    if (root == nullptr)
        return new AVLNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data)
        return rotateRight(root);

    if (balanceFactor < -1 && data > root->right->data)
        return rotateLeft(root);

    if (balanceFactor > 1 && data > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balanceFactor < -1 && data < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorderTraversal(AVLNode *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    AVLNode *root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of the AVL tree: ";
    inorderTraversal(root);

    return 0;
}