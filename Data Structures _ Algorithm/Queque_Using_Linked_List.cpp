#include <iostream>

class Node
{
    public :
        int key,value;
        Node *next;

        Node()
        {
            key=0;
            value=0;
            next=NULL;
        }
        Node(int k, int v)
        {
            key=k;
            value=v;
            next=NULL;
        }
};

class Queque
{   
    public :
        Node *rear;
        Node *end;

        Queque()
        {
            rear=NULL;
            end=NULL;
        }

        bool Is_Empty()
        {
            bool status;
            if(rear==NULL && end==NULL){status=true;}
            else{status=false;}
            return status;
        }

        bool Is_Node_Exist(int k)
        {
            bool status=false;
            Node *ptr=end;
            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    status=true;
                    break;
                }
                else{ptr=ptr->next;}
            }
            return status;
        }

        void Enqueque(Node *n)
        {
            if(Is_Empty())
            {
                rear=n;
                end=n;
                std::cout<<"Node Enquequed\n";
            }
            else
            {
                Node *ptr=rear;
                if(Is_Node_Exist(n->key)){std::cout<<"Node With Key "<<n->key<<"Already Exist\n";}
                else
                {
                    rear->next=n;
                    rear=n;
                    std::cout<<"Node Enquequed\n";
                }
            }
        }

        Node *Dequequed()
        {
            Node *temp=NULL;
            if(Is_Empty()){std::cout<<"List Is Underflowed\n";}
            else if(rear==end)
            {
                temp=end;
                end=NULL;
                rear=NULL;
            }
            else
            {
                temp=end;
                end=end->next;
            }
            return temp;
        }

        int Count()
        {
            Node *ptr=end;
            int count=0;
            while(ptr!=NULL)
            {
                count++;
                ptr=ptr->next;
            }
            return count;
        }

        void Display()
        {
            Node *ptr=end;
            while(ptr!=NULL)
            {
                std::cout<<"(Key ="<<ptr->key<<" Value ="<<ptr->value<<") ===>\n";
                ptr=ptr->next;
            }
        }
};

int main ()
{
    Queque q;
    int option, key, value;

    do
    {
        std::cout<<"What Operation do You Want to Perform?\n";
        std::cout<<"1.Enqueque()\n";
        std::cout<<"2.Dequeque()\n";
        std::cout<<"3.IsEmpty()\n";
        std::cout<<"4.Count()\n";
        std::cout<<"5.Display()\n";
        std::cout<<"6.Clear Screen\n";
        std::cout<<"Select ="; std::cin>>option;

        Node *n=new Node();

        switch(option)
        {
            case 1:
            {
                std::cout<<"Input Key And Value Of Node To Enqueque\n";
                std::cout<<"Key ="; std::cin>>key;
                std::cout<<"Value ="; std::cin>>value;
                n->key=key;
                n->value=value;
                q.Enqueque(n);
                break;
            }
            case 2:
            {
                if(q.Is_Empty()){std::cout<<"Queque Is Empty, Can't Dequeque\n";}
                else
                {
                    Node *temp=q.Dequequed();
                    std::cout<<"Dequequed Data =(Key ="<<temp->key<<" Value ="<<temp->value<<")\n";
                    delete temp;
                    temp=NULL;
                }
                break;
            }
            case 3:
            {
                if(q.Is_Empty()){std::cout<<"Queque Is Empty\n";}
                else{std::cout<<"Queque Is Not Empty\n";}
                break;
            }
            case 4:
            {
                int count=q.Count();
                std::cout<<"Numbers Of Nodes in Queque is ="<<count<<"\n";
                break;
            }
            case 5:
            {
                std::cout<<"DISPLAY =\n";
                q.Display();
                break;
            }
            case 6: 
            {
                system("CLS");
                break;
            }
            default:
            {
                std::cout<<"Input Invalid, Enter Proper Number\n";
                break;
            }
        }
    }while(option!=0);
    std::cout<<"Program Terminated\n";

    return 0;
}