#include <iostream>
using namespace std;

void printArray(int* arr, int length)
{
    cout << "Array: ";
    for (int i = 1; i < length; i++)
    {
        cout << "(" << arr[i] << " " << ")";
    }
    cout << endl;
}

int main()
{
    int* ptr;
    int* ptr2 = nullptr;
    int* ptr3;

    ptr3 = new int[10];  // Current
    ptr = ptr3;         // Head
    ptr2 = ptr3;        // Tail

    int choice = 0;
    int index;
    int replace;
    int length = 0;
    char option;

    while (choice != 10)
    {
        printArray(ptr, length);
        cout << "Select the Required Action" << endl;
        cout << "1. Get" << endl
            << "2. Update" << endl
            << "3. Length" << endl
            << "4. Pointer Back" << endl
            << "5. Pointer Next" << endl
            << "6. Pointer First" << endl
            << "7. Pointer End" << endl
            << "8. Remove" << endl
            << "9. Add" << endl
            << "10. End" << endl;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Please enter the index you want to get: ";
            cin >> index;
            cout << *(ptr + (index - 1)) << endl;
        }
        else if (choice == 2)
        {
            cout << "Please enter the index you want to update: ";
            cin >> index;
            cout << "Please enter the integer to be updated: ";
            cin >> replace;
            *(ptr + (index - 1)) = replace;
        }
        else if (choice == 3)
        {
            cout << "Elements in the list: " << length << endl;
        }
        else if (choice == 4)
        {
            if (ptr3 == ptr)
            {
                cout << "Pointer out of bounds!" << endl;
            }
            else
            {
                ptr3--;
            }
        }
        else if (choice == 5)
        {
            if (ptr3 == ptr)
            {
                cout << "Pointer out of bounds!" << endl;
            }
            else
            {
                ptr3++;
            }
        }
        else if (choice == 6)
        {
            if (ptr3 == ptr)
            {
                cout << "Pointer already at Start" << endl;
            }
            else
            {
                ptr3 = ptr;
            }
        }
        else if (choice == 7)
        {
            if (ptr3 == ptr2)
            {
                cout << "Pointer already at end" << endl;
            }
            else
            {
                ptr3 = ptr2;
            }
        }
        else if (choice == 8)
        {
            cout << "Please enter the index you want to remove: ";
            cin >> index;

            if (index >= 1 && index <= length)
            {
                for (int i = index; i < length; i++)
                {
                    *(ptr + i - 1) = *(ptr + i);
                }

                length--;
                ptr2--;

                // Adjust ptr3 if it was pointing to the removed element
                if (ptr3 >= ptr + index)
                {
                    ptr3--;
                }
            }
            else
            {
                cout << "Invalid index!" << endl;
            }
        }
        else if (choice == 9)
        {
            cout << "Enter Index you want to input to" << endl;
            cin >> index;
            if (index <= 10 && index >= 1)
            {
                if (ptr2 - ptr == 10)
                {
                    cout << "Data loss can happen. Are you sure? (y/n)" << endl;
                    cin >> option;
                    if (option == 'y')
                    {
                        ptr3--;
                        for (int i = ptr2 - ptr; i >= index; i--)
                        {
                            *(ptr3 + 1) = *ptr3;
                            ptr3--;
                        }
                        cout << "Enter the Value to Store" << endl;
                        cin >> replace;
                        *(ptr + index) = replace;
                    }
                    else
                    {
                        cout << "Data not lost!" << endl;
                    }
                }
                else
                {
                    for (int i = ptr2 - ptr; i >= index - 1; i--)
                    {
                        *(ptr3 + 1) = *ptr3;
                        ptr3--;
                    }
                    cout << "Enter the Value to Store" << endl;
                    cin >> replace;
                    *(ptr + index) = replace;
                    length++;
                    ptr2++;
                }
            }
            else
            {
                cout << "Out of Bounds" << endl;
            }
        }

    }

    delete[] ptr3;
    return 0;
}