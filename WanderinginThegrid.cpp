#include <iostream>
using namespace std;

int main()
{
    char *ptr;
    char arr[3][3];
    ptr = &arr[0][0];
    int choice;
    char choice2;

    while(choice != 5)
    {
        for(int i=0;i<3;i++)
        {
        for(int j=0;j<3;j++) 
        {
            arr[i][j] = (rand() % 2 == 0) ? '-' : 'x';
            if(i==1 & j==1)
            {
                arr[i][j]= 'o';
                ptr = &arr[i][j];
            }
        }
        }
        cout << "Current position: o" << endl;
        cout << "Choose a move , you are stading in the middle of the grid" << endl;
        cout << "1)- Top" << endl << "2)- Bottom" << endl << "3)- Left" << endl << "4)- Right" << endl << "5)- Exit Game" << endl;
        cin >> choice;

        if(choice==1)
        {
            ptr = ptr-3;
        }
        if(choice==2)
        {
            ptr = ptr+3;
        }
        if(choice==3)
        {
            ptr = ptr-1;
        }
        if(choice==4)
        {
            ptr = ptr +1;
        }

        if(*ptr == '-')
        {
            cout << "Safe place, you won." << endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++) 
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        }
        else if(*ptr == 'x')
        {
            cout << "You lost, collided." << endl;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++) 
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

            cout << "Want to try your Luck again? (y/n)" << endl;
            cin >> choice2;
            if(choice2 == 'n')
            {
                break;
            }
        }
    }
 return 0;
}