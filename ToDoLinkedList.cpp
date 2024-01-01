#include <iostream>
using namespace std;

struct node
{
    string tasks;
    bool status;
    bool completed;
    node *next;
    node *prev;
};

class list
{
private:
    node *head;
    node *tail;

public:
    list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void delet()
    {
        node *current = head;
        while (current != nullptr)
        {
            node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        cout << "All tasks deleted!" << endl;
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        int orderChoice;
        cout << "Choose the order to display tasks:" << endl;
        cout << "1 - Ascending order (Least priority to Most priority)" << endl;
        cout << "2 - Descending order (Most priority to Least priority)" << endl;
        cout << "Enter your choice: ";
        cin >> orderChoice;

        node *current;

        if (orderChoice == 1) // Ascending order
        {
            current = head;
            cout << "Tasks (Ascending Order)" << endl;
            while (current != nullptr)
            {
                cout << "Task: " << current->tasks << ", Priority: " << current->status << ", Completed: " << (current->completed ? "Yes" : "No") << endl;
                current = current->next;
            }
        }
        else if (orderChoice == 2) // Descending order
        {
            current = tail;
            cout << "Tasks (Descending Order)" << endl;
            while (current != nullptr)
            {
                cout << "Task: " << current->tasks << ", Priority: " << current->status << ", Completed: " << (current->completed ? "Yes" : "No") << endl;
                current = current->prev;
            }
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            return;
        }
    }

    void add()
    {
        string replace;
        int choice2;
        node *newNode = new node;
        cout << "Enter tasks for New Node: ";
        cin >> newNode->tasks;
        cout << "Enter the Status of the Task (0-Low, 1-High): ";
        cin >> newNode->status;

        cout << "1) - Top Priority" << endl
             << "2) - Least Priority" << endl
             << "3) - Specify Priority" << endl;
        cin >> choice2;

        newNode->completed = false;
        newNode->prev = nullptr;

        if (choice2 == 1)
        {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            if (tail == nullptr)
            {
                tail = newNode;
            }
        }
        else if (choice2 == 2)
        {
            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }
        else if (choice2 == 3)
        {
            int position;
            cout << "Please Enter the position where you want to add it to (1 - " << count() + 1 << "): ";
            cin >> position;

            if (position <= 0 || position > count() + 1)
            {
                cout << "Invalid position. Position should be between 1 and " << count() + 1 << "." << endl;
                delete newNode;
                return;
            }

            if (position == 1)
            {
                newNode->next = head;
                if (head != nullptr)
                    head->prev = newNode;
                head = newNode;
            }
            else if (position == count() + 1)
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            else
            {
                node *temp = head;
                int count = 1;
                while (temp != nullptr && count < position - 1)
                {
                    temp = temp->next;
                    count++;
                }

                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
            }
        }
        else
        {
            cout << "Invalid choice. Task not addedHere's the continuation of the modified code" << endl;
            delete newNode;
            return;
        }

        cout << "Task added!" << endl;
    }

    void markCompleted()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty!" << endl;
            return;
        }

        string task;
        cout << "Enter the task to mark as completed: ";
        cin >> task;

        node *temp = head;
        bool markedCompleted = false;
        while (temp != nullptr)
        {
            if (temp->tasks == task)
            {
                temp->completed = true;
                markedCompleted = true;
            }

            temp = temp->next;
        }

        if (markedCompleted)
            cout << "Task marked as completed!" << endl;
        else
            cout << "Task not found in the list." << endl;
    }

    int count()
    {
        int count = 0;
        node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    list l;
    int choice;

    while (true)
    {
        cout << "\n1 - Delete" << endl;
        cout << "2 - Print" << endl;
        cout << "3 - Add" << endl;
        cout << "4 - Mark Task Completed" << endl;
        cout << "5 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            l.delet();
            break;
        case 2:
            l.print();
            break;
        case 3:
            l.add();
            break;
        case 4:
            l.markCompleted();
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}