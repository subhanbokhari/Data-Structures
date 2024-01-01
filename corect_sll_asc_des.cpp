#include <iostream>

struct node
{
    int val;
    node *next;
};

bool checkOrder(node *head, int size)
{
    int asc = 0;
    int dsc = 0;
    int no = 0;

    while (head->next != nullptr)
    {
        if (head->val < head->next->val)
        {
            asc++;
        }
        else if (head->val > head->next->val)
        {
            dsc++;
        }
        else
        {
            no++;
        }

        head = head->next;
    }

    if (asc == size - 1)
    {
        std::cout << "Ascending" << std::endl;
    }
    else if (dsc == size - 1)
    {
        std::cout << "Descending" << std::endl;
    }
    else
    {
        std::cout << "No Order" << std::endl;
    }

    return true;
}