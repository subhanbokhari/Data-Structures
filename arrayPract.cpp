#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    int total = 0;
    int size;

    cout << "Enter the size of the arrays: ";
    cin >> size;

    int *arr = new int[size];
    int *arr2 = new int[size];

    cout << "Enter " << size << " values for array A: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter " << size << " values for array B: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr2[i];
    }

    int *p = arr;
    int *q = arr2;

    while (total != size)
    {
        if (*p == *q)
        {
            count++;
        }
        q++;
        p++;
        total++;
    }

    cout << count << endl;

    count = 0;
    int i = 0;
    int j = 0;

    while (i < size)
    {
        j = 0;

        while (j < size)
        {
            if (arr[i] == arr2[j])
            {
                count++;
            }
            j++;
        }

        i++;
    }

    cout << count << endl;

    return 0;
}