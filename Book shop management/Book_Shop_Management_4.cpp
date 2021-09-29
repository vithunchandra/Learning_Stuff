#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <chrono>
#include <thread>

void menu();

class Book
{
    private:
        char *author_fs,*author_ls,*title,*publisher,*price,*stock;
        int price_i;
        int stock_i;
    public:
    Book()
    {
        author_fs=new char [100];
        author_ls=new char [100];
        title=new char [100];
        publisher=new char [100];
        price=new char[100];
        stock=new char[100];
    }

    void load_data(int i)
    {
        char read[100];
        int count=0;
        std::ifstream ifs;
        ifs.open("Book.txt");

        for(int j=0;j<i;j++)
        {
            ifs.ignore(1000,'\n');
        }
        ifs.getline(author_fs,100,' ');
        ifs.getline(author_ls,100,' ');
        ifs.getline(publisher,100,' ');
        ifs.getline(title,100,' ');
        ifs.getline(price,100,' ');
        ifs.getline(stock,100);

        ifs.close();
    }

    int get_price()
    {
        return price_i;
    }

    int get_stock()
    {
        return stock_i;
    }

    void load_price_stock(int i)
    {
        price_i=atoi(price);
        stock_i=atoi(stock);
    }

    bool search(char x[100])
    {
        if(strcmp(x,title)==0)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }

    void show_data()
    {
        std::cout<<"Details Book =\n";
        std::cout<<"--Author ="<<author_fs<<" "<<author_ls<<std::endl;
        std::cout<<"--Publisher ="<<publisher<<std::endl;
        std::cout<<"--Title ="<<title<<std::endl;
        std::cout<<"--Price ="<<price<<std::endl;
        std::cout<<"--Stock ="<<stock<<std::endl;
    }

    void list_title(int i)
    {
        std::cout<<(i+1)<<"."<<title<<std::endl;
    }

    void confirmation(int total_price,int num_book)
    {
        std::cout<<"\t\t\tCONFIRMATION\n";
        std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        std::cout<<"Author    =--------------------------------------:"<<author_fs<<" "<<author_ls<<"\n";
        std::cout<<"Publisher =--------------------------------------:"<<publisher<<"\n";
        std::cout<<"Title     =--------------------------------------:"<<title<<"\n";
        std::cout<<"Price     =--------------------------------------:"<<price<<"\n";
        std::cout<<"________________________________________________________________\n";
        std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
            
        std::cout<<"Number of Book  =---------------------------------:"<<num_book<<std::endl;
        std::cout<<"________________________________________________________________\n";
        std::cout<<"Total Price     =---------------------------------:"<<total_price<<std::endl;
    }

    void invoice(int total_price,int x,int num_book)
    {
        std::cout<<"\t\t\tINVOICE\n";
        std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        std::cout<<"Author    =--------------------------------------:"<<author_fs<<" "<<author_ls<<"\n";
        std::cout<<"Publisher =--------------------------------------:"<<publisher<<"\n";
        std::cout<<"Title     =--------------------------------------:"<<title<<"\n";
        std::cout<<"Price     =--------------------------------------:"<<price<<"\n";
        std::cout<<"________________________________________________________________\n";
        std::cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
            
        std::cout<<"Number of Book  =---------------------------------:"<<num_book<<std::endl;
        std::cout<<"________________________________________________________________\n";
        std::cout<<"Total Price     =---------------------------------:"<<total_price<<std::endl;
    }
};

Book book[100];

