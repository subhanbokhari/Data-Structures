#include <iostream>
using namespace std;

class Node
{
public:
    string val;
    Node *next;
    string location;

    Node(string val, string location)
    {
        this->val = val;
        this->location = location;
        next = nullptr;
    }
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(string val, string location)
    {
        Node *temp = new Node(val, location);
        temp->next = top;
        top = temp;
    }

    string pop()
    {
        if (isEmpty())
        {
            return "Stack is empty!";
        }
        else
        {
            string tempo = top->val;
            Node *temp = top;
            top = top->next;
            delete temp;
            return tempo;
        }
    }
};

class Queue
{
public:
    int front;
    int rear;
    int size;
    string *arr;

    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        arr = new string[size];
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void enqueue(string val)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue element.\n";
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = val;
        cout << val << " enqueued to the queue.\n";
    }

    string dequeue()
    {
        if (isEmpty())
        {
            return "Queue is empty. Cannot dequeue element.\n";
        }
        else if (front == rear)
        {
            string deq = arr[front];
            front = rear = -1;
            return deq;
        }
        else
        {
            string deq = arr[front];
            front = (front + 1) % size;
            return deq;
        }
    }

    void getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            cout << arr[front];
        }
    }
};

int main()
{
    int choice;

    // Set up the stack for encounters
    Stack encounters;

    Queue mansionQueue(6);
    mansionQueue.enqueue("The Gateway to Darkness");
    mansionQueue.enqueue("The Creeping Corridor");
    mansionQueue.enqueue("The Abandoned Lounge");
    mansionQueue.enqueue("The Haunted Gallery");
    mansionQueue.enqueue("The Shadowed Library");
    mansionQueue.enqueue("The Broken Window");

    cout << "Start exploring the mansion? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;

    if (choice == 1)
    {
        while (!mansionQueue.isEmpty())
        {
            int choice;
            string enc;

            cout << "Currently at: " << mansionQueue.arr[mansionQueue.front] << endl;

            cout << "Did you encounter a ghost or an evil spirit?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> choice;

            if (choice == 1)
            {
                cout << "Whatdid you see?" << endl;
                cin >> enc;
                encounters.push(enc, mansionQueue.arr[mansionQueue.front]);
            }

            mansionQueue.dequeue();
        }

        cout << "Yayyy, you escaped safe and sound!" << endl;
        cout << "Most recent ghosts/evil spirits encounters:" << endl;

        while (!encounters.isEmpty())
        {
            cout << encounters.top->val << ": " << encounters.top->location << endl;
            encounters.pop();
        }
    }
    else
    {
        cout << "See you next time!" << endl;
        return 0;
    }
}