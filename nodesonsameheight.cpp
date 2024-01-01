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

int countNodesAtHeight(Node *root, int height, int currentHeight)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (currentHeight == height)
    {
        return 1;
    }

    int leftCount = countNodesAtHeight(root->left, height, currentHeight + 1);
    int rightCount = countNodesAtHeight(root->right, height, currentHeight + 1);

    return leftCount + rightCount;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    int height = 2;
    int nodeCount = countNodesAtHeight(root, height, 1);
    cout << "Number of nodes at height " << height << " is: " << nodeCount << endl;

    return 0;
}