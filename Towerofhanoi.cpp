#include <iostream>
#include <string>

using namespace std;

struct Stack
{
    int data[100];
    int top;

    Stack()
    {
        top = -1;
    }

    Stack(int size)
    {
        top = -1;
        if (size > 100)
        {
            cout << "Stack size exceeds the limit of 100. Setting size to 100." << endl;
            size = 100;
        }
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
        top = size - 1;
    }

    void push(int value)
    {
        if (top >= 99)
        {
            cout << "Stack overflow. Cannot push element." << endl;
            return;
        }
        data[++top] = value;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow. Cannot pop element." << endl;
            return -1;
        }
        return data[top--];
    }

    int peek() const
    {
        if (top < 0)
        {
            cout << "Stack is empty. No element to peek." << endl;
            return -1;
        }
        return data[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }
};

void displayMove(int disk, const string &source, const string &destination)
{
    cout << "Move disk " << disk << " from rod " << source << " to rod " << destination << endl;
}

void modifiedTowerOfHanoi(int numDisks)
{
    Stack stackA(numDisks), stackB(numDisks), stackC(numDisks);

    for (int i = numDisks; i > 0; --i)
    {
        stackA.push(i);
    }

    string source = "A", auxiliary = "B", destination = "C";

    int totalMoves = 0;

    if (numDisks % 2 == 0)
    {
        swap(auxiliary, destination);
    }

    for (int move = 1; move <= (1 << numDisks) - 1; ++move)
    {
        if (move % 3 == 1)
        {
            if ((source == "A" && destination == "C") || (source == "C" && destination == "A"))
            {
                displayMove(stackA.peek(), source, destination);
                stackC.push(stackA.pop());
            }
            else if ((source == "A" && destination == "B") || (source == "B" && destination == "A"))
            {
                displayMove(stackA.peek(), source, auxiliary);
                stackB.push(stackA.pop());
            }
            else if ((source == "B" && destination == "C") || (source == "C" && destination == "B"))
            {
                displayMove(stackB.peek(), auxiliary, destination);
                stackC.push(stackB.pop());
            }
        }
        else if (move % 3 == 2)
        {
            if ((source == "A" && auxiliary == "C") || (source == "C" && auxiliary == "A"))
            {
                displayMove(stackA.peek(), source, destination);
                stackC.push(stackA.pop());
            }
            else if ((source == "A" && auxiliary == "B") || (source == "B" && auxiliary == "A"))
            {
                displayMove(stackA.peek(), source, auxiliary);
                stackB.push(stackA.pop());
            }
            else if ((source == "B" && auxiliary == "C") || (source == "C" && auxiliary == "B"))
            {
                displayMove(stackB.peek(), auxiliary, destination);
                stackC.push(stackB.pop());
            }
        }
        else
        {
            if ((auxiliary == "A" && destination == "C") || (auxiliary == "C" && destination == "A"))
            {
                displayMove(stackB.peek(), auxiliary, destination);
                stackC.push(stackB.pop());
            }
            else if ((auxiliary == "A" && destination == "B") || (auxiliary == "B" && destination == "A"))
            {
                displayMove(stackA.peek(), source, auxiliary);
                stackB.push(stackA.pop());
            }
            else if ((auxiliary == "B" && destination == "C") || (auxiliary == "C" && destination == "B"))
            {
                displayMove(stackB.peek(), auxiliary, destination);
                stackC.push(stackB.pop());
            }
        }

        totalMoves++;
    }

    cout << "Total moves: " << totalMoves << endl;
}

int main()
{
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    modifiedTowerOfHanoi(numDisks);

    return 0;
}