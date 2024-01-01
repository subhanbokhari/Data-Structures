#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

bool checkOrder(node *head, int size)
{
    int asc;
    int dsc;
    int no;

    if (head->val > head->next->val)
    {
        asc++;
    }
    if (head->val < head->next->val)
    {
        dsc++;
    }
    if (head->val < head->next->next->val && head->next->val < head->val)
    {
        no++;
    }
    else if (head->val > head->next->next->val && head->next->val > head->val)
    {
        no++;
    }
    if (head->next == nullptr)
    {
        return;
    }
    if (asc = size - 1)
    {
        cout << "Ascending" << endl;
    }
    if (dsc == size - 1)
    {
        cout << "Descending" << endl;
    }
    else
    {
        cout << "No Order" < endl;
    }
}

int main()
{

    return 0;
}