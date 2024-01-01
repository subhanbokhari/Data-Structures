#include <iostream>
using namespace std;
// Syed Subhan Shah Bokhari (22P-9447) (BCS-3C)


void swap(int *ptr1, int *ptr2)
{
    int *ptr3;
    ptr3 = ptr2;
    ptr2 = ptr1;
    ptr1 = ptr3;

    cout << "1 is: " << *ptr1 << endl;
    cout << "2 is: " << *ptr2 << endl;

}
int main()
{
    int num;
    int num2;
    cout << "Enter Number 1: " << endl;
    cin >> num;
    cout << "Enter Number 2: " << endl;
    cin >> num2; 

    int *ptr1 = &num;
    int *ptr2 = &num2;

    swap(ptr1,ptr2);

 return 0;
}
