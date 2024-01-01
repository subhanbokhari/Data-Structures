#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *next;

    Node(string name)
    {
        this->name = name;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue(string name)
    {
        Node *newNode = new Node(name);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return "";
        }

        Node *temp = front;
        string name = temp->name;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        return name;
    }
};

int main()
{
    Queue ticketSalesQueue;
    Queue rollerCoasterQueue;
    Queue motionRideQueue;
    Queue roundWheelQueue;

    int choice;
    string visitorName;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Enter visitor to Ticket Purchase Queue" << endl;
        cout << "2. Sell the Ticker to person in queue" << endl;
        cout << "3. Process all sold ticket queues" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter visitor name: ";
            cin >> visitorName;
            ticketSalesQueue.enqueue(visitorName);
        }
        if (choice == 2)
        {
            if (ticketSalesQueue.isEmpty())
            {
                cout << "No visitors in the ticket purchase queue" << endl;
            }
            else
            {
                visitorName = ticketSalesQueue.dequeue();
                cout << "Ticket sold to " << visitorName << endl;
                cout << "Select attraction (1. Roller Coaster, 2. Motion Ride, 3. Round Wheel): ";
                cin >> choice;
                if (choice == 1)
                {
                    rollerCoasterQueue.enqueue(visitorName);
                }
                if (choice == 2)
                {
                    motionRideQueue.enqueue(visitorName);
                }
                if (choice == 3)
                {
                    roundWheelQueue.enqueue(visitorName);
                }
                choice = 0;
            }
        }

        if (choice == 3)
        {
            cout << "Processing all queues..." << endl;
            while (!rollerCoasterQueue.isEmpty())
            {
                visitorName = rollerCoasterQueue.dequeue();
                cout << visitorName << " is enjoying the Roller Coaster" << endl;
            }
            while (!motionRideQueue.isEmpty())
            {
                visitorName = motionRideQueue.dequeue();
                cout << visitorName << " is enjoying the Motion Ride" << endl;
            }
            while (!roundWheelQueue.isEmpty())
            {
                visitorName = roundWheelQueue.dequeue();
                cout << visitorName << " is enjoying the Round Wheel" << endl;
            }
        }
        if (choice == 4)
        {
            cout << "Exiting..." << endl;
            break;
        }
        cout << endl;
    } while (choice != 4);

    return 0;
}