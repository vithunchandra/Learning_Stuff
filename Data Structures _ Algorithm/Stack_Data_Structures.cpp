#include <iostream>
#include <string>

class Stack
{
    private:
    int top;
    int arr[5];

    public:
    Stack()
    {
        top = -1;
        for(int i=0; i<5; i++)
        {
            arr[i]=0;
        }
    }
    bool isempty()
    {
        if (top==-1){return true;}
        else{return false;}
    }
    bool isfull()
    {
        if(top==4){return true;}
        else{return false;}
    }

    void push(int val)
    {
        if(isfull()){std::cout<<"Stack is Full\n"; return ;}
        else
        {
            top++;
            arr[top]=val;
        }
    }

    int pop()
    {
        if(isempty()){std::cout<<"Stack is Empty\n"; return 0;}
        else
        {
            int temp=arr[top];
            arr[top]=0;
            top--;
            return temp;
        }
    }

    int count()
    {
        return (top+1);
    }

    int peek(int pos)
    {
        return arr[pos];
    }

    void change(int pos, int value)
    {
        arr[pos]=value;
        std::cout<<"Change Success\n";
    }

    void display()
    {
        if(isempty())
        {
            std::cout<<"Stack is Empty\n";
            return ;
        }   
        for(int i=4;i>=0;i--){std::cout<<arr[i]<<", ";}
        std::cout<<"\n";
    }
};


int main()
{
    Stack stack;
    int option,position,value;
    
    do
    {
        std::cout<<"What Operation do You Want to Perform?\n";
        std::cout<<"1.Push()\n";
        std::cout<<"2.Pop()\n";
        std::cout<<"3.IsEmpty()\n";
        std::cout<<"4.IsFull()\n";
        std::cout<<"5.Peek()\n";
        std::cout<<"6.Count()\n";
        std::cout<<"7.Change()\n";
        std::cout<<"8.Display()\n";
        std::cout<<"9.Clear Screen\n";
        std::cout<<"Select ="; std::cin>>option;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');

            std::cout<<"Wrong Input\n";
            continue;
        }
        switch(option)
        {
            case 1:
            std::cout<<"Input Value to Push ="; std::cin>>value;
            while(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');

                std::cout<<"Input Value to Push ="; std::cin>>value;
            }
            stack.push(value);
            break;
            case 2:
            stack.pop();
            break;
            case 3:
            if(stack.isempty()){std::cout<<"Stack is Empty\n";}
            else{std::cout<<"Stack is Not Empty\n";}
            break;
            case 4:
            stack.isfull();
            break;
            case 5:
            std::cout<<"Input Position ="; std::cin>>position;
            std::cout<<"Value at Position"<<position<<" is ="<<stack.peek(position)<<std::endl;
            break;
            case 6:
            stack.count();
            break;
            case 7:
            std::cout<<"Input Position ="; std::cin>>position;
            while(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');

                std::cout<<"Input Position ="; std::cin>>position;
            }
            std::cout<<"Input Value ="; std::cin>>value;
            while(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');

                std::cout<<"Input Value ="; std::cin>>value;
            }
            stack.change(position,value);
            break;
            case 8:
            stack.display();
            break;
            case 9:
            system("CLS");
            break;
            default:
            std::cout<<"Wrong Input!\n";
            break;
        }
        

    }while(option!=0);
    
    return 0;
}