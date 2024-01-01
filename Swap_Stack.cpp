#include <iostream>
using namespace std;
class Stack
{
    int top;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[size];
    }
    ~Stack()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            cout << "Stack is full" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int val)
    {
        if (!isFull())
        {
            top++;
            arr[top] = val;
            cout << "Element: " << val << " is pushed" << endl;
        }
    }
    int pop()
    {
        int r;
        if (!isEmpty())
        {
            cout << "Element: " << arr[top] << " is popped" << endl;
            r = arr[top];
            top--;
        }
        return r;
    }
    void peek()
    {
        if (!isEmpty())
        {
            cout << "Peeking into the stack (accessing top element)" << endl;
            cout << arr[top] << endl;
        }
    }
    void display()
    {
        if (!isEmpty())
        {
            cout << "Stack elements: " << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s1(2);
    Stack s2(2);

    s1.push(2);
    s1.push(5);
    s1.display();

     s1.push(2);
     s1.push(5);
     s1.display();
     int rep = s1.pop();
     int rep2 = s1.pop();
     s1.push(rep);
     s1.push(rep2);
     s1.display();
}
