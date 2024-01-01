
#include <iostream>
using namespace std;
// Syed Subhan Shah Bokhari (22P-9447) (BCS-3C)

int main()
{
    int arr[4][7];
    int *ptr=&arr[0][0];

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<7;j++)
        {
            *ptr=(rand() % (30 - 10 + 1)) + 10;
            ptr++;
        }
    }

    ptr=&arr[0][0];
    cout<<"Temperatures of Each Week:" << endl;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<7;j++)
        {
            cout<<*ptr<<"   ";
            ptr++;
        }
        cout<<endl;
    }

    ptr =&arr[0][0];
    int *hottest=ptr;
    int hot;
    string hot_day;

    for (int i=0;i<4;i++)
    {
        hottest=&arr[i][0];
        hot=0;
        for (int j=0;j<7;j++)
        {
            if (arr[i][j]>*hottest)
            {
                hottest=&arr[i][j];
                hot=j;
            }
        }
        if (hot==0)
        {
            hot_day="Sunday";
        }
        else if (hot==1)
        {
            hot_day ="Monday";
        }
        else if (hot==2)
        {
            hot_day="Tuesday";
        }
        else if (hot==3)
        {
            hot_day="Wednesday";
        }
        else if (hot==4)
        {
            hot_day="Thursday";
        }
        else if (hot==5)
        {
            hot_day="Friday";
        }
        else if (hot==6)
        {
            hot_day="Saturday";
        }

        cout << "The Hottest was Day " << hot_day << " of Week " << i + 1 << ": " << *hottest << endl;
    }

    return 0;
}