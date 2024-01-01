#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    string designation;
    Employee *left;
    Employee *right;
    int height;

    Employee(int id, const string &name, const string &designation)
    {
        this->id = id;
        this->name = name;
        this->designation = designation;
        left = right = nullptr;
        height = 1;
    }
};

class OrgHierarchy
{
public:
    Employee *root;

    int getHeight(Employee *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Employee *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Employee *rightRotate(Employee *y)
    {
        Employee *x = y->left;
        Employee *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Employee *leftRotate(Employee *x)
    {
        Employee *y = x->right;
        Employee *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Employee *insert(Employee *node, int id, const string &name, const string &designation)
    {
        if (node == nullptr)
        {
            return new Employee(id, name, designation);
        }

        if (id < node->id)
        {
            node->left = insert(node->left, id, name, designation);
        }
        else if (id > node->id)
        {
            node->right = insert(node->right, id, name, designation);
        }
        else
        {
            cout << "Employee with the same ID already exists." << endl;
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1)
        {
            if (id < node->left->id)
            {
                return rightRotate(node);
            }
            else if (id > node->left->id)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if (balanceFactor < -1)
        {
            if (id > node->right->id)
            {
                return leftRotate(node);
            }
            else if (id < node->right->id)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    Employee *search(Employee *node, int id)
    {
        if (node == nullptr || node->id == id)
        {
            return node;
        }

        if (id < node->id)
        {
            return search(node->left, id);
        }
        else
        {
            return search(node->right, id);
        }
    }

    Employee *findMinValueNode(Employee *node)
    {
        Employee *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Employee *remove(Employee *node, int id)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (id < node->id)
        {
            node->left = remove(node->left, id);
        }
        else if (id > node->id)
        {
            node->right = remove(node->right, id);
        }
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                Employee *temp = node->left ? node->left : node->right;

                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }

                delete temp;
            }
            else
            {
                Employee *minValueNode = findMinValueNode(node->right);

                node->id = minValueNode->id;
                node->name = minValueNode->name;
                node->designation = minValueNode->designation;

                node->right = remove(node->right, minValueNode->id);
            }
        }

        if (node == nullptr)
        {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1)
        {
            if (getBalanceFactor(node->left) >= 0)
            {
                return rightRotate(node);
            }
            else
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if (balanceFactor < -1)
        {
            if (getBalanceFactor(node->right) <= 0)
            {
                return leftRotate(node);
            }
            else
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }
    void printEmployeeDetails(Employee *node)
    {
        if (node)
        {
            cout << "ID: " << node->id << endl;
            cout << "Name: " << node->name << endl;
            cout << "Designation: " << node->designation << endl;
            cout << endl;

            printEmployeeDetails(node->left);
            printEmployeeDetails(node->right);
        }
    }
};

int main()
{
    OrgHierarchy org;
    org.root = nullptr;

    cout << "Organization Hierarchy Management" << endl;

    char choice;
    do
    {
        cout << "1. Add Employee" << endl;
        cout << "2. Remove Employee" << endl;
        cout << "3. Print Employees" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            int id;
            string name, designation;
            cout << "Enter the ID of the employee: ";
            cin >> id;
            cout << "Enter the name of the employee: ";
            cin >> name;
            cout << "Enter the designation of the employee: ";
            cin >> designation;

            org.root = org.insert(org.root, id, name, designation);
            cout << "Employee added successfully!" << endl;
            break;
        }
        case '2':
        {
            int id;
            cout << "Enter the ID of the employee to remove: ";
            cin >> id;

            org.root = org.remove(org.root, id);
            cout << "Employee removed successfully!" << endl;
            break;
        }
        case '3':
        {
            cout << "Employee Details:" << endl;
            org.printEmployeeDetails(org.root);
            break;
        }
        case '4':
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != '4');

    return 0;
}