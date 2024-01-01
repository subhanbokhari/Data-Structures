#include <iostream>
#include <string>

using namespace std;

struct Node 
{
    string name;
    Node* next;
};

class CircularLinkedList 
{
private:
    Node* head;
    int size;

public:
    CircularLinkedList() 
    {
        head = nullptr;
        size = 0;
    }

    void insertNode(string name) 
    {
        Node* newNode = new Node;
        newNode->name = name;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void removeNode(Node* prevNode, Node* currentNode) 
    {
        if (size == 1) 
        {
            head = nullptr;
        } else if (currentNode == head) 
        {
            Node* temp = head;
            while (temp->next != head) 
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        } else {
            prevNode->next = currentNode->next;
            if (currentNode == head) 
            {
                head = currentNode->next;
            }
        }
        delete currentNode;
        size--;
    }

    void playRound() 
    {
    while (size > 1) 
    {
        Node* prevNode = nullptr;
        Node* currentNode = head;
        int counter = 1;

        while (counter < size) 
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
            counter++;
        }

        cout << "Player removed: " << currentNode->name << endl;
        removeNode(prevNode, currentNode);
    }

    cout << "Winner: " << head->name << endl;
}

    void displayPlayers() 
    {
        Node* temp = head;

        if (head == nullptr) 
        {
            cout << "No players in the game." << endl;
            return;
        }

        cout << "Current players: ";
        do 
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList game;

    string names[5];
    cout << "Enter the names of the players:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Player " << i + 1 << ": ";
        cin >> names[i];
        game.insertNode(names[i]);
    }

    char choice;
    do {
        cout << "Press any key to play the next round (or 'q' to quit): ";
        cin >> choice;

        game.playRound();
        game.displayPlayers();
    } while (choice != 'q');

    return 0;
}