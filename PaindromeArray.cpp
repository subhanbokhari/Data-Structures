#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// Syed Subhan Shah Bokhari (22P-9447) (BCS-3C)

string toLowercase(string& input)
{
  string lowercase=input;
  for(char& c:lowercase)
  {
    if (c>='A' && c<='Z') 
    {
      c =c-'A'+'a';
    }
  }
  return lowercase;
}

int main()
{
    string input;

    cout<<"Please Enter a String"<<endl;
    cin>>input;

    char *ptr1=&input[0];
    char *ptr2=&input[input.length() - 1];
    bool palindrome=true;

    input=toLowercase(input);

    while(ptr1<ptr2)
    {
        if(*ptr1!=*ptr2)
        {
          palindrome = false;
          cout << "Not Palindrome." << endl;
          break;
        }
        ptr1++;
        ptr2--;
    }
    if (palindrome)
    {
      cout<<"Palindrome."<<endl;
    }

  char maxChar;
  int maxCount=0;

  for(char c='a';c<='z';c++) {
    int count=0;
    for(char ch:input) {
      if(ch==c) 
      {
        count++;
      }  
    }

    if(count>maxCount) {
      maxCount=count;
      maxChar=c;
    }
  }

  cout<<"Max character is "<<maxChar<<" with count "<<maxCount<<endl;


 return 0;
}
