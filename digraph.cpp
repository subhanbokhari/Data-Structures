#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node *next;

    node(char data)
    {
        this->data = data;
        next = nullptr;
    }
};

class vertex
{
    char data;
    node *head;

    void add(node *temp, char data)
    {
        temp = head;
        if (temp == nullptr)
        {
            temp = new node(data);
        }
        if (temp != nullptr)
        {
            if (temp->next != nullptr)
            {
                add(temp->next, data);
            }
        }
    }
};

int main()
{

    vertex v1[5];

    return 0;
}