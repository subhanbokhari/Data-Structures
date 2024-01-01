#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Book
{
    int isbn;
    string author;
    string title;
    string genre;
    Date publicationDate;
};

struct Node
{
    Book book;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void addBook(const Book &book)
    {
        Node *newNode = new Node;
        newNode->book = book;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        sortListByPublicationYear();

        cout << "Book added successfully!" << endl;
    }

    void sortListByPublicationYear()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node *current = head;
        Node *sortedHead = nullptr;
        Node *sortedTail = nullptr;

        while (current != nullptr)
        {
            Node *nextNode = current->next;
            insertNodeByPublicationYear(current, sortedHead, sortedTail);
            current = nextNode;
        }

        head = sortedHead;
    }

    void insertNodeByPublicationYear(Node *node, Node *&sortedHead, Node *&sortedTail)
    {
        if (sortedHead == nullptr)
        {
            sortedHead = node;
            sortedTail = node;
            node->prev = nullptr;
            node->next = nullptr;
        }
        else if (node->book.publicationDate.year < sortedHead->book.publicationDate.year)
        {
            node->prev = nullptr;
            node->next = sortedHead;
            sortedHead->prev = node;
            sortedHead = node;
        }
        else if (node->book.publicationDate.year >= sortedTail->book.publicationDate.year)
        {
            node->next = nullptr;
            node->prev = sortedTail;
            sortedTail->next = node;
            sortedTail = node;
        }
        else
        {
            Node *current = sortedHead;
            while (current->next != nullptr && current->next->book.publicationDate.year <= node->book.publicationDate.year)
            {
                current = current->next;
            }
            node->prev = current;
            node->next = current->next;
            current->next->prev = node;
            current->next = node;
        }
    }

    void searchByISBN(int isbn)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->book.isbn == isbn)
            {
                displayBook(current->book);
                return;
            }
            current = current->next;
        }
        cout << "Book not found." << endl;
    }

    void searchByTitle(const string &title)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->book.title == title)
            {
                displayBook(current->book);
                return;
            }
            current = current->next;
        }
        cout << "Book not found." << endl;
    }

    void displayBooks()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty!" << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            displayBook(current->book);
            current = current->next;
        }
    }

private:
    void displayBook(const Book &book)
    {
        cout << "ISBN: " << book.isbn << endl;
        cout << "Author: " << book.author << endl;
        cout << "Title: " << book.title << endl;
        cout << "Genre: " << book.genre << endl;
        cout << "Publication Date: " << book.publicationDate.day << "/" << book.publicationDate.month << "/" << book.publicationDate.year << endl;
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList bookList;

    while (true)
    {
        cout << "----- Book Management System -----" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Search by ISBN" << endl;
        cout << "3. Search by Title" << endl;
        cout << "4. Display all books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            Book newBook;
            cout << "Enter ISBN: ";
            cin >> newBook.isbn;

            cout << "Enter Author: ";
            cin >> newBook.author;

            cout << "Enter Title: ";
            cin >> newBook.title;

            cout << "Enter Genre: ";
            cin >> newBook.genre;

            cout << "Enter Publication Date (DD MM YYYY): ";
            cin >> newBook.publicationDate.day >> newBook.publicationDate.month >> newBook.publicationDate.year;

            bookList.addBook(newBook);
        }
        else if (choice == 2)
        {
            int isbn;
            cout << "Enter ISBN to search: ";
            cin >> isbn;
            bookList.searchByISBN(isbn);
        }
        else if (choice == 3)
        {
            string title;
            cout << "Enter Title to search: ";
            cin >> title;
            bookList.searchByTitle(title);
        }
        else if (choice == 4)
        {
            bookList.displayBooks();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}