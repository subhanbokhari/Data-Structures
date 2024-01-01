#include <iostream>

#define MAX_SIZE 100

using namespace std;

class Queue
{
private:
    int data[MAX_SIZE];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enqueue(int value)
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
            rear = (rear + 1) % MAX_SIZE;
        }

        data[rear] = value;
        cout << value << " enqueued to the queue.\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue element.\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }

        return data[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (i != rear)
        {
            cout << data[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << data[i] << "\n";
    }
};

int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    cout << "Front element: " << queue.getFront() << "\n";

    queue.dequeue();
    queue.dequeue();

    queue.display();

    return 0;
}