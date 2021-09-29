#include <iostream>
#include <string>

using namespace std;

bool Is_Num(string s)
{
    bool status=true;
    for(int i=0; i<s.length();i++)
    {
        if(s[i]<'0' || s[i]>'9'){status=false;}
    }
    return status;
}

int main ()
{
    string s;
    
    do
    {
        cout<<"Input \"Exit\" For Terminated the Program\n";
        cout<<"Input Card Number ="; cin>>s;
        if(Is_Num(s)==false){cout<<"Card Input Is Invalid\n"; continue;}
        else
        {
            int temp=0,total=0,d1=0,d2=0;
            for(int i=0; i<s.length();i+=2)
            {
                temp=(s[i]-48)*2;
                if(temp>9)
                {
                    d1=temp/10;
                    d2=temp%10;
                    temp=d1+d2;
                }
                total+=temp;
            }
            for(int i=1; i<s.length(); i+=2)
            {
                total+=s[i]-48;
            }
            if(total%10==0){cout<<"Card Valid\n";}
            else{cout<<"Card Invalid\n";}
        }
    }while(s!="exit");
    return 0;
}