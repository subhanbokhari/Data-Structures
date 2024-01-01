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
    node *temp;
    node *temp2;

public:
    list()
    {
        head = temp = temp2 = nullptr;
    }

    ~list()
    {
        // Destructor code if needed
    }

    void search()
    {
        // Search function code
    }

    void delet()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty!" << endl;
            return;
        }

        int key;
        cout << "Enter the element to remove: ";
        cin >> key;

        char choice;
        cout << "Delete single occurrence (Y/N)? ";
        cin >> choice;

        bool deleteSingleOccurrence = (choice == 'Y' || choice == 'y');

        bool deleted = false; // Flag to keep track if any deletion occurred

        // Check if the head node matches the key
        while (head != nullptr && head->data == key && (deleteSingleOccurrence || !deleted))
        {
            temp = head;
            head = head->next;
            delete temp;
            deleted = true;
        }

        temp = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->next->data == key && (deleteSingleOccurrence || !deleted))
            {
                temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                deleted = true;
            }
            else
            {
                temp = temp->next;
            }
        }

        if (deleted)
            cout << "Deletion completed!" << endl;
        else
            cout << "Element not found in the list." << endl;
    }

    void print()
    {
        if (head != nullptr)
        {
            temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << "|";
                temp = temp->next;
            }
        }
        else
        {
            cout << "Linked List is Empty!" << endl;
        }
    }

    void add()
    {
        if (head == nullptr)
        {
            head = new node;
            cout << "Please Enter Data for First Element: ";
            cin >> head->data;
            head->next = nullptr;
        }
        else
        {
            int key;
            temp = head;
            cout << "In Which Node Do You Want to Insert? ";
            cin >> key;
            while (temp != nullptr)
            {
                if (temp->data == key)
                {
                    cout << "Found!" << endl;
                    temp2 = new node;
                    cout << "Enter Data for New Node: ";
                    cin >> temp2->data;
                    temp2->next = temp->next;
                    temp->next = temp2;
                    break; // Exit the loop after adding the node
                }
                temp = temp->next;
            }

            if (temp == nullptr)
            {
                cout << "Key not found in the linked list" << endl;
            }
        }
    }

    void options()
    {
        int choice;
        while (choice != 10)
        {
            cout << "Select the Required Action:" << endl;
            cout << "1. Get" << endl
                 << "2. Print" << endl
                 << "3. Remove" << endl
                 << "4. Add" << endl
                 << "5. End" << endl;
            cin >> choice;

            // Perform actions based on the selected choice
            switch (choice)
            {
            case 1:
                // Code for 'Get' action
                break;
            case 2:
                print();
                break;
            case 3:
                delet(); // Call the delet function
                break;
            case 4:
                add(); // Call the add function
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