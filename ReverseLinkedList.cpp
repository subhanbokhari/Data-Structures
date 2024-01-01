#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void reverseLinkedList(Node **head, int K, int n)
{
    if (*head == nullptr || (*head)->next == nullptr || K % n == 0)
    {
        return;
    }

    Node *current = *head;
    Node *newHead = nullptr;
    Node *prevTail = nullptr;
    int count = 0;

    while (current != nullptr)
    {
        Node *stack[K];
        int i = 0;

        while (current != nullptr && i < K)
        {
            stack[i] = current;
            current = current->next;
            i++;
        }

        if (i == K)
        {
            while (i > 0)
            {
                i--;
                Node *node = stack[i];
                if (newHead == nullptr)
                {
                    newHead = node;
                }
                node->next = current;
                node->prev = prevTail;
                if (prevTail != nullptr)
                {
                    prevTail->next = node;
                }
                if (current != nullptr)
                {
                    current->prev = node;
                }
                prevTail = node;
            }
        }
        else
        {
            prevTail->next = stack[0];
            stack[0]->prev = prevTail;
        }
    }

    *head = newHead;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int n;
    int k;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        Node *newNode = new Node();
        newNode->data = value;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    cout << "Enter the value for K" << endl;
    cin >> k;

    cout << "Original List: ";
    printList(head);

    reverseLinkedList(&head, k, n);

    cout << "Reversed List: ";
    printList(head);

    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}