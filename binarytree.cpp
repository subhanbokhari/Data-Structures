#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *right;
    node *left;

    node(int info)
    {
        right = left = nullptr;
        this->info = info;
    }
};

class tree
{
public:
    node *root;

    node *add(int data, node *root)
    {
        if (root == nullptr)
        {
            root = new node(data);
            root->left = root->right = nullptr;
            return root;
        }
        if (data > root->info)
        {
            root->right = add(data, root->right);
        }
        if (data < root->info)
        {
            root->left = add(data, root->left);
        }
        return root;
    }

    node *del(int key, node *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (key > root->info)
        {
            root->right = del(key, root->right);
        }
        else if (key < root->info)
        {
            root->left = del(key, root->left);
        }
        else
        {
            if (root->left == nullptr)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }

            node *minValueNode = findMinValueNode(root->right);
            root->info = minValueNode->info;
            root->right = del(minValueNode->info, root->right);
        }

        return root;
    }

    node *findMinValueNode(node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->left != nullptr)
        {
            return findMinValueNode(root->left);
        }

        return root;
    }

    void inOrder(node *root)
    {
        int min1=-1;
        int min1=-1;
        int min1=-1;
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);
        
        inOrder(root->right);
    }
};

int main()
{
    node *root = new node(5);
    tree t1;
    t1.root = t1.add(10, root);
    t1.root = t1.add(2, root);
    t1.root = t1.add(8, root);
    t1.root = t1.add(4, root);
    t1.root = t1.add(1, root);
    t1.root = t1.add(9, root);
    t1.root = t1.add(7, root);
    t1.root = t1.add(3, root);
    t1.root = t1.add(6, root);

    t1.inOrder(root);
    cout << "----------------------" << endl;
    cout << "----------------------" << endl;

    t1.del(5, root);
    t1.inOrder(root);

    return 0;
}