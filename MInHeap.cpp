#include <iostream>
#include <vector>
using namespace std;

class Patient
{
public:
    string name;
    int urgency;

    Patient(string name, int urgency)
    {
        this->name = name;
        this->urgency = urgency;
    }
};

class Heap
{
public:
    vector<Patient> htree;

    int getParent(int child)
    {
        return (child - 1) / 2;
    }

    int getLeft(int parent)
    {
        return 2 * parent + 1;
    }

    int getRight(int parent)
    {
        return 2 * parent + 2;
    }

    void swap(Patient *a, Patient *b)
    {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        while (node > 0 && htree[node].urgency < htree[getParent(node)].urgency)
        {
            swap(&htree[node], &htree[getParent(node)]);
            node = getParent(node);
        }
    }

    void heapifyDown(int node)
    {
        int left = getLeft(node);
        int right = getRight(node);
        int smallest = node;

        if (left < htree.size() && htree[left].urgency < htree[smallest].urgency)
        {
            smallest = left;
        }

        if (right < htree.size() && htree[right].urgency < htree[smallest].urgency)
        {
            smallest = right;
        }

        if (smallest != node)
        {
            swap(&htree[node], &htree[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(Patient patient)
    {
        htree.push_back(patient);
        int lastIndex = htree.size() - 1;
        heapifyUp(lastIndex);
    }

    void del()
    {
        if (htree.empty())
        {
            cout << "No appointments to delete." << endl;
            return;
        }

        cout << "Sending next patient to the doctor: " << htree[0].name << endl;

        htree[0] = htree.back();
        htree.pop_back();

        if (!htree.empty())
        {
            heapifyDown(0);
        }
    }

    void updateUrgency(string patientName, int newUrgency)
    {
        for (int i = 0; i < htree.size(); ++i)
        {
            if (htree[i].name == patientName)
            {
                htree[i].urgency = newUrgency;
                heapifyUp(i);
                heapifyDown(i);
                return;
            }
        }
        cout << "Patient not found." << endl;
    }

    void display()
    {
        if (htree.empty())
        {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++)
        {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
        cout << "----------------------" << endl;
    }
};

int main()
{
    Heap priorityQueue;

    while (true)
    {
        cout << "1. Make Appointment" << endl;
        cout << "2. Send Next Patient" << endl;
        cout << "3. Update Urgency" << endl;
        cout << "4. Show Appointments" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            int urgency;
            cout << "Enter patient's name: ";
            cin >> name;
            cout << "Enter urgency level: ";
            cin >> urgency;
            priorityQueue.insert(Patient(name, urgency));
            break;
        }
        if (choice == 2)
        {
            priorityQueue.del();
            break;
        }
        if (choice == 3)
        {
            string name;
            int newUrgency;
            cout << "Enter patient's name: ";
            cin >> name;
            cout << "Enter new urgency level: ";
            cin >> newUrgency;
            priorityQueue.updateUrgency(name, newUrgency);
            break;
        }
        if (choice == 4)
        {
            priorityQueue.display();
            break;
        }
        if (choice == 5)
        {
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
