#include <iostream>

class Node
{
    public:
        int key;
        int data;
        Node *next;
        Node *previous;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
            previous = NULL;
        }
        Node(int k, int d)
        {
            key = k;
            data = d;
            next = NULL;
            previous = NULL;
        }
};

class Double_Linkedlist
{
    public:
        Node *head;

        Double_Linkedlist()
        {head = NULL;}

        Node *exist_key(int k)
        {
            Node *ptr=head;
            while(ptr!=NULL)
            {
                if(ptr->key==k){break;}
                else{ptr=ptr->next;}
            }
            return ptr;
        }

        void append(Node *n)
        {
            if(exist_key(n->key)!=NULL){std::cout<<"Key Already Used, Please Pick Another Key\n";}
            else
            {
                if(head==NULL){head=n; std::cout<<"Node Appended\n";}
                else
                {
                    Node *ptr=head;
                    while(ptr->next!=NULL)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    n->previous=ptr;
                    std::cout<<"Node Appended\n";
                }    
            }
        }

        void prepend_node(Node *n)
        {
            if(exist_key(n->key)!=NULL){std::cout<<"Key Already Used, Please Pick Another Key\n";}
            else
            {
                if(head==NULL){head=n; std::cout<<"Node Appended as Head\n";}
                else
                {
                    n->next=head;
                    head->previous=n;
                    head=n;
                    std::cout<<"Node Appended\n";
                }
            }
        }

        void insert_node_after(Node *n, int k)
        {
            Node *ptr=exist_key(k);
            if(ptr==NULL){std::cout<<"Node With "<<k<<" Key Value is Doesn't Exist\n";}
            else
            {
                if(exist_key(n->key)!=NULL){std::cout<<"Key Already Used, Please Pick Another Key\n";}
                else
                {
                   if(ptr->next!=NULL)
                    {
                        n->previous=ptr;
                        n->next=ptr->next;
                        n->next->previous=n;
                        ptr->next=n;
                        std::cout<<"Node Appended\n";
                    }
                   else
                   {
                       ptr->next=n;
                       n->previous=ptr;
                       std::cout<<"Node Appended at The End\n";
                   }
                }
            }
        }

        void delete_node(int k)
        {
            if(head==NULL){std::cout<<"Double Linkedlist Doesn't Have Node Yet\n";}
            else
            {
                Node *ptr=exist_key(k);
                if(ptr==NULL){std::cout<<"Node With "<<k<<" Key Value Doesn't Exist\n";}
                else
                {
                    if(ptr->next==NULL)
                    {
                        ptr->previous->next=NULL;
                        std::cout<<"Node Unlinked\n";
                    }
                    else
                    {
                        ptr->next->previous=ptr->previous;
                        ptr->previous->next=ptr->next;
                        std::cout<<"Node Unlinked\n";
                    }
                }
            }
        }

        void update_data_by_key(int k, int data)
        {
            Node *ptr=exist_key(k);
            if(ptr==NULL){std::cout<<"Node Doesn't Exist\n";}
            else
            {
                ptr->data=data;
                std::cout<<"Data Updated\n";
            }
        }

        void printlist()
        {
            Node *ptr=head;
            if(ptr==NULL){std::cout<<"Double Linkedlist is Empty\n";}
            else
            {
                do
                {
                    std::cout<<"Key ="<<ptr->key<<" Data ="<<ptr->data<<std::endl;
                    ptr=ptr->next;
                }while(ptr!=NULL);
            }
        }
};

int main ()
{
    Double_Linkedlist d;
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
            d.append(n1);
            break;

            case 2:
            std::cout<<"Prepend Mode Operation \n Enter Key & Data Of The Node to Be Prepend\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            n1->key=key1;
            n1->data=data1;
            d.prepend_node(n1);
            break;

            case 3:
            std::cout<<"Insert Node After Operation \n Enter Key Of Existing Node After Which You Want To Insert =";
            std::cin>>k1;
            std::cout<<"Enter Key & Data Of The Node to Be Insert\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            n1->key=key1;
            n1->data=data1;
            d.insert_node_after(n1,k1);
            break;

            case 4:
            std::cout<<"Delete Node By Key operation\n Enter Node Key You Want to Delete\n";
            std::cout<<"key ="; std::cin>>key1;
            d.delete_node(key1);
            break;

            case 5:
            std::cout<<"Update Node By Key\nEnter Key Node And New Data To Be Updated\n";
            std::cout<<"Key ="; std::cin>>key1;
            std::cout<<"Data ="; std::cin>>data1;
            d.update_data_by_key(key1,data1);
            break;

            case 6:
            d.printlist();
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