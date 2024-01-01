#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insert(int value, int position)
    {
        Node *newNode = new Node;
        newNode->data = value;

        if (position == 1)
        {
            if (head == nullptr)
            {
                head = newNode;
                newNode->next = head;
            }
            else
            {
                Node *current = head;
                while (current->next != head)
                {
                    current = current->next;
                }
                current->next = newNode;
                newNode->next = head;
                head = newNode;
            }
        }
        else
        {
            Node *current = head;
            int count = 1;

            while (count < position - 1 && current->next != head)
            {
                current = current->next;
                count++;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;
        int count = 1;

        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
            if (current == head)
            {
                cout << "Position not found." << endl;
                return;
            }
        }

        if (previous == nullptr)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
    }

    void update(int position, int newValue)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        int count = 1;

        while (count < position)
        {
            current = current->next;
            count++;
            if (current == head)
            {
                cout << "Position not found." << endl;
                return;
            }
        }

        current->data = newValue;
    }

    bool isPalindrome()
    {
        if (head == nullptr)
        {
            return false;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = slow->next;
        slow->next = head;

        Node *prev = nullptr;
        Node *next = nullptr;
        Node *current = secondHalf;

        while (current != head)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        secondHalf = prev;

        Node *list1 = head;
        Node *list2 = secondHalf;

        while (list1 != head && list2 != head)
        {
            if (list1->data != list2->data)
            {
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }

        return true;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;

        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main()
{
    CircularLinkedList list;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert a value at a specific position\n";
        cout << "2. Delete a value at a specific position\n";
        cout << "3. Update a value at a specific position\n";
        cout << "4. Check if the linked list is a palindrome\n";
        cout << "5. Display the linked list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value, position;
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the position to insert: ";
            cin >> position;
            list.insert(value, position);
            break;
        case 2:
            int deletePosition;
            cout << "Enter the position to delete: ";
            cin >> deletePosition;
            list.remove(deletePosition);
            break;
        case 3:
            int updatePosition, newValue;
            cout << "Enter the position to update: ";
            cin >> updatePosition;
            cout << "Enter the new value: ";
            cin >> newValue;
            list.update(updatePosition, newValue);
            break;
        case 4:
            if (list.isPalindrome())
            {
                cout << "The linked list is a palindrome." << endl;
            }
            else
            {
                cout << "The linked list is not a palindrome." << endl;
            }
            break;
        case 5:
            cout << "Linked List: ";
            list.display();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}