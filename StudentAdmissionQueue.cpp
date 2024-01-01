#include <iostream>
#include <cstdlib>

using namespace std;

class Student
{
public:
    string name;
    int merit;

    Student(string studentName, int studentMerit) : name(studentName), merit(studentMerit) {}
};

class Node
{
public:
    Student student;
    Node *next;

    Node(Student s) : student(s), next(nullptr) {}
};

class AdmissionQueue
{
private:
    Node *front;
    Node *rear;

public:
    AdmissionQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(Student student)
    {
        Node *newNode = new Node(student);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    int getSize()
    {
        int size = 0;
        Node *temp = front;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    Student getFrontStudent()
    {
        return front->student;
    }
};

int getRandomQueue()
{
    return rand() % 3;
}

void displayQueueStatus(AdmissionQueue queues[], int numQueues)
{
    cout << "\nQueue Status:\n";
    for (int i = 0; i < numQueues; ++i)
    {
        cout << "Queue " << i + 1 << ": " << queues[i].getSize() << " students\n";
    }
}

int main()
{
    int numQueues = 3;
    AdmissionQueue queues[numQueues];

    while (true)
    {
        cout << "1. Add Student to Queue\n";
        cout << "2. Process Admissions\n";
        cout << "3. Check Queue Status\n";
        cout << "4. See who is next\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string studentName;
            int studentMerit;

            cout << "Enter student name: ";
            cin >> studentName;
            cout << "Enter student merit: ";
            cin >> studentMerit;

            int randomQueue = getRandomQueue();
            queues[randomQueue].enqueue(Student(studentName, studentMerit));

            cout << "Student added to Queue " << randomQueue + 1 << endl;
        }
        else if (choice == 2)
        {
            for (int i = 0; i < numQueues; ++i)
            {
                cout << "\nProcessing Queue " << i + 1 << ":\n";
                while (!queues[i].isEmpty())
                {
                    Student currentStudent = queues[i].getFrontStudent();
                    queues[i].dequeue();

                    cout << "Processing " << currentStudent.name << "'s admission... ";
                    if (currentStudent.merit > 50)
                    {
                        cout << "Admitted successfully\n";
                    }
                    else
                    {
                        cout << "Not admitted due to low merit.\n";
                    }
                }
            }
        }
        else if (choice == 3)
        {
            displayQueueStatus(queues, numQueues);
        }
        else if (choice == 4)
        {
            int queueNumber;
            cout << "Enter queue number: ";
            cin >> queueNumber;

            if (queueNumber >= 1 && queueNumber <= numQueues)
            {
                if (!queues[queueNumber - 1].isEmpty())
                {
                    Student nextStudent = queues[queueNumber - 1].getFrontStudent();
                    cout << "Next student in Queue " << queueNumber << ": " << nextStudent.name << endl;
                }
                else
                {
                    cout << "Queue " << queueNumber << " is empty.\n";
                }
            }
            else
            {
                cout << "Invalid queue number.\n";
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting the program.\n";
            exit(0);
        }
        else
        {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}