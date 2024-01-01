#include <iostream>
#include <vector>
using namespace std;

class Employee
{
public:
	int employeeID;
	string name;
	float sales;
	float customerSatisfaction;
	float projectCompletion;
	float performanceScore;

	Employee(int employeeID, string name, float customerSatisfaction, float projectCompletion)
	{
		this->employeeID = employeeID;
		this->name = name;
		this->customerSatisfaction = customerSatisfaction;
		this->projectCompletion = projectCompletion;
	}

	void calculatePerformanceScore()
	{
		performanceScore = sales + customerSatisfaction + projectCompletion;
	}
};

class MaxHeap
{
public:
	vector<Employee> employeeHeap;

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

	void swap(Employee *a, Employee *b)
	{
		Employee temp = *a;
		*a = *b;
		*b = temp;
	}

	void heapifyUp(int node)
	{
		while (node > 0 && employeeHeap[node].performanceScore < employeeHeap[getParent(node)].performanceScore)
		{
			swap(&employeeHeap[node], &employeeHeap[getParent(node)]);
			node = getParent(node);
		}
	}

	void heapifyDown(int node)
	{
		int left = getLeft(node);
		int right = getRight(node);
		int largest = node;

		if (left < employeeHeap.size() && employeeHeap[left].performanceScore < employeeHeap[largest].performanceScore)
		{
			largest = left;
		}

		if (right < employeeHeap.size() && employeeHeap[right].performanceScore < employeeHeap[largest].performanceScore)
		{
			largest = right;
		}

		if (largest != node)
		{
			swap(&employeeHeap[node], &employeeHeap[largest]);
			heapifyDown(largest);
		}
	}

	void insertEmployee(Employee emp)
	{
		employeeHeap.push_back(emp);
		int lastIndex = employeeHeap.size() - 1;
		heapifyUp(lastIndex);
	}

	void getTopRankingEmployee()
	{
	}

	void updatePerformance(string employee, float newSales, float newCS, float newPCE)
	{
		for (int i = 0; i < employeeHeap.size(); ++i)
		{
			if (employeeHeap[i].name == employee)
			{
				employeeHeap[i].performanceScore += newSales;
				heapifyUp(i);
				heapifyDown(i);
				return;
			}
		}
		cout << "Patient not found." << endl;
	}

	void displayEmployees()
	{
		if (employeeHeap.empty())
		{
			cout << "No Employees." << endl;
			return;
		}
		cout << "Employee Rankings:" << endl;
		for (const Employee &emp : employeeHeap)
		{
			cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
		}
	}
};

int main()
{
	MaxHeap employeeMaxHeap;

	while (true)
	{
		cout << "\nMenu:\n";
		cout << "1. Enter a new employee details\n";
		cout << "2. Get the top-ranking employee\n";
		cout << "3. Update an employee's scores\n";
		cout << "4. Display employee rankings\n";
		cout << "5. Exit\n";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int id;
			string name;
			float sales, cs, pce;
			cout << "Enter Employee ID: ";
			cin >> id;
			cin.ignore(); // Clear newline character from the buffer
			cout << "Enter Employee Name: ";
			getline(cin, name);
			cout << "Enter Sales (in percentage): ";
			cin >> sales;
			cout << "Enter Customer Satisfaction (in percentage): ";
			cin >> cs;
			cout << "Enter Project Completion Efficiency (in percentage): ";
			cin >> pce;

			Employee newEmployee(id, name, cs, pce);
			newEmployee.calculatePerformanceScore();
			employeeMaxHeap.insertEmployee(newEmployee);
			cout << "Employee added successfully!" << endl;
			break;
		}
		case 2:
		{
			employeeMaxHeap.getTopRankingEmployee();
			break;
		}
		case 3:
		{
			string emp;
			float newSales, newCS, newPCE;
			cout << "Enter Employee Name to update scores: ";
			cin >> emp;
			cout << "Enter new Sales (in percentage): ";
			cin >> newSales;
			cout << "Enter new Customer Satisfaction (in percentage): ";
			cin >> newCS;
			cout << "Enter new Project Completion Efficiency (in percentage): ";
			cin >> newPCE;
			employeeMaxHeap.updatePerformance(emp, newSales, newCS, newPCE);
			break;
		}
		case 4:
		{
			employeeMaxHeap.displayEmployees();
			break;
		}
		case 5:
			cout << "Exiting the program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}

	return 0;
}
