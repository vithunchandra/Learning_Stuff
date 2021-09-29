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
#include <stdio.h>

void welcome();
char* date_time();
int count_admin();
int count_account();
int count_car();
void load_admin_data();
void load_account_data();
void load_car_data();
void save_car_data();
bool car_status(int x);
void please_wait();
void wrong_input();
void welcome();
void user_type();
void admin_log();
bool login_admin();
void login_registry();
void login_registry();
void registry();
bool login();
void menu();
void menu_admin();
void edit_car_list();
void edit_car_details(int x);
void car_after_edit(int x);
void new_car();
void new_car_details(int i);
void car_list();
void choose_car();
void car_display();
double fee_per_hour(int x);
double fee_per_day(int x);
void confirmation(int pick, int num_car,double total_fee,std::string day_hour);
void invoice (int pick, int num_car,double total_fee,std::string day_hour);

class Customer
{
    public:
    char name[100];
    char username[100];
    char password[100];
};

class Admin
{
    public:
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

Admin admin[1000];
Customer cust[1000];
Car car[1000];
char name[100];

void cin_fail()
{
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

void wrong_input()
{
    cin_fail();
    std::cout<<"\\Wrong Input";
    system("PAUSE");
    please_wait();
    system("CLS");
}

void please_wait()
    {
        for(int i=0;i<4;i++)
        {
            std::cout<<".";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }


char* date_time()
{
    time_t rawtime = time(0);
    char* datetime=ctime(&rawtime);
    return datetime;
}

void live_time()
{
    int hours,minutes,seconds,seconds_prev;
    struct tm* time_data;
    time_t raw_time;
    std::string pm_am;

    while(true)
    {
        time(&raw_time);
        time_data=localtime(&raw_time);
        
        hours=time_data->tm_hour;
        minutes=time_data->tm_min;
        seconds=time_data->tm_sec;

        if(hours<12)
        {
            pm_am="AM";
        }
        else
        {
            pm_am="PM";
        }

        if(seconds==seconds_prev+1 || seconds_prev==59 && seconds==0)
        {
            system("CLS");
            std::cout<< (hours<12 ? "0":"") <<hours<<":"<< (minutes<10 ? "0":"") <<minutes<<":"<< (seconds<10 ? "0":"") <<seconds<<" "<< pm_am <<std::endl;
        }

        seconds_prev=seconds;
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

int count_admin()
{
    int count;
    std::string check;
    std::ifstream ifs;
    ifs.open("admin.txt");
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

void load_admin_data()
{
    std::ifstream ifs;
    ifs.open("admin.txt");
    for(int i=0;i<count_admin();i++)
    {
        ifs.getline(admin[i].username,20,' ');
        ifs.getline(admin[i].password,20,' ');
    }
    ifs.close();
}

void save_car_data()
{
    std::ofstream ofs;
    ofs.open("car rental.txt");
    for(int i=0;i<count_car();i++)
    {
        ofs<<car[i].model<<" ";
        ofs<<car[i].namecar<<" ";
        ofs<<car[i].plate_num<<" ";
        ofs<<car[i].colour<<" ";
        ofs<<car[i].power_suply<<" ";
        ofs<<car[i].fee_per_hour<<" ";
        ofs<<car[i].fee_per_day<<" ";
        ofs<<car[i].status<<"\n";
    }
    ofs.close();
}

int count_car()
{
    int numofcar=0;
    std::string check;
    std::ifstream ifs("car rental.txt");
    while(std::getline(ifs,check))
    {
        if(!check.empty())
        {
            numofcar++;
        }
    }
    ifs.close();
    return numofcar;
}

void load_car_data()
{
    std::ifstream ifs;
    ifs.open("car rental.txt");
    
    for(int i=0;i<count_car();i++)
    {
            ifs.getline(car[i].model,20,' ');
            ifs.getline(car[i].namecar,20,' ');
            ifs.getline(car[i].plate_num,20,' ');
            ifs.getline(car[i].colour,20,' ');
            ifs.getline(car[i].power_suply,20,' ');
            ifs.getline(car[i].fee_per_hour,20,' ');
            ifs.getline(car[i].fee_per_day,20,' ');
            ifs.getline(car[i].status,20);
    }
    ifs.close();
}

bool car_status(int x)
{
    bool status;
    if(strcmp(car[(x-1)].status,"true")==0)
    {
        status=true;
    }
    else
    {
         status=false;
    }
    
    return status;
}

void welcome()
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
    load_admin_data();
    load_account_data();
    load_car_data();
    sleep(1);
    please_wait();
    system("CLS");
}

void user_type()
{
    int pick;
    std::cout<<"\t\tType of User\n\n";
    std::cout<<"1.Admin\n2.Customer\n";
    std::cout<<"Input Your Type ="; std::cin>>pick;
    while(std::cin.fail())
    {
        wrong_input();
        std::cout<<"Input Your Type ="; std::cin>>pick;
    }
    if(pick==1)
    {
        admin_log();
    }
    if(pick==2)
    {
        login_registry();
    }
}

void admin_log()
{
    bool status;
    status=login_admin();
    if(status=true)
    {
        std::cout<<"\\Acces Granted\n";
        system("pause");
        system("CLS");
        menu_admin();
    }
    else
    {
        std::cout<<"\\Acces Denied\n";
        system("PAUSE");
        system("CLS");
        admin_log();
    }
}

bool login_admin()
{
    bool status;
    char us[100];
    char pass[100];
    std::cout<<"\t\t\tCar Rental \n\n";
    std::cout<<"Input Username ="; std::cin>>us;
    std::cout<<"Input Password ="; std::cin>>pass;

    for(int i=0;i<count_admin();i++)
    {
        if(strcmp(admin[i].username,us)==0)
        {
            if(strcmp(admin[i].password,pass)==0)
            {
                status=true;
                break;
            }

            else
            {
                status=false;
            }
        }

        else
        {
            status=false;
        }
    }
    return status;
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

    if(std::cin.fail())
    {
        wrong_input();
        login_registry();
    }

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
            menu();
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

    else if(choice==2)
    {
        //please_wait();
        system("CLS");
        registry();
        load_account_data();
        system("CLS");
        login_registry();
    }

    else
    {
        std::cout<<"Wrong Input";
        system("PAUSE");
        please_wait();
        login_registry();
    }
}

void registry()
{
    std::ofstream ofs;
    ofs.open("customer_data.txt",std::ofstream::app);
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

    for(int i=0;i<count_account();i++)
    {
        if(strcmp(cust[i].username,us)==0)
        {
            if(strcmp(cust[i].password,pass)==0)
            {
                strcpy(name,cust[i].name);
                status=true;
                break;
            }

            else
            {
                status=false;
            }
        }
        
        else
        {
            status=false;
        }
    }
    return status;
}

void menu ()
{
    std::string pick;
    do
    {
        
        std::cout<<"\t\t\t MENU \n\n";
        std::cout<<"1.Car Rental\n";
        std::cout<<"2.List of Car\n";
        std::cout<<"3.All Car Details\n";
        std::cout<<"4.Back To Login and Registry Page\n";
        std::cout<<"Select Number =";
        std::cin>>pick;
        if(pick=="1")
        {
            choose_car();
        }
        if(pick=="2")
        {
            car_list();
        }
        if(pick=="3")
        {
            car_display();
        }
        if(pick=="4")
        {
            login_registry();
        }

        else if(pick!="1" || pick!="2" || pick!="3")
        {
            std::cout<<"\nWrong Input";
            system("CLS");
        }
    }
    while(pick!="1" || pick!="2" || pick!="3");
}

void menu_admin()
{
    int choice;
    std::cout<<"\t\tAdmin Menu\n\n";
    std::cout<<"1.Edit Car Data\n";
    std::cout<<"2.New Car Data";
    std::cin>>choice;
    if(std::cin.fail())
    {
        wrong_input();
        menu_admin();
    }
    if(choice==1)
    {
        please_wait();
        edit_car_list();
    }
    else if(choice==2)
    {
        please_wait();
        new_car();
    }
    else
    {
        std::cout<<"\\Wrong Input\n";
        system("PAUSE");
        std::cout<<"Back To Menu Admin\n";
        please_wait();
        menu_admin();
    }
}

void edit_car_list()
{
    int pick;
    std::cout<<"\t\t\tEdit Car\n\n";
    std::cout<<"LIST OF CAR\n";
    std::cout<<"===================================================\n\n";
    for(int i=0;i<count_car();i++)
    {
        std::cout<<(i+1)<<"."<<car[i].namecar<<std::endl;
    }
    std::cout<<"===================================================\n";
    std::cout<<"What Car you Want to Edit? You Want to Edit ="; std::cin>>pick;
    if(std::cin.fail())
    {
        wrong_input();
        edit_car_list();
    }
    if(pick>count_car())
    {
        wrong_input();
        edit_car_list();
    }

    edit_car_details(pick);
}

void edit_car_details(int x)
{
    int car_num;
    for(int i=0;i<count_car();i++)
    {
        if((x-1)==i)
        {
            car_num=i;
            std::cout<<"\t\t\tCAR DETAILS\n\n";
            std::cout<<"/////////////////////////////////////////////////////////////////\n";
            std::cout<<"1.Car Model       =--------------------------------------:"<<car[i].model<<"\n";
            std::cout<<"2.Name Car        =--------------------------------------:"<<car[i].namecar<<"\n";
            std::cout<<"3.Plate Number    =--------------------------------------:"<<car[i].plate_num<<"\n";
            std::cout<<"4.Car Colour      =--------------------------------------:"<<car[i].colour<<"\n";
            std::cout<<"5.Car Power Suply =--------------------------------------:"<<car[i].power_suply<<"\n";
            std::cout<<"6.Fee Per Hour    =--------------------------------------:"<<car[i].fee_per_hour<<"\n";
            std::cout<<"7.Fee Per Day     =--------------------------------------:"<<car[i].fee_per_day<<"\n";
            std::cout<<"8.Car Status      =--------------------------------------:"<<car[i].status<<std::endl;
            std::cout<<"________________________________________________________________\n";
        }
    }

    int edit;
    std::cout<<"What Item You Want to Edit ="; std::cin>>edit;
    if(std::cin.fail())
    {
        wrong_input();
        std::cout<<"bug"<<std::endl;
        system("PAUSE");
        edit_car_details(x);
    }
    /*if(edit>8)
    {
        wrong_input();
        edit_car_details(x);
    }*/

    switch (edit)
    {
        case 1:
        std::cout<<"1.Car Model       =--------------------------------------:"; std::cin>>car[car_num].model;
        break;
        case 2:
        std::cout<<"2.Name Car        =--------------------------------------:"; std::cin>>car[car_num].namecar;
        break;
        case 3:
        std::cout<<"3.Plate Number    =--------------------------------------:"; std::cin>>car[car_num].plate_num;
        break;
        case 4:
        std::cout<<"4.Car Colour      =--------------------------------------:"; std::cin>>car[car_num].colour;
        break;
        case 5:
        std::cout<<"5.Car Power Suply =--------------------------------------:"; std::cin>>car[car_num].power_suply;
        break;
        case 6:
        std::cout<<"6.Fee Per Hour    =--------------------------------------:"; std::cin>>car[car_num].fee_per_hour;
        break;
        case 7:
        std::cout<<"7.Fee Per Day     =--------------------------------------:"; std::cin>>car[car_num].fee_per_day;
        break;
        case 8:
        std::cout<<"8.Car Status      =--------------------------------------:"; std::cin>>car[car_num].status;
        break;
        default:
        std::cout<<"Invalid Input\n";
    }

    save_car_data();
    load_car_data();
    car_after_edit(car_num);

    int pick;
    std::cout<<"Edit Succes\n";
    system("pause");
    system("CLS");
    std::cout<<"1.Edit Again\n2.Back to Menu\n";
    std::cout<<"Input ="; std::cin>>pick;
    while(std::cin.fail() || pick>2)
    {
        wrong_input();
        std::cout<<"Input ="; std::cin>>pick;
    }
    if(pick==1)
    {
        please_wait();
        edit_car_list();
    }
    if(pick==2)
    {
        please_wait();
        menu_admin();
    }
}

void car_after_edit(int x)
{
    std::cout<<"Details Car After Edit =\n";
    std::cout<<"\t\t\tCAR DETAILS\n\n";
    std::cout<<"/////////////////////////////////////////////////////////////////\n";
    std::cout<<"1.Car Model       =--------------------------------------:"<<car[x].model<<"\n";
    std::cout<<"2.Name Car        =--------------------------------------:"<<car[x].namecar<<"\n";
    std::cout<<"3.Plate Number    =--------------------------------------:"<<car[x].plate_num<<"\n";
    std::cout<<"4.Car Colour      =--------------------------------------:"<<car[x].colour<<"\n";
    std::cout<<"5.Car Power Suply =--------------------------------------:"<<car[x].power_suply<<"\n";
    std::cout<<"6.Fee Per Hour    =--------------------------------------:"<<car[x].fee_per_hour<<"\n";
    std::cout<<"7.Fee Per Day     =--------------------------------------:"<<car[x].fee_per_day<<"\n";
    std::cout<<"8.Car Status      =--------------------------------------:"<<car[x].status<<std::endl;
    std::cout<<"________________________________________________________________\n";
}

void new_car()
{
    int i=count_car()+1;
    std::ofstream ofs;
    ofs.open("car rental.txt",ofs.app);
    ofs<<"\n";
    std::cout<<"\t\t New Car Data Input\n\n";
    std::cout<<"\t\t\tCAR DETAILS\n\n";
    std::cout<<"/////////////////////////////////////////////////////////////////\n";
    std::cout<<"Car Model       =--------------------------------------:";
    std::cin>>car[i].model; ofs<<car[i].model<<" ";
    std::cout<<"Name Car        =--------------------------------------:";
    std::cin>>car[i].namecar; ofs<<car[i].namecar<<" ";
    std::cout<<"Plate Number    =--------------------------------------:";
    std::cin>>car[i].plate_num; ofs<<car[i].plate_num<<" ";
    std::cout<<"Car Colour      =--------------------------------------:";
    std::cin>>car[i].colour; ofs<<car[i].colour<<" ";
    std::cout<<"Car Power Suply =--------------------------------------:";
    std::cin>>car[i].power_suply; ofs<<car[i].power_suply<<" ";
    std::cout<<"Fee Per Hour    =--------------------------------------:";
    std::cin>>car[i].fee_per_hour; ofs<<car[i].fee_per_hour<<" ";
    std::cout<<"Fee Per Day     =--------------------------------------:";
    std::cin>>car[i].fee_per_day; ofs<<car[i].fee_per_day<<" ";
    std::cout<<"Car Status      =--------------------------------------:";
    std::cin>>car[i].status; ofs<<car[i].status<<" ";
    std::cout<<"________________________________________________________________\n";
    load_car_data();
    new_car_details(i);
}

void new_car_details(int i)
{
    std::cout<<"New Car Details =\n";
    std::cout<<"\t\t\tCAR DETAILS\n\n";
    std::cout<<"/////////////////////////////////////////////////////////////////\n";
    std::cout<<"1.Car Model       =--------------------------------------:"<<car[i].model<<"\n";
    std::cout<<"2.Name Car        =--------------------------------------:"<<car[i].namecar<<"\n";
    std::cout<<"3.Plate Number    =--------------------------------------:"<<car[i].plate_num<<"\n";
    std::cout<<"4.Car Colour      =--------------------------------------:"<<car[i].colour<<"\n";
    std::cout<<"5.Car Power Suply =--------------------------------------:"<<car[i].power_suply<<"\n";
    std::cout<<"6.Fee Per Hour    =--------------------------------------:"<<car[i].fee_per_hour<<"\n";
    std::cout<<"7.Fee Per Day     =--------------------------------------:"<<car[i].fee_per_day<<"\n";
    std::cout<<"8.Car Status      =--------------------------------------:"<<car[i].status<<std::endl;
    std::cout<<"________________________________________________________________\n";
}

void car_list()
{
    int pick;
    std::cout<<"\t\t\tLIST OF CAR\n";
    std::cout<<"===================================================\n\n";
    for(int i=0;i<count_car();i++)
    {
        std::cout<<(i+1)<<"."<<car[i].namecar<<std::endl;
    }
    std::cout<<"===================================================";

    
    std::cout<<"Enter 0 to back\n";
    std::cin>>pick;
    
    if(std::cin.fail())
    {
        wrong_input();
        car_list();
    }
    else if(pick==0)
    {
        please_wait();
        system("CLS");
        menu();
    }
    else
    {   
        std::cout<<"Wrong Input"<<std::endl;
        system("Pause");
        please_wait();
        system("CLS");
        car_list();
    }
}

void choose_car()
{
    std::cout<<"\t\t\tLIST OF CAR\n";
    std::cout<<"===================================================\n\n";
    for(int i=0;i<count_car();i++)
    {
        std::cout<<(i+1)<<"."<<car[i].namecar<<std::endl;
    }
    std::cout<<"===================================================";

    int pick=0;
    bool status;
    std::cout<<"\n\n";
    std::cout<<"What Car You Want to Rent ?\n";
    std::cout<<"Car Number =";
    std::cin>>pick;

    if(std::cin.fail())
    {
        wrong_input();
        choose_car();
    }
    else if(pick>count_car())
    {
        std::cout<<"\\Wrong Input";
        system("PAUSE");
        please_wait();
        system("CLS");
        choose_car();
    }


        for (int i=0;i<count_car();i++)
        {
            if((pick-1)==i)
            {
                if(car_status(pick))
                {
                std::cout<<"\t\t\tCAR DETAILS\n\n";
                std::cout<<"/////////////////////////////////////////////////////////////////\n";
                std::cout<<"Car Model       =--------------------------------------:"<<car[i].model<<"\n";
                std::cout<<"Name Car        =--------------------------------------:"<<car[i].namecar<<"\n";
                std::cout<<"Plate Number    =--------------------------------------:"<<car[i].plate_num<<"\n";
                std::cout<<"Car Colour      =--------------------------------------:"<<car[i].colour<<"\n";
                std::cout<<"Car Power Suply =--------------------------------------:"<<car[i].power_suply<<"\n";
                std::cout<<"Fee Per Hour    =--------------------------------------:"<<car[i].fee_per_hour<<"\n";
                std::cout<<"Fee Per Day     =--------------------------------------:"<<car[i].fee_per_day<<"\n";
                std::cout<<"Car Status      =--------------------------------------:"<<car[i].status<<std::endl;
                std::cout<<"________________________________________________________________\n";
                }
                else
                {
                    std::cout<<"Oops That Car Have Been Rented"<<std::endl;
                    system("PAUSE");
                    std::cout<<"Back to Car Selection"<<std::endl;
                    please_wait();
                    choose_car();
                }
            }
        }
    
    int car_num,fee_type;
    double total_fee;
    std::cout<<"How Many Car do You Want to Rent ="; std::cin>>car_num;
    while(std::cin.fail())
    {
        wrong_input();
        std::cout<<"How Many Car do You Want to Rent ="; std::cin>>car_num;
    }
    std::cout<<"1.Rent For a Day\n2.Rent For a Hour\n";
    std::cout<<"What Type of Rent do You Want ="; std::cin>>fee_type;
    while(std::cin.fail())
    {
        wrong_input();
        std::cout<<"What Type of Rent do You Want ="; std::cin>>fee_type;
    }
    if(fee_type==1)
    {
        int day;
        std::string str_day;
        std::cout<<"How Many Days You Want to Rent ="; std::cin>>day;
        while(std::cin.fail())
        {
            wrong_input();
            std::cout<<"How Many Day You Want to Rent ="; std::cin>>day;
        }
        str_day=std::to_string(day)+"Day";
        total_fee=(car_num*fee_per_day(pick)*day);
        confirmation(pick,car_num,total_fee,str_day);
    }
    else if(fee_type==2)
    {
        int hour;
        std::string str_hour;
        std::cout<<"How Many Hour You Want to Rent ="; std::cin>>hour;
        while(std::cin.fail())
        {
            wrong_input();
            std::cout<<"How Many Hour You Want to Rent ="; std::cin>>hour;
        }
        str_hour=std::to_string(hour)+"Hour";
        total_fee=(car_num*fee_per_day(pick)*hour);
        confirmation(pick,car_num,total_fee,str_hour);
    }
    else
    {
        std::cout<<"Wrong Input"<<std::endl;
        please_wait();
        choose_car();
    }
}

void car_display()
{
    int pick;
    std::cout<<"\t\t\tCAR DETAILS\n\n";
    for(int i=0;i<count_car();i++)
    {
        std::cout<<"/////////////////////////////////////////////////////////////////\n";
        std::cout<<"Car Model       =--------------------------------------:"<<car[i].model<<"\n";
        std::cout<<"Name Car        =--------------------------------------:"<<car[i].namecar<<"\n";
        std::cout<<"Plate Number    =--------------------------------------:"<<car[i].plate_num<<"\n";
        std::cout<<"Car Colour      =--------------------------------------:"<<car[i].colour<<"\n";
        std::cout<<"Car Power Suply =--------------------------------------:"<<car[i].power_suply<<"\n";
        std::cout<<"Fee Per Hour    =--------------------------------------:"<<car[i].fee_per_hour<<"\n";
        std::cout<<"Fee Per Day     =--------------------------------------:"<<car[i].fee_per_day<<"\n";
        std::cout<<"Car Status      =--------------------------------------:"<<car[i].status<<std::endl;
        std::cout<<"________________________________________________________________\n";
    }
        std::cout<<"Enter 0 to back\n";
        std::cin>>pick;
        if(std::cin.fail())
        {
            wrong_input();
            car_display();
        }
        else if(pick==0)
        {
            sleep(2);
            system("CLS");
            menu();
        }
        else
        {
            std::cout<<"Wrong input\n";
            please_wait();
            system("CLS");
            car_display();
        }
}

void confirmation(int pick, int num_car,double total_fee,std::string day_hour)
{
    std::cout<<"\t\t\tCar Details\n";
    std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    std::cout<<"Car Model       =--------------------------------------:"<<car[(pick-1)].model<<"\n";
    std::cout<<"Name Car        =--------------------------------------:"<<car[(pick-1)].namecar<<"\n";
    std::cout<<"Plate Number    =--------------------------------------:"<<car[(pick-1)].plate_num<<"\n";
    std::cout<<"Car Colour      =--------------------------------------:"<<car[(pick-1)].colour<<"\n";
    std::cout<<"Car Power Suply =--------------------------------------:"<<car[(pick-1)].power_suply<<"\n";
    std::cout<<"Fee Per Hour    =--------------------------------------:"<<car[(pick-1)].fee_per_hour<<"\n";
    std::cout<<"Fee Per Day     =--------------------------------------:"<<car[(pick-1)].fee_per_day<<"\n";
    std::cout<<"________________________________________________________________\n";
    std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
           
    std::cout<<"Number of Car Rented =---------------------------------:"<<num_car<<std::endl;
    std::cout<<"Time Rent            =---------------------------------:"<<day_hour<<std::endl;
    std::cout<<"________________________________________________________________\n";
    std::cout<<"Total Fee            =---------------------------------:"<<total_fee<<std::endl;

    std::string confirm;
    std::cout<<"Please Type 'yes' to Confirm and 'no' to Cancel ="; std::cin>>confirm;
    std::cout<<std::endl;
    if(confirm=="yes")
    {
        please_wait();
        invoice(pick,num_car,total_fee,day_hour);
    }
    else if(confirm=="no")
    {
        std::cout<<"Back to Menu"<<std::endl;
        please_wait();
        menu();
    }
    else
    {
        std::cout<<"Wrong Input"<<std::endl;
        please_wait();
        confirmation(pick,num_car,total_fee,day_hour);
    }
}

void invoice (int pick, int num_car,double total_fee,std::string day_hour)
{
    std::cout<<"\n\n\t\t Car Rental - INVOICE "<<std::endl;
        std::cout<<"_______________________________________________________"<<std::endl;
        std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<std::endl;
        std::cout<<"//Name:------------------------------------------------:"<<name<<std::endl;
        std::cout<<"Car Model       =--------------------------------------:"<<car[(pick-1)].model<<"\n";
        std::cout<<"Name Car        =--------------------------------------:"<<car[(pick-1)].namecar<<"\n";
        std::cout<<"Plate Number    =--------------------------------------:"<<car[(pick-1)].plate_num<<"\n";
        std::cout<<"Car Colour      =--------------------------------------:"<<car[(pick-1)].colour<<"\n";
        std::cout<<"Car Power Suply =--------------------------------------:"<<car[(pick-1)].power_suply<<"\n";
        std::cout<<"Fee Per Hour    =--------------------------------------:"<<car[(pick-1)].fee_per_hour<<"\n";
        std::cout<<"Fee Per Day     =--------------------------------------:"<<car[(pick-1)].fee_per_day<<"\n";
        std::cout<<"Date and Time:---------------------------------------:"<<date_time()<<std::endl;
        std::cout<<"_______________________________________________________\n";
        std::cout<<"Total Fee:-------------------------------------------:Rp."<<total_fee<<".000"<<std::endl;
        std::cout<<"========================================================\n";
        std::cout<<"\n\n\n\t\t\tThank You"<<std::endl;
        std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<std::endl;
    system("PAUSE");
    std::cout<<std::endl;
    please_wait();
    exit(0);
}

double fee_per_hour(int x)
{
    double fee=atof(car[x-1].fee_per_hour);
    return fee;
}

double fee_per_day(int x)
{
    double fee=atof(car[x-1].fee_per_day);
    return fee;
}

int main ()
{
    welcome();
    user_type();
    return 0;
}