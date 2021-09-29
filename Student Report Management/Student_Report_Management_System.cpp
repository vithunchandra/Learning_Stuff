#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <windows.h>

class Student
{
    private:
    int roll_num;
    char name[100];
    int english, math, science, computer_science;
    double average;
    char grade;

    public:

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

    void get_data()
    {
            std::cout<<"Input Roll Number ="; std::cin>>roll_num;
            while(std::cin.fail())
            {
                wrong_input();
                std::cout<<"Input Roll Number ="; std::cin>>roll_num;
            }
            std::cout<<"Input Student Name ="; std::cin>>name;
            
            std::cout<<"\\Mark Input\n";
            std::cout<<"===============================";

            std::cout<<"Input English Marks ="; std::cin>>english;
            while(std::cin.fail() || english>100)
            {
                wrong_input();
                std::cout<<"Input English Marks ="; std::cin>>english;
            }
            std::cout<<"Input Math Marks ="; std::cin>>math;
            while(std::cin.fail() || math>100)
            {
                wrong_input();
                std::cout<<"Input Math Marks ="; std::cin>>math;
            }
            std::cout<<"Input Science Marks ="; std::cin>>science;
            while(std::cin.fail() || science>100)
            {
                wrong_input();
                std::cout<<"Input Science Marks ="; std::cin>>science;
            }
            std::cout<<"Input Computer Science Marks ="; std::cin>>computer_science;
            while(std::cin.fail() || computer_science>100)
            {
                wrong_input();
                std::cout<<"Input Computer Science Marks ="; std::cin>>computer_science;
            }
        
        grade_average();
    }

    void grade_average()
    {
        average=(english+math+science+computer_science)/4.0;

        if(average>=90)
        {
            grade='A';
        }
        else if(average>=75)
        {
            grade='B';
        }
        else if(average>=50)
        {
            grade='C';
        }
        else
        {
            grade='D';
        }
    }

    int get_roll_num()
    {
        return roll_num;
    }

    void display_data()
    {
        std::cout<<"==========================\n\n";
        std::cout<<"\t\\\ STUDENT REPORT\n";
        std::cout<<"--Name              ="<<name<<std::endl;
        std::cout<<"--Roll Number       ="<<roll_num<<std::endl;
        std::cout<<"_______________________________________"<<std::endl;
        std::cout<<"\n\\\ Student Marks"<<std::endl;
        std::cout<<"--English           ="<<english<<std::endl;
        std::cout<<"--Math              ="<<math<<std::endl;
        std::cout<<"--Science           ="<<science<<std::endl;
        std::cout<<"--Computer Science  ="<<computer_science<<std::endl;
        std::cout<<"\n\\\ Student Average and Grade"<<std::endl;
        std::cout<<"Average             ="<<average<<std::endl;
        std::cout<<"Grade               ="<<grade<<std::endl;
    }

    
};

bool record_check(int roll_numb)
{
    Student student;
    std::ifstream ifs;
    ifs.open("student report",std::ios::binary);
    while(ifs.read(reinterpret_cast<char*>(&student),sizeof(student)))
    {
        if(roll_numb==student.get_roll_num())
        {
            false;
        }
        else
        {
            true;
        }
    }
}

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

void back_menu();

void create_sr()
{
    Student student;
    std::ofstream ofs;
    ofs.open("student report",std::ios::binary|std::ios::app);
    student.get_data();
    ofs.write(reinterpret_cast<char*>(&student),sizeof(student));
    ofs.close();
    std::cout<<"Student Report Created"<<std::endl;
}

void search_student()
{
    int roll_num;
    bool status=false;
    std::cout<<"Input Roll Number of Report You Want to Search ="; std::cin>>roll_num;
    while(std::cin.fail())
    {
        wrong_input();
        std::cout<<"Input Roll Number of Report You Want to Search ="; std::cin>>roll_num;
    }
    
    Student student;
    std::ifstream ifs;
    ifs.open("student report",std::ios::binary);
    ifs.seekg(0,std::ios::beg);
    while(ifs.read(reinterpret_cast<char*>(&student),sizeof(student)))
    {
        if(roll_num==student.get_roll_num())
        {
            status=true;
            student.display_data();
            break;
        }
    }

    if(status==false)
    {
        std::cout<<"Those Roll Number Not Registered,Try Again..\n";
        please_wait();
        search_student();
    }   
    ifs.close();
}

