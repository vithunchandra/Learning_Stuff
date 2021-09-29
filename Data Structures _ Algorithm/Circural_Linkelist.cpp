#include <iostream>

class Node
{
    public:
        int key,data;
        Node *next;

        Node()
        {
            key=0;
            data=0;
            next=NULL;
        }
        Node(int k,int d)
        {
            key=k;
            data=d;
        }
};

class Circular_Linkedlist
{
    public:
        Node *head;
        Circular_Linkedlist(){head=NULL;}
        Circular_Linkedlist(Node *n){head=n;}

        Node *exist_key(int k)
        {
            Node *ptr=head;
            if(ptr==NULL){return ptr;}
            else
            {
                do
                {
                    if(ptr->key==k){return ptr;}
                    else{ptr=ptr->next;}
                }while(ptr!=head);
                return ptr=NULL;
            }
        }

        void append(Node *n)
        {
            if(exist_key(n->key)!=NULL){std::cout<<"Key Already Exist, Please Use Another Key\n";}
            else
            {
                if(head==NULL){head=n; n->next=head; std::cout<<"Node Appended As Head\n";}
                else
                {
                    Node *ptr=head;
                    while(ptr->next!=head){ptr=ptr->next;}
                    ptr->next=n;
                    n->next=head;
                    std::cout<<"Node Appended\n";
                }
            }
        }

        void prepend(Node *n)
        {
            if(exist_key(n->key)!=NULL){std::cout<<"Key Already Exist, Please Use Another Key\n";}
            else
            {
                if(head==NULL){head=n; n->next=head; std::cout<<"Node Appended As Head\n";}
                else
                {
                    Node *ptr=head;
                    while(ptr->next!=head){ptr=ptr->next;}
                    n->next=head;
                    head=n;
                    ptr->next=head;
                    std::cout<<"Node Prepended\n";
                }
            }
        }

        void insert_node_after_by_key(Node *n, int k)
        {
            if(exist_key(n->key)!=NULL){std::cout<<"Key Already Exist, Please Use Another Key\n";}
            else
            {
                Node *ptr=exist_key(k);
                if(ptr==NULL){std::cout<<"Node With "<<k<<" Key Value is Doesn't Exist\n";}
                else
                {
                    if(ptr->next==head)
                    {
                        n->next=head;
                        ptr->next=n;
                        std::cout<<"Node Appended\n";
                    }
                    else
                    {
                        n->next=ptr->next;
                        ptr->next=n;
                        std::cout<<"Node Appended\n";
                    }
                }
            }
        }

        void delete_node(int k)
        {
            if(head==NULL){std::cout<<"Circular Linked List is Empty\n";}
            else
            {
                Node *ptr=exist_key(k);
                if(ptr==NULL){std::cout<<"Node With "<<k<<" Key Value Doesn't Exist\n";}
                else
                {
                    if(ptr==head)
                    {   
                        if(head->next==head)
                        {
                            head=NULL
                            std::cout<<"Node Unlinked. List Empty\n";
                        }
                        else
                        {
                            Node *temp=head;
                            while(temp->next!=head){temp=temp->next;}
                            head=head->next;
                            temp->next=head;    
                            std::cout<<"Node Deleted\n";
                        }
                    }
                    else
                    {
                        Node *temp=head;
                        while(temp->next!=ptr){temp=temp->next;}
                        if(ptr->next==head)
                        {
                            temp->next=head;
                            std::cout<<"Node Deleted\n";
                        }
                        else
                        {
                            temp->next=ptr->next;
                            std::cout<<"Node Deleted\n";
                        }
                    }
                }
            }
        }

        void update(int k, int d)
        {
            Node *ptr=exist_key(k);
            std::cout<<"TEST\n";
            if(ptr==NULL){std::cout<<"Node With "<<k<<" Key Value is Doesn't Exist\n";}
            else{ptr->data=d; std::cout<<"Data Updated\n";}
        }

        void printlist()
        {
            if(head==NULL){std::cout<<"Circular Linkedlist is Empty";}
            else
            {
                std::cout<<"Printing Circular Linkedlist...\n";
                Node *ptr=head;
                do
                {
                    std::cout<<"Key ="<<ptr->key<<" Data ="<<ptr->data<<std::endl;
                    ptr=ptr->next;
                }while(ptr!=head);
            }
        }
};

int main()
{
    Circular_Linkedlist c;
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
            c.append(n1);
            break;

            case 2:
            std::cout<<"Prepend Mode Operation \n Enter Key & Data Of The Node to Be Prepend\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            n1->key=key1;
            n1->data=data1;
            c.prepend(n1);
            break;

            case 3:
            std::cout<<"Insert Node After Operation \n Enter Key Of Existing Node After Which You Want To Insert =";
            std::cin>>k1;
            std::cout<<"Enter Key & Data Of The Node to Be Insert\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            n1->key=key1;
            n1->data=data1;
            c.insert_node_after_by_key(n1,k1);
            break;

            case 4:
            std::cout<<"Delete Node By Key operation\n Enter Node Key You Want to Delete\n";
            std::cout<<"key ="; std::cin>>key1;
            c.delete_node(key1);
            break;

            case 5:
            std::cout<<"Update Node By Key\nEnter Key Node And New Data To Be Updated\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            c.update(key1,data1);
            break;

            case 6:
            c.printlist();
            system("Pause");
            break;

            case 7:
            system("CLS");
            break;

            default:
            std::cout<<"Enter Proper Option Number\n";
            break;
        }
    }while(option!=0);

    return 0;
}