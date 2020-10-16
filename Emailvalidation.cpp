#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

int main()
{

string email;
int x = 1,count=0,i,num;



     while(x == 1)
     {
         cout<<endl<<"Enter Email: ";
        cin>>email;
      for(i=0; i<=email.size(); i++)
      {
         if(email[i] == '@')
            count++;
      }
      if(count != 1)
      {
         cout<<"invalid email"<<endl<<"enter again";
      }
      else
      {
        x = 2;
        cout<<"OK";
      }
     }
}