void display_all_data()
{
    Student student;
    std::ifstream ifs;
    ifs.open("student report",std::ios::binary);
    ifs.seekg(0,std::ios::beg);
    std::cout<<"\\Display All Data...\n";
    please_wait();
    while(ifs.read(reinterpret_cast<char*>(&student),sizeof(student)))
    {
        std::cout<<"====================================================\n";
        student.display_data();
        std::cout<<"====================================================\n";
    }
    ifs.close();
}

void modify_data()
{   
    Student student;
    int roll_num;
    bool status = false;
    std::cout<<"Enter Roll Number Student You Want to Modify ="; std::cin>>roll_num;
    while(std::cin.fail())
    {
        wrong_input();
        std::cout<<"Enter Roll Number Student You Want to Modify ="; std::cin>>roll_num;
    }
    std::fstream fs;
    fs.open("student report",std::ios::binary|std::ios::in|std::ios::out);
    while(fs.read(reinterpret_cast<char*>(&student),sizeof(student)))
    {
        std::cout<<"tes\n";
        if(roll_num==student.get_roll_num())
        {
            int pos=(-1)*static_cast<int>(sizeof(student));
            std::cout<<"pos ="<<pos<<std::endl;
            fs.seekp(136,std::ios::cur);
            student.get_data();
            fs.write(reinterpret_cast<char*>(&student),sizeof(student));
            std::cout<<"Modify Succsses\n";
            status=true;
        }
    }
    if(status==false)
    {
        std::cout<<"Roll Number Not Found\n";
    }
    fs.close();
}

void delete_data()
{
    Student student;
    int roll_num;
    bool status = false;
    std::cout<<"Enter Roll Number Student You Want to Delete ="; std::cin>>roll_num;
    while(std::cin.fail())
    {
        wrong_input();
        std::cout<<"Enter Roll Number Student You Want to Delete ="; std::cin>>roll_num;
    }
    std::ifstream ifs;
    std::ofstream ofs;
    ifs.open("student report",std::ios::binary|std::ios::in|std::ios::out);
    ofs.open("student report",std::ios::binary);
    while(ifs.read(reinterpret_cast<char*>(&student),sizeof(student)))
    {
        if(student.get_roll_num()!=roll_num)
        {
            ofs.seekp(0,std::ios::beg);
            ofs.write(reinterpret_cast<char*>(&student),sizeof(student));
        }
    }
    std::cout<<"Delete Data Succsses\n";
    ifs.close();
    ofs.close();
}

int main()
{
    int choice;
    std::cout<<"\t\tSTUDENT REPORT MANAGEMENT SYSTEM\n\n";
    std::cout<<"\t\t\tMenu\n";
    std::cout<<"1.Create Student Report\n";
    std::cout<<"2.Search Student Report\n";
    std::cout<<"3.All List Student Report\n";
    std::cout<<"4.Modify Student Report\n";
    std::cout<<"5.Delete Student Report\n";
    std::cout<<"6.Exit\n";
    std::cout<<"Number ="; std::cin>>choice;
    if(std::cin.fail())
    {
        wrong_input();
    }

    switch(choice)
    {
        case 1:
        create_sr();
        std::cout<<"Back to Menu\n";
        back_menu();
        break;
        case 2:
        search_student();
        std::cout<<"Back to Menu\n";
        back_menu();
        break;
        case 3:
        display_all_data();
        std::cout<<"Back to Menu\n";
        back_menu();
        break;
        case 4:
        modify_data();
        std::cout<<"Back to Menu\n";
        back_menu();
        case 5:
        delete_data();
        std::cout<<"Back To Menu\n";
        back_menu();
        case 6:
        exit(0);
        break;

        default:
        std::cout<<"Invalid Input, Back to Menu\n";
        please_wait();
        main();
    }


    return 0;
}

void back_menu()
{
    system("pause");
    please_wait();
    main();
}