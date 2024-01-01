#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    string *arr;

public:
    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        arr = new string[size];
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (((rear + 1) % size) == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(string val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        cout << "Enqueued: " << val << endl;
    }
    void dequeue()
    {
        string val = arr[front];
        if (!isEmpty())
        {
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            cout << "Dequeued: " << val << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }
    void getFront()
    {
        cout << "The next in queue is " << arr[front] << endl;
    }
    void display()
    {
        cout << "Queue elements:" << endl;
        if (isEmpty())
        {
            return;
        }
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
    void menu()
    {
        int option = 0;
        while (option != 5)
        {
            cout << "Enter an option" << endl;
            cout << "1.Enter a patient in the waiting queue" << endl;
            cout << "2.Send next patient to the doctor." << endl;
            cout << "3.See who's next" << endl;
            cout << "4.Display all the patients in the queue" << endl;
            cout << "5.Exit" << endl;
            cin >> option;

            if (option == 1)
            {
                string n;
                cout << "Enter the name of the patient" << endl;
                cin >> n;
                enqueue(n);
            }
            if (option == 2)
            {
                dequeue();
            }
            if (option == 3)
            {
                getFront();
            }
            if (option == 4)
            {
                display();
            }
            if (option == 5)
            {
                exit;
            }
        }
    }
};

int main()
{
    int people;
    cout << "Enter the number of seats in the wating area:" << endl;
    cin >> people;
    Queue q(people);
    q.menu();
}