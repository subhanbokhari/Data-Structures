#include <iostream>
using namespace std;

class ArrayList 
{
    int maxSize;
    int length;
    char* arr;
    char* curr;

public:
    ArrayList(int size) 
    {
        maxSize=size;
        length=0;
        arr=new char[maxSize];
        curr=NULL;
    }

    void start() 
    {
        curr=arr;
    }

    void tail() 
    {
        curr=arr+length-1;
    }

    void back() 
    {
        curr--;
    }

    void next() 
    {
        curr++;
    }

    void insert(int pos,char val) 
    {
        if (length==maxSize) 
        {
            cout << "List is full" << endl;
        } else if (pos<1 || pos>length+1) 
        {
            cout << "Invalid position" << endl;
        } else 
        {
            tail();
            for(int i=length;i>=pos;i--) 
            {
                *(curr+1)=*curr;
                back();
            }
            *(curr+1)=val;
            length++;
        }
    }

    void remove(int pos) 
    {
        if(pos<1 || pos>length) 
        {
            cout << "Invalid position" << endl;
        } else 
        {
            start();
            for (int i=1;i<pos;i++) 
            {
                next();
            }
            for (int i=pos;i<length;i++) 
            {
                *curr =*(curr+1);
                next();
            }
            length--;
        }
    }

    void printList() 
    {
        start();
        for(int i=0;i<length;i++) 
        {
            cout << *curr << " ";
            next();
        }
        cout << endl;
    }

    void search(char val) 
    {
        start();
        for (int i=0;i<length;i++) 
        {
            if(*curr==val) 
            {
                cout << "Element found at position: " << i+1 << endl;
                return;
            }
            next();
        }
        cout << "Element not found" << endl;
    }

    char get(int pos) 
    {
        if (pos<1 || pos>length) 
        {
            cout << "Invalid position" << endl;
            return '\0';
        } else 
        {
            start();
            for(int i=1;i<pos;i++) 
            {
                next();
            }
            return *curr;
        }
    }
};

#include <iostream>
using namespace std;

int main() {
    ArrayList l(6);
    int position;
    int choice;
    char element;

    l.insert(1,'e');
    l.insert(2,'f');
    l.insert(3,'a');
    l.insert(4,'b');
    l.insert(5,'i');
    l.insert(1,'r');

    cout << "Initial List: ";
    l.printList();

    while (true) 
    {
        cout << "\nMenu:\n";
        cout << "1. Add\n";
        cout << "2. Remove\n";
        cout << "3. Print List\n";
        cout << "4. Search\n";
        cout << "5. Get\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter the position where you want to add: ";
                cin >> position;
                cout << "Enter the element you want to add: ";
                cin >> element;
                l.insert(position,element);
                cout << "Element added.\n";
                break;
            case 2:
                cout << "Enter the position of the element you want to remove: ";
                cin >> position;
                l.remove(position);
                cout << "Element removed.\n";
                break;
            case 3:
                cout << "Current List: ";
                l.printList();
                break;
            case 4:
                cout << "Enter the element you want to search: ";
                cin >> element;
                l.search(element);
                break;
            case 5:
                cout << "Enter the position of the element you want to get: ";
                cin >> position;
                cout << "Element at position " << position << ": " << l.get(position) << "\n";
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}