#include <iostream>
using namespace std;

struct node
{
    int data;
    node *last;
    node *next;
};

class stack {
    private:
    node *head;
    node *temp;
    public:
    stack () {
        head = temp = nullptr;
    }
    void push()
    {
        if(head==nullptr)
        {
            head = new node;
            head->last = nullptr;
            head->next = nullptr;
            cout << "Input Value for First Node" << endl;
            cin >> head->data;
        }
        else if(head!=nullptr)
        {
            temp = new node;
            cout << "Input Value" << endl;
            cin >> temp->data;
            temp->last = head;
            temp->next = head->next;
            head->next = temp;
            head = temp;
        }
    }

    void pop()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        else if (head->last == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            head->last->next = head->next;
            if (head->next != nullptr)
                head->next->last = head->last;
            temp = head;
            head = head->last;
            delete temp;
        }
    }

    void print()
    {
        node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->last;
        }
        cout << endl;
    }

    void menu ()
    {
        int option;
        while(option!=4)
        {
            cout << "Select The Required Action." << endl
            << "1.Push" << endl
            << "2.Pop" << endl
            << "3.Print" << endl
            << "4.Exit" << endl;
        
            cin >> option;
            
            if(option==1)
            {
                push();
            }
            if(option==2)
            {
                pop();
            }
            if(option==3)
            {
                print();
            }
            if(option==4)
            {
                return;
            } 
        }

    }
};
int main()
{
    stack s;
    s.menu();

 return 0;
}