void please_wait()
{
    std::cout<<"Please wait";
    for(int i=0;i<5;i++)
    {
        std::cout<<"*";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void cin_fail()
{
    std::cin.clear();
    std::cin.ignore(1000,'\n');
}

void wrong_input()
{
    cin_fail();
    std::cout<<"Wrong Input";
    system("pause");
    please_wait();
    system("CLS");
}

int count_book()
{
    int count=0;
    std::string check;
    std::ifstream ifs;
    ifs.open("book.txt");
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

void load_book()
{
    for(int i=0;i<count_book();i++)
    {
        book[i].load_data(i);
    }
}

void load_price_stock()
{   
    for(int i=0;i<count_book();i++)
    {
        book[i].load_price_stock(i);
    }
}

int search_book()
{
    int x;
    char title[100];
    std::cout<<"What Title of The Book do You Want to Search ="; std::cin>>title;

    for (int i=0;i<count_book();i++)
    {
        if(book[i].search(title)==true)
        {
            book[i].show_data();
            x=(i+1);
            break;
        }
        else
        {
            std::cout<<"That Book Not Alvailable Right Now";
            search_book();
        }
    }

    return x;
}

void show_book()
{
    for(int i=0;i<count_book();i++)
    {
        book[i].list_title(i);
    }
}

void detail_book()
{
    int choice;
    int choice_2;
    std::cout<<"List of Book\n";
    show_book();
    std::cout<<"What Book You Want to See?"<<std::endl; std::cin>>choice;

    if(std::cin.fail())
    {
        wrong_input();
    }

    for(int i=0;i<count_book();i++)
    {
        if((i+1)==choice)
        {
            book[i].show_data();
        }
    }
    std::cout<<"1.See Another Book\n2.Back to Menu\n"; 
    std::cout<<"Choice ="; std::cin>>choice_2;
    if(std::cin.fail())
    {
        wrong_input();
    }
    
    if(choice_2==1)
    {
        please_wait();
        detail_book();
    }
    else if(choice_2==2)
    {
        please_wait();
        menu();
    }
    else
    {
        std::cout<<"Invalid Input,Back to Menu";
        please_wait();
        menu();
    }
    
}

void buy_book(int x)
{
    int num_book;
    int total_price;
    std::string type;
    std::cout<<"How Many Book do You Want to Buy ="; std::cin>>num_book;
    while(std::cin.fail())
    {
        wrong_input();
        std::cout<<"How Many Book do You Want to Buy ="; std::cin>>num_book;
    }
    total_price=book[(x-1)].get_price()*num_book;

    book[(x-1)].confirmation(total_price,num_book);

    std::cout<<"\n\n";
    std::cout<<"Buy Book ?\n";
    std::cout<<"Type 'yes' to Continue or 'no' to Cancel\n";
    std::cout<<"Type ="; std::cin>>type;

    if(type=="yes")
    {
        book[(x-1)].invoice(total_price,x,num_book);
    }
    else if(type=="no")
    {
        std::cout<<"Transaction Canceled\n";
        menu();
    }
    else
    {
        std::cout<<"Invalid Input\n";
        please_wait();
        buy_book(x);
    }
}

void choose_book()
{
    int choice;
    int book;
    std::cout<<"You Want to Search The Book or Just See in The List ?\n";
    std::cout<<"1.Search book\n2.See in The List"<<std::endl;
    std::cout<<"Choice ="; std::cin>>choice;

    if(std::cin.fail())
    {
        wrong_input();
        choose_book();
    }

    if(choice==1)
    {
        int x;
        x=search_book();
        buy_book(x);
    }
    else if(choice==2)
    {
        int choice;
        show_book();
            std::cout<<"What Book You Want to Buy ="; std::cin>>choice;
            if(std::cin.fail())
            {
                wrong_input();
                choose_book();
            }
            if(choice<=count_book() && choice>0)
            {
                buy_book(choice);
            }
            else if(choice<1)
            {
                wrong_input();
                choose_book();
            }
    }
    else
    {
        std::cout<<"Invalid Input";
        please_wait();
        choose_book();
    }
}

void menu()
{
    int choice;
    std::cout<<"\t\t\tMENU\n\n";
    std::cout<<"1.Buy Book\n2.List Book\n3.Detail Book\n";
    std::cout<<"Choice =";  std::cin>>choice;
    if(std::cin.fail())
    {
        wrong_input();
        menu();
    }

    switch (choice)
    {
        case 1:
        choose_book();
        break;
        case 2:
        show_book();
        system("pause");
        std::cout<<"Back to Menu";
        please_wait();
        menu();
        break;
        case 3:
        detail_book();
        break;

        default:
        std::cout<<"Invalid Choice";
        menu();
        break;
    }
}

int main()
{
    load_book();
    load_price_stock();
    menu();

    return 0;
}