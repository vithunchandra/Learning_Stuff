#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <chrono>
#include <thread>

class Player
{
    private:
    char name[100];
    char username[100];
    char password[100];
    int balance=0;

    public:

    void registry(char n[100],char us[100],char pw[100])
    {
        strcpy(name,n);
        strcpy(username,us);
        strcpy(password,pw);
    }

    void set_balance(int x)
    {
        balance=balance+x;
    }

    void reduce_balance(int x)
    {
        balance=balance-x;
    }

    int get_balance()
    {
        return balance;
    }

    bool login(char us[100],char pw[100])
    {
        bool status;
        if(strcmp(username,us)==0)
        {
            if(strcmp(password,pw)==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

};

void cin_fail()
{
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

void please_wait()
    {
        for(int i=0;i<4;i++)
        {
            std::cout<<".";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

void wrong_input()
{
    cin_fail();
    std::cout<<"\\Wrong Input";
    system("PAUSE");
    please_wait();
    system("CLS");
}

void registry(Player &player)
{
    char name[100];
    char us[100];
    char pw[100];
    std::ofstream ofs;
    ofs.open("player data",std::ios::binary|std::ios::app);
    std::cout<<"Input Username ="; std::cin>>us;
    std::cout<<"Input Password ="; std::cin>>pw;
    std::cout<<"Input Name ="; std::cin>>name;
    player.registry(name,us,pw);
    ofs.write(reinterpret_cast<char*>(&player),sizeof(player));
    std::cout<<"Registry Success\n";
}

void save_data(Player &player,int &x)
{
    std::fstream fs;
    int pos;
    fs.open("player data",std::ios::binary|std::ios::in|std::ios::out);
    pos=static_cast<int>(sizeof(player))*x;
    pos=pos-static_cast<int>(sizeof(player));
    fs.seekp(pos,std::ios::beg);
    fs.write(reinterpret_cast<char*>(&player),sizeof(player));
    fs.close();
    system("pause");
}

bool login(Player &player,int &x)
{
    char us[100];
    char pw[100];
    bool status=false;
    std::ifstream ifs;
    ifs.open("player data",std::ios::binary);
    std::cout<<"Enter Username ="; std::cin>>us;
    std::cout<<"Enter Password ="; std::cin>>pw;
    while(ifs.read(reinterpret_cast<char*>(&player),sizeof(player)) && status==false)
    {
        if(player.login(us,pw) == true)
        {
            std::cout<<"//Access Granted\n";
            status=true;
            break;
        }
    }
    if(status==false)
    {
        std::cout<<"//Access Denied\n";
        std::cout<<"Back To Login And Registry Menu";
        please_wait();
    }
    ifs.close();
    return status;
}

void login_registry(Player &player,int &x)
{
    int choice;
    bool status;
    do
    {
        status=false;
        std::cout<<"1.Login\n2.Registry\n";
        std::cout<<"Number ="; std::cin>>choice;
        std::cout<<"\n";
        while(std::cin.fail() || choice>2)
        {
            wrong_input();
            std::cout<<"1.Login\n2.Registry\n";
            std::cout<<"Number ="; std::cin>>choice;
            std::cout<<"\n";
        }
        switch (choice)
        {
            case 1:
            status=login(player,x);
            break;
            case 2:
            registry(player);
            break;
            default:
            std::cout<<"Invalid Input";
            please_wait();
            status=false;
            break;
        }
    }while(status==false);
}

void play(Player &player)
{
    int guess;
    int number;
    int count=1;
    int reward;
    int choice;
    bool status = true;
    srand(time(0));
    std::cout<<"\t\tCassino Guessing Number\n\n";
    std::cout<<"========================================================\n";
    std::cout<<"Rule Of The Game =\n";
    std::cout<<"-Each Guess Cost 100$\n-If Your Guess Is Correct,You Will Receive 500$\n-If You Correct Continuesly Then The Reward Will Be Multiply\n";
    std::cout<<"========================================================\n";
    system("pause");
    std::cout<<"\t\tGAME START\n";
    please_wait();
    system("cls");
    while(player.get_balance() >= 100 && status==true)
    {
        std::cout<<"Your Current Balance ="<<player.get_balance()<<"$"<<std::endl;
        player.reduce_balance(100);
        std::cout<<"Guess The Number From 1-10 ="; std::cin>>guess;
        while(std::cin.fail() || guess==0 || guess>10)
        {
            wrong_input();
            std::cout<<"Guess The Number From 1-10 ="; std::cin>>guess;
        }
        number=(rand()%10)+1;
        std::cout<<"The Number is ="<<number<<std::endl;
        if(guess==number)
        {
            reward=500*count;
            player.set_balance(reward);
            std::cout<<"--Congratulations Your Guess Is Correct\n";
            std::cout<<"--Your Earned ="<<reward<<"$\n";
            count++;
        }
        else if(guess!=number)
        {
            std::cout<<"Oops Your Guess Not Correct\n";
            std::cout<<"Maybe This Is Not Your Day\n";
            count=1;
        }
        std::cout<<"Your Current Balance ="<<player.get_balance()<<"$"<<std::endl;
        std::cout<<"Play Again? =\n";
        std::cout<<"1.Play Again\n2.Back To Menu\n";
        std::cout<<"Input ="; std::cin>>choice;
        while(std::cin.fail() || choice==0 || choice>2)
        {
            wrong_input();
            std::cout<<"1.Play Again\n2.Back To Menu\n";
            std::cout<<"Input ="; std::cin>>choice;
        }
        if(choice==1)
        {
            status=true;
            please_wait();
            system("cls");
        }
        else if(choice==2)
        {
            status=false;
            please_wait();
        }
    }
    if(player.get_balance()<100)
    {
        std::cout<<"--Oops Your Balance Is Not Suifficient\n";
        std::cout<<"--Please Recharge In Menu Recharge\n";
    }
    std::cout<<"Back To Menu"; please_wait();
}

void charge_balance(Player &player)
{
    int balance;
    std::cout<<"How Many Balance You Want To Add ="; std::cin>>balance;
    while(std::cin.fail())
    {
        wrong_input();
        std::cout<<"How Many Balance You Want To Add ="; std::cin>>balance;
    }
    player.set_balance(balance);
    std::cout<<"Balance Added\n";
}

void see_balance(Player &player)
{
    std::cout<<"Your Balance Is ="<<player.get_balance()<<std::endl;
}

void main_menu(Player &player, int &x)
{
    int choice;
    do
    {
        std::cout<<"\t\t\tMENU\n";
        std::cout<<"1.Play\n2.Charge Balance\n3.See My Balance\n4.Save My Data\n5.Exit\n";
        std::cout<<"Number ="; std::cin>>choice;
        while(std::cin.fail() || choice>5)
        {
            wrong_input();
            std::cout<<"Number ="; std::cin>>choice;
        }

        switch(choice)
        {
            case 1:
            play(player);
            break;
            case 2:
            charge_balance(player);
            case 3:
            see_balance(player);
            break;
            case 4:
            save_data(player,x);
            break;
            case 5:
            exit(0);
            default:
            exit(0);
            break;
        }
    }while(true);
}

int main ()
{
    Player player;
    int count;
    std::cout<<"\t\tCASSINO GUESING NUMBER\n";
    std::cout<<"Loading Data";
    please_wait();
    system("CLS");
    login_registry(player,count);
    main_menu(player,count);

    return 0;
}