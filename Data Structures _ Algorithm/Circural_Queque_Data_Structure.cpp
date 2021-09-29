#include <iostream>

#include <iostream>

class Queque
{
    private:
    int arr[4];
    int rear=0;
    int front=0;
    int count;

    public:
    Queque()
    {
        count=0;
        front=-1;
        rear=-1;
        for(int i=0;i<4;i++)
        {
            arr[i]=0;
        }
    }

    bool isempty()
    {
        if(rear==-1 && front==-1){return true;}
        else{return false;}
    }
    
    bool isfull()
    {
        if((rear+1)%4==front){return true;}
        else{return false;}
    }
    
    void enque(int value)
    {
        if(isfull())
        {
            std::cout<<"Queque is Full\n";
            return;
        }
        else if(isempty()){front=0; rear=0; arr[rear]=value; count++;}
        else{rear=(rear+1)%4; arr[rear]=value; count++}
    }
    
    int deque()
    {
        int temp;
        if(isempty())
        {
            std::cout<<"Queque is Empty\n";
            return 0;
        }
        else if(front==rear)
        {
            temp=arr[front];
            arr[front]=0; 
            count--
            rear=front=-1;
        }
        else
        {
            temp=arr[front];
            arr[front]=0;
            count--;
            front=(front+1)%4;
        }
        return temp;
    }

    int count()
    {
        return count;
    }

    void display()
    {
        for(int i=0;i<4;i++)
        {
            std::cout<<arr[i]<<", ";
        }
        std::cout<<std::endl;
    }
};

int main()
{
    Queque q1;
    int option;
    int value;
    do
    {
        std::cout<<"What Operation do You Want to Perform? \n-Option From 1-7\n";
        std::cout<<"1.Enqueque()\n2.Dequeque()\n3.IsEmpty()\n4.IsFull\n5.Count()\n6.Display\n7.Clear Screen\n0.Exit\n";
        std::cout<<"Select Operation ="; std::cin>>option;

        switch(option)
        {
            case 1:
            std::cout<<"Input Value ="; std::cin>>value;
            q1.enque(value);
            break;
            case 2:
            std::cout<<"Deque Operation value ="<<q1.deque()<<std::endl;
            break;
            case 3:
            if(q1.isempty()){std::cout<<"Queque Is Empty\n";}
            else{std::cout<<"Queque Is Not Empty\n";}
            break;
            case 4:
            if(q1.isfull()){std::cout<<"Queque Is Full\n";}
            else{std::cout<<"Queque Is Not Full\n";}
            break;
            case 5:
            std::cout<<"Queque Data Count ="<<q1.count()<<std::endl;
            break;
            case 6:
            q1.display();
            break;
            case 7: 
            system("CLS");
            break;

            default:
            std::cout<<"Wrong Input!\n";
            break;
        }
    }while(option!=0);

}