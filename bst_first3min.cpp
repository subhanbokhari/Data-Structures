#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:
    Node *root;
    int min1, min2, min3;

    BST()
    {
        root = nullptr;
        min1 = min2 = min3 = 1000;
    }

    void insert(int value, Node *root)
    {
        if (value < root->data)
        {
            if (root->left == nullptr)
            {
                root->left = new Node(value);
            }
            else
            {
                insert(value, root->left);
            }
        }
        else if (value > root->data)
        {
            if (root->right == nullptr)
            {
                root->right = new Node(value);
            }
            else
            {
                insert(value, root->right);
            }
        }
    }

    void findFirstThreeMin(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        findFirstThreeMin(root->left);

        if (root->data < min1)
        {
            min3 = min2;
            min2 = min1;
            min1 = root->data;
        }
        else if (root->data < min2)
        {
            min3 = min2;
            min2 = root->data;
        }
        else if (root->data < min3)
        {
            min3 = root->data;
        }

        findFirstThreeMin(root->right);
    }
};

int main()
{
    BST bst;
    bst.root = new Node(0);
    bst.insert(10, bst.root);
    bst.insert(2, bst.root);
    bst.insert(8, bst.root);
    bst.insert(4, bst.root);
    bst.insert(1, bst.root);
    bst.insert(9, bst.root);
    bst.insert(7, bst.root);
    bst.insert(3, bst.root);
    bst.insert(6, bst.root);

    bst.findFirstThreeMin(bst.root);
    cout << "First three minimum values in the BST are: " << bst.min1 << ", " << bst.min2 << ", " << bst.min3 << endl;

    return 0;
}