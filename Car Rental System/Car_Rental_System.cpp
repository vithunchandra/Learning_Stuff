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

class Customer
{
    public:
    std::string name;
    std::string carmodel;
    std::string namecar;
    int carnumber;
    double sum;
    
};

class Rent : public Customer
{
    public:
    int day=0;
    void please_wait();
    void date_time();
    void welcome();
    void registry();
    void login_registry();
    bool login();
    void Customer();
    void calculations();
    void invoice();
    
};



void Rent::date_time()
{
    time_t rawtime = time(0);
    char* datetime=ctime(&rawtime);
    std::cout<<datetime;
}

void Rent::welcome()
{
    std::ifstream welcome("welcome.txt");
    std::string str;
    std::string file_contents;
    while(std::getline(welcome,str))
    {
        file_contents += str;
        file_contents.push_back('\n');
    }
    std::cout<<file_contents<<std::endl;
    welcome.close();
    std::cout<<"-------------------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"\n\n\n\n\n";
    std::cout<<"Loading Files....."<<std::endl;
    sleep(1);
    std::cout<<"Please Wait";
    please_wait();
    system("CLS");
}

void Rent::registry()
{
    std::string username;
    std::string password;
    std::cout<<"\t CAR RENTAL SYSTEM"<<std::endl;
    std::cout<<"================================="<<std::endl;
    std::cout<<"\t      REGISTER "<<std::endl;
    std::cout<<"================================="<<std::endl;
    std::cout<<"Username="; std::cin>>username;
    std::cout<<"Password="; std::cin>>password;
    std::ofstream file(username+".txt");
    file<<username<<std::endl<<password;
    file.close();
    std::cout<<"Back To Login and Register Menu";
    please_wait();
    system("CLS");
}

bool Rent::login()
{
    char ch;
    std::string username;
    std::string password;
    std::string us;
    std::string pass;
    std::cout<<"\t CAR RENTAL SYSTEM"<<std::endl;
    std::cout<<"================================="<<std::endl;
    std::cout<<"\t      LOGIN "<<std::endl;
    std::cout<<"================================="<<std::endl;
    
        std::cout<<"Enter Username ="; std::cin>>username;
        std::cout<<"Enter Password ="; 
        ch=getch();
        while(ch != 13)
        {
            password.push_back(ch);
            std::cout<<"*";
            ch=getch();
        }

        std::ifstream file;
        file.open(username+".txt");
        std::getline(file,us);
        std::getline(file,pass);
        if(username==us && password==pass)
        {
            
            return true;
        }
        else
        {
            return false;
        }
}

void Rent::login_registry()
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
        if(status==true)
        {
            std::cout<<"//Accses Granted"<<std::endl;
            std::cout<<"Please Wait";
            please_wait();
            system("CLS");
        }
        else
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
        login_registry();
    };

}

void Rent::Customer()
{
        std::cout<<"Input Name"<<std::endl;
        std::cin>>name;
        std::cout<<"Please Wait";
        please_wait();
        system("CLS");
    
        do
        {
            std::cout<<"Welcome "<<name<<std::endl;
            std::cout<<"=========================="<<std::endl;
            std::cout<<"\n\n\n";
            std::cout<<"What Car You Want To Rent ?"<<std::endl;
            std::cout<<"A.Mobilio 2020"<<std::endl;
            std::cout<<"B.Alphard 2019"<<std::endl;
            std::cout<<"C.Astra 2020"<<std::endl;
            std::cout<<"\n\n\n\n\n\n";
            std::cout<<"Input With Capital Letter"<<std::endl;
            std::cout<<"Input Your Choice....";
            std::cin>>carmodel;
            
            if(carmodel=="A")
            {
                std::cout<<"Please Wait";
                please_wait();
                system("CLS");
                std::string file;
                std::string file_contents;
                std::ifstream A("A.txt");
                while(std::getline(A,file_contents))
                {
                    file+=file_contents;
                    file.push_back('\n');
                }
                namecar="Mobilio 2020";
                std::cout<<"Mobilio 2020"<<std::endl;
                std::cout<<"============";
                std::cout<<"\n\n\n";
                std::cout<<file<<std::endl;
            }
            if(carmodel=="B")
            {
                std::cout<<"Please Wait";
                please_wait();
                system("CLS");
                std::string file;
                std::string file_contents;
                std::ifstream B("B.txt");
                while(std::getline(B,file_contents))
                {
                    file+=file_contents;
                    file.push_back('\n');
                }
                namecar="Alphard 2019";
                std::cout<<"Alphard 2019"<<std::endl;
                std::cout<<"============";
                std::cout<<"\n\n\n";
                std::cout<<file<<std::endl;
            }
            if(carmodel=="C")
            {
                std::cout<<"Please Wait";
                please_wait();
                system("CLS");
                std::string file;
                std::string file_contents;
                std::ifstream C("C.txt");
                while(std::getline(C,file_contents))
                {
                    file+=file_contents;
                    file.push_back('\n');
                }
                namecar="Astra 2020";
                std::cout<<"Astra 2020"<<std::endl;
                std::cout<<"============";
                std::cout<<"\n\n\n";
                std::cout<<file<<std::endl;
            }
            if(carmodel!="A" || carmodel!="B" || carmodel!="C")
            {
                std::cout<<"Invalid Car Model"<<std::endl;
                
            }
        
        }
        while(carmodel!="A" || carmodel!="B" || carmodel!="C");
}    

void Rent::calculations()
    {
        std::cout<<"Number of Car Want to Rent =........";
        std::cin>>carnumber;
        std::cout<<std::endl;
        std::cout<<"Day of Car Want to Rent =........";
        std::cin>>day;
        std::cout<<std::endl;

        if(carmodel=="A")
        {   
            int fee=20;
            sum=(fee*carnumber*day);
        }
        if(carmodel=="B")
        {   
            int fee=30;
            sum=(fee*carnumber*day);
        }
        if(carmodel=="C")
        {   
            int fee=25;
            sum=(fee*carnumber*day);
        }
        std::cout<<"Printing Invoice";
        please_wait();
        system("CLS");
    }

void Rent::invoice()
    {
        std::cout<<"\n\n\t\t Car Rental - INVOICE "<<std::endl;
        std::cout<<"____________________________________________________"<<std::endl;
        std::cout<<"////////////////////////////////////////////////////"<<std::endl;
        std::cout<<"//Name:--------------------------------------------:"<<name<<std::endl;
        std::cout<<"//Car Model:---------------------------------------:"<<carmodel<<std::endl;
        std::cout<<"//Car Name:----------------------------------------:"<<namecar<<std::endl;
        std::cout<<"//Number of Car:-----------------------------------:"<<carnumber<<std::endl;
        std::cout<<"//Number of Day:-----------------------------------:"<<day<<std::endl;
        std::cout<<"//Date and Time:-----------------------------------:"; date_time(); std::cout<<"\n";
        std::cout<<"____________________________________________________\n";
        std::cout<<"//Total Fee:---------------------------------------:Rp."<<sum<<".000"<<std::endl;
        std::cout<<"====================================================\n";
        std::cout<<"===================================================="<<std::endl;
        std::cout<<"\n\n\n\t\t\tThank You"<<std::endl;
        std::cout<<"====================================================";
    }

void Rent::please_wait() 
    {
        for(int i=0;i<4;i++)
        {
            std::cout<<".";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }


int main ()
{
    Rent obj;
    obj.welcome();
    obj.login_registry();
    obj.Customer();
    obj.calculations();
    obj.invoice();
    
    return 0;
}