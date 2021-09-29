#include<iostream>

class Node
{
    public:
    int key;
    int data;
    Node *next;

    Node()
    {
        data=0;  
        next=0;
        next=NULL;
    }

    Node(int k, int d)
    {
        key=k;
        data=d;
    }
};

class Singlylinkedlist
{
    public:
    Node *head;
    Singlylinkedlist()
    {
        head=NULL;
    }

    Singlylinkedlist(Node *n)
    {
        head=n;
    }

    Node *node_exist(int k)
    {
        Node *temp=NULL;

        Node *ptr=head;
        while(ptr!=NULL)
        {
            temp=head;
            if(ptr->key==k)
            {
                temp=ptr;
                break;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        return temp;
    }

    void append_node(Node *n)
    {
        if(node_exist(n->key)!=NULL)
        {
            std::cout<<"Append With Another Key Value\n";
        }

        else
        {
            if(head==NULL)
            {
                head=n;
                std::cout<<"Node Appended\n";
            }
            else
            {
                Node *ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
            }
        }
        
    }

    void prepend_node(Node *n)
    {
        if(node_exist(n->key)!=NULL)
        {
            std::cout<<"Key Has Been Used"<<n->key<<"Insert Another Key to Append\n";
        }
        else
        {
                n->next=head;
                head=n;
                std::cout<<"Node prepended\n";
        }
    }

    void insert_node_after(Node *n,int k)
    {
            Node *ptr=node_exist(k);
            if(ptr==NULL){std::cout<<"Node With "<<k<<"Key Value Doesn't Exist\n";}
            else
            {
                if(node_exist(n->key)!=NULL){std::cout<<"That's Key Value Already Exist\n";}
                else
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    std::cout<<"Node Inserted\n";
                }
            }
    }

    void delete_node_bykey(int k)
    {
        if(head==NULL){std::cout<<"Singlelinkedlist Doesn't Have Node\n";}
        else
        {
            if(head->key==k)
            {
                head=head->next;
                std::cout<<"Deleting Complete\n";
            }
            else
            {
                Node *temp=NULL;
                Node *ptr=head->next;
                Node *prevptr=head;
                while(ptr!=NULL)
                {
                    if(ptr->key==k)
                    {
                        temp=ptr;
                        ptr=NULL;
                    }
                    else
                    {
                        prevptr=prevptr->next;
                        ptr=ptr->next;
                    }
                }
                if(temp!=NULL)
                {
                    prevptr->next=temp->next;
                    std::cout<<"Deleting Success\n";
                }
                else
                {
                    std::cout<<"Node Doesn't Exist\n";
                }
            }

        }
    }

    void updatenodebykey(int k, int d)
    {
        Node *ptr=node_exist(k);
        if(ptr!=NULL)
        {
            ptr->data=d;
            std::cout<<"Update Data Success\n";    
        }
        else{std::cout<<"Node Doesnt Exist\n";}
    }
    
    void printlist()
    {
        if(head==NULL)
        {
            std::cout<<"No Nodes in Single Linked List\n";
        }
        else
        {
            Node *ptr=head;
            std::cout<<"Single Linked list Values =";
            while(ptr!=NULL)
            {
                std::cout<<"("<<ptr->key<<","<<ptr->data<<")-->>";
                ptr=ptr->next;
            }
            std::cout<<"\n";
        }
    }
};

int main ()
{
    Singlylinkedlist s;
    int option;
    int key1,k1,data1;

    do
    {
        std::cout<<"What Operation Do You Want To Perform ?\n";
        std::cout<<"1. appenNode()\n2. PrependNode()\n3. InsertNodeAfter()\n4. DeleteNodebyKey()\n5. UpdateNodebyKey()\n6. Print\n7. Clear Screen\n";
        std::cout<<"Select ="; std::cin>>option;
        Node *n1=new Node();

        switch(option)
        {
            case 0:
            break;
            case 1:
            std::cout<<"Append Mode Operation \n Enter Key & Data Of The Node to Be Append\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.append_node(n1);
            break;

            case 2:
            std::cout<<"Prepend Mode Operation \n Enter Key & Data Of The Node to Be Prepend\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prepend_node(n1);
            break;

            case 3:
            std::cout<<"Insert Node After Operation \n Enter Key Of Existing Node After Which You Want To Insert =";
            std::cin>>k1;
            std::cout<<"Enter Key & Data Of The Node to Be Insert\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.insert_node_after(n1,k1);
            break;

            case 4:
            std::cout<<"Delete Node By Key operation\n Enter Node Key You Want to Delete\n";
            std::cout<<"key ="; std::cin>>key1;
            s.delete_node_bykey(key1);

            case 5:
            std::cout<<"Update Node By Key\nEnter Key Node And New Data To Be Updated\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            s.updatenodebykey(key1,data1);

            case 6:
            s.printlist();
            system("Pause");

            case 7:
            system("CLS");
            break;

            default:
            std::cout<<"Enter Proper Option Number\n";
        }
    }while(option!=0);

    return 0;
}