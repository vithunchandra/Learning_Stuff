#include <iostream>
#include <stdio.h>
#include <string>

bool check_num(std::string &credit_num)
{
    int length=credit_num.length();
    for(int i=0; i<length; i++)
    {
        if(credit_num[i]<'0' || credit_num[i]>'9'){return true;}
    }
    return false;
}

bool card_validator(std::string check_num)
{
    int length=check_num.length();
    int temp=0;
    int double_even_sum=0;

    //Sum even number
    for(int i=length-2; i>=0; i-=2)
    {
        temp=(check_num[i]-48);
        temp=temp*2;
        if(temp>9){temp=((temp/10)+(temp%10));}
        double_even_sum += temp;
    }

    //Sum odd number
    for(int i=length-1; i>=0; i-=2)
    {
        temp=(check_num[i]-48);
        double_even_sum+=temp;
    }

    if(double_even_sum%10==0){return true;}
    else{return false;}
}

int main()
{
    std::string credit_num;
    int length;

    while(true)
    {
        std::cout<<"Card Validator Program\n--You Can Type Exit To Out From The Program\n";
        std::cout<<"Input Your Card Number ="; std::cin>>credit_num;

        if(credit_num == "exit"){break;}

        else if(check_num(credit_num))
        {
            std::cout<<"Wrong Input!\n";
            continue;
        }

        if(card_validator(credit_num))
        {
            std::cout<<"Card Valid\n";
            break;
        }
        else{std::cout<<"Card Invalid\n";}
    }

    return 0;
}