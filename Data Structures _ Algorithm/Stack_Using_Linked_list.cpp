#include<iostream>

class Node
{
    public:
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

class Stack
{
    public:
        Node *top;
        Stack(){top=NULL;}

        bool Is_Node_Exist(int k)
        {
            bool status=false;
            Node *ptr=top;
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
        
        bool Is_Empty()
        {
            if(top==NULL){return true;}
            else{return false;}
        }

        void push(Node *n)
        {
            if(Is_Empty()){top=n;}
            else
            {
                if(Is_Node_Exist(n->key)){std::cout<<"Node With "<<n->key<<" Key Already Exist\n";}
                else
                {
                    Node *temp=top;
                    top=n;
                    top->next=temp;
                    std::cout<<"Node Appended\n";
                }
            }
        }

        int count()
        {
            Node *ptr=top;
            int count=0;
            while(ptr!=NULL)
            {
                count++;
                ptr=ptr->next;
            }
            return count;
        }

        Node *pop()
        {
            Node *temp=NULL;
            if(Is_Empty()){std::cout<<"Stack Is Underflow\n";}
            else
            {
                temp=top;
                top=top->next;
                std::cout<<"Pop Success\n";
            }   
            return temp;
        }

        Node *peek()
        {
            return top;
        }

        void display()
        {
            Node *ptr=top;
            while(ptr!=NULL)
            {
                std::cout<<"(Key ="<<ptr->key<<", Value ="<<ptr->value<<")"<<std::endl;
                ptr=ptr->next;
            }
        }
};

int main ()
{
    Stack stack;
    int option,key,value;
    
    do
    {
        std::cout<<"What Operation do You Want to Perform?\n";
        std::cout<<"1.Push()\n";
        std::cout<<"2.Pop()\n";
        std::cout<<"3.IsEmpty()\n";
        std::cout<<"4.Peek()\n";
        std::cout<<"5.Count()\n";
        std::cout<<"6.Display()\n";
        std::cout<<"7.Clear Screen\n";
        std::cout<<"Select ="; std::cin>>option;
        Node *n=new Node();
        switch(option)
        {
            case 0:
            {
                break;
            }    
            case 1:
            {
                std::cout<<"Enter Key And Value Of Node To Push To The Stack\n";
                std::cout<<"Key ="; std::cin>>key;
                std::cout<<"Value ="; std::cin>>value;
                n->key=key;
                n->value=value;
                stack.push(n);
                break;
            }
            case 2:
            {
                n=stack.pop();
                std::cout<<"Top Data =(Key ="<<n->key<<" Value ="<<n->value<<")"<<std::endl;
                delete n;  
                std::cout<<"Top Popped\n";
                break;
            }
            case 3:
            {
                if(stack.Is_Empty()){std::cout<<"Stack Is Empty\n";}
                else{std::cout<<"Stack Is Not Empty\n";}
                break;
            }
            case 4:
            {
                if(stack.Is_Empty()){std::cout<<"Stack is Underflow\n";}
                else
                {
                    n=stack.peek();
                    std::cout<<"Top Data =(Key ="<<n->key<<", Value ="<<n->value<<")"<<std::endl;
                }
                break;
            }
            case 5:
            {
                int count=stack.count();
                std::cout<<"Count ="<<count<<"\n";
                break;
            }
            case 6:
            {
                stack.display();
                break;
            }
            case 7:
            {
                system("CLS");
                break;
            }
            default:
            {
                std::cout<<"Input Invalid\n";
                break;
            }
        }   
    }while(option!=0);

    return 0;
}