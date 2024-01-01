#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class list
{
private:
    node *head;

public:
    list()
    {
        head = nullptr;
    }

    void add(int data, node *current = nullptr)
    {
        if (current == nullptr)
        {
            // If the list is empty, create a new node and make it the head
            head = new node;
            head->data = data;
            head->next = nullptr;
        }
        else if (current->next == nullptr)
        {
            // Create a new node at the end of the list
            current->next = new node;
            current->next->data = data;
            current->next->next = nullptr;
        }
        else
        {
            // Recursive call to traverse the list
            add(data, current->next);
        }
    }

    void print(node *current = nullptr)
    {
        if (current == nullptr)
        {
            current = head; // Start from the head if no current node is provided
        }

        if (current == nullptr)
        {
            cout << "Empty Linked List!" << endl;
        }
        else
        {
            cout << current->data << " || ";
            print(current->next); // Recursive call to print the next node
        }
    }

    void options()
    {
        int choice = 0;
        while (choice != 5)
        {
            cout << "Select the Required Action:" << endl;
            cout << "1. Get" << endl
                 << "2. Print" << endl
                 << "3. Remove" << endl
                 << "4. Add" << endl
                 << "5. End" << endl;
            cin >> choice;

            switch (choice)
            {
                // case 1:
                //     break;
            case 2:
                print();
                break;
                // case 3:
                //     int key;
                //     cout << "Enter the element to remove: ";
                //     cin >> key;
                //     delet(key);
                //     break;
            case 4:
                int input;
                cout << "What do you want to input??" << endl;
                cin >> input;
                add(input);
                break;
            case 5:
                cout << "Ending the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main()
{
    list l1;
    l1.options();

    return 0;
}