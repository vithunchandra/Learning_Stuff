#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip> 
#include <string>
#include <chrono>
#include <ctime>
#include <thread>


void please_wait();
void login_registry();
int count_account();
void load_account_data();
void login_registry();
void registry();
bool login();

class Customer
{
    public:
    char name[100];
    char username[100];
    char password[100];
};

class Car
{
    public:
    char model[100];
    char namecar[100];
    char plate_num[100];
    char colour[100];
    char power_suply[100];
    char fee_per_hour[100];
    char fee_per_day[100];
    char status[100];
};

Customer cust[1000];
Car car[1000];

void please_wait()
    {
        for(int i=0;i<4;i++)
        {
            std::cout<<".";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

int count_account()
{
    int count=0;
    std::ifstream ifs;
    std::string check;
    ifs.open("customer_data.txt");
    while(std::getline(ifs,check))
    {
        if(!check.empty())
        {
            count++;
        }
    }
    ifs.close();
    return count;
}

void load_account_data ()
{
    std::ifstream ifs;
    ifs.open("customer_data.txt");
    for(int i=0;i<count_account();i++)
    {
        ifs.getline(cust[i].name,20,' ');
        ifs.getline(cust[i].username,20,' ');
        ifs.getline(cust[i].password,20);
    }
    ifs.close();
}

void login_registry()
{
    int choice;
    bool status;
    std::cout<<"\t CAR RENTAL SYSTEM"<<std::endl;
    std::cout<<"================================="<<std::endl;
    std::cout<<"\n\n";
    std::cout<<"---1.Login"<<std::endl;
    std::cout<<"---2.Register"<<std::endl;
    std::cout<<"Number=";
    std::cin>>choice;

    if(choice==1)
    {
        //please_wait();
        system("CLS");
        status=login();
        std::cout<<status<<std::endl;
        if(status==true)
        {
            std::cout<<"//Accses Granted"<<std::endl;
            std::cout<<"Please Wait";
            please_wait();
            system("CLS");
        }
        else if(status==false)
        {
            char retry;
            std::cout<<"//Acces Denied\n";
            std::cout<<"Press any key to Back "<<std::endl;
            if(retry=_getch())
            {
                std::cout<<"Please Wait";
                please_wait();
                system("CLS");
                login_registry();
            }
        }
    }

    if(choice==2)
    {
        //please_wait();
        system("CLS");
        registry();
        system("CLS");
        login_registry();
    }

    else
    {

    }

}

void registry()
{
    std::ofstream ofs;
    ofs.open("customer_data.txt");
    char ch;
    std::string name;
    std::string username;
    std::string password;
    std::cout<<"\t CAR RENTAL SYSTEM"<<std::endl;
    std::cout<<"================================="<<std::endl;
    std::cout<<"\t      REGISTER "<<std::endl;
    std::cout<<"================================="<<std::endl;
    std::cout<<"Input Name ="; std::cin>>name;
    std::cout<<"Input Username ="; std::cin>>username;
    std::cout<<"Input Password =";
    ch=getch();
    while (ch!=13)
    {
        password.push_back(ch);
        std::cout<<"*";
        ch=getch();
    }

    ofs<<name<<" ";
    ofs<<username<<" ";
    ofs<<password<<"\n";
}

bool login()
{
    char us[100];
    char pass[100];
    bool status;
    std::cout<<"\t CAR RENTAL SYSTEM"<<std::endl;
    std::cout<<"================================="<<std::endl;
    std::cout<<"\t      LOGIN "<<std::endl;
    std::cout<<"================================="<<std::endl;
    std::cout<<"\n";
    std::cout<<"Input Username ="; std::cin>>us;
    std::cout<<"Input Password ="; std::cin>>pass;
    std::cout<<us<<pass<<"test"<<std::endl;

    for(int i=0;i<count_account();i++)
    {
        std::cout<<cust[i].username<<cust[i].password<<"test"<<std::endl;
        if(cust[i].username == us && cust[i].password == pass)
        {
            std::cout<<cust[i].username<<cust[i].password<<"test"<<std::endl;
            std::cout<<"username correct"<<std::endl;
            status=true;
            
        }
        
        else
        {
            status=false;
        }
    }
    return status;
}

int main ()
{
    load_account_data();
    login_registry();

    return 0;
}