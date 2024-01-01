#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void findThreeSmallest(TreeNode *root, int &smallestCount, int &firstSmallest, int &secondSmallest, int &thirdSmallest)
{
    if (root == nullptr || smallestCount == 3)
    {
        return;
    }

    findThreeSmallest(root->left, smallestCount, firstSmallest, secondSmallest, thirdSmallest);

    if (smallestCount == 0)
    {
        firstSmallest = root->val;
    }
    else if (smallestCount == 1)
    {
        secondSmallest = root->val;
    }
    else if (smallestCount == 2)
    {
        thirdSmallest = root->val;
    }

    smallestCount++;

    findThreeSmallest(root->right, smallestCount, firstSmallest, secondSmallest, thirdSmallest);
}

TreeNode *insertNode(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < root->val)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->val)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int main()
{
    // Create a BST
    TreeNode *root = nullptr;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    // Variables to store smallest values
    int smallestCount = 0;
    int firstSmallest = INT_MAX;
    int secondSmallest = INT_MAX;
    int thirdSmallest = INT_MAX;

    // Find three smallest values
    findThreeSmallest(root, smallestCount, firstSmallest, secondSmallest, thirdSmallest);

    // Print the three smallest values
    std::cout << "Three smallest values in the BST: " << firstSmallest << ", " << secondSmallest << ", " << thirdSmallest << std::endl;

    return 0;
}