#include <iostream>
#define Spaces 5;
class TreeNode
{
    public:
        int value;
        TreeNode *left;
        TreeNode *right;

        TreeNode()
        {
            value=0;
            left=NULL;
            right=NULL;
        }
        TreeNode(int v)
        {
            value=v;
            left=NULL;
            right=NULL;
        }
};

class BST
{
    public:
        TreeNode *Root;

        BST(){Root=NULL;}

        bool Is_Empty()
        {
            if(Root==NULL){return true;}
            else{return false;}
        }

        TreeNode *Left_left(TreeNode *ptr)
        {
            TreeNode *temp=ptr->left;
            ptr->left=temp->right;
            temp->right=ptr;
            ptr=temp;
            std::cout<<"ptr="<<ptr<<std::endl;
            return ptr;
        }

        TreeNode *Right_right(TreeNode *ptr)
        {
            TreeNode *temp=ptr->right;
            ptr->right=temp->left;
            temp->left=ptr;
            ptr=temp;
            std::cout<<"ptr="<<ptr<<std::endl;
            return ptr;
        }

        TreeNode *Left_right(TreeNode *ptr)
        {
            TreeNode *temp=ptr->left->right;
            TreeNode *temp_2=temp->left;
            ptr->left->right=temp_2;
            temp->left=ptr->left;
            ptr->left=temp;
            ptr=Left_left(ptr);
            return ptr;
        }

        TreeNode *Right_left(TreeNode *ptr)
        {
            TreeNode *temp=ptr->right->left;
            TreeNode *temp_2=temp->right;
            ptr->right->left=temp_2;
            temp->right=ptr->right;
            ptr->right=temp;
            ptr=Right_right(ptr);
            return ptr;
        }

        void Insertion(TreeNode *n)
        {
            if(Root==NULL){Root=n; std::cout<<"Value Appended As Root\n"; return;}
            else
            {
                TreeNode *ptr=Root;
                while(ptr!=NULL)
                {
                    if(n->value == ptr->value){std::cout<<"Value Already Exist, Input Another Value\n"; return;}
                    else if((n->value < ptr->value) && (ptr->left == NULL)){ptr->left=n; std::cout<<"Value Inserted To The Left\n"; break;}
                    else if(n->value < ptr->value){ptr=ptr->left;}
                    else if((n->value > ptr->value) && (ptr->right == NULL)){ptr->right=n; std::cout<<"Value Inserted To The Right\n"; break;}
                    else{ptr=ptr->right;}
                }
            }
        }

        TreeNode *Insertion_Recursive(TreeNode *ptr, TreeNode *n)
        {
            if(Root==NULL)
            {
                Root=n;
                std::cout<<"Insertion Success\n";
                return Root;
            }
            else if(ptr==NULL)
            {
                ptr=n; 
                std::cout<<"Insertion Success\n";
                return ptr;
            }
            else
            {
                if(n->value<ptr->value){ptr->left=Insertion_Recursive(ptr->left,n);}
                else if(n->value>ptr->value){ptr->right=Insertion_Recursive(ptr->right,n);}
                else{std::cout<<"Duplicate Value Not Allowed\n"; return ptr;}
            }

            int dif_height=(Height(ptr->left))-(Height(ptr->right));
            if(dif_height>1 && n->value < ptr->left->value){ptr=Left_left(ptr);}
            else if(dif_height<-1 && n->value > ptr->right->value){ptr=Right_right(ptr);}
            else if(dif_height>1 && n->value > ptr->left->value){ptr=Left_right(ptr);}
            else if(dif_height<-1 && n->value < ptr->right->value){ptr=Right_left(ptr);}
            return ptr;
        }

        TreeNode *Search(int value)
        {
            if(Is_Empty()){return NULL;}
            else
            {
                TreeNode *ptr=Root;
                while(ptr!=NULL)
                {
                    if(ptr->value==value){return ptr;}
                    else if(ptr->value<value){ptr=ptr->right;}
                    else{ptr=ptr->left;}
                }
                return NULL;
            }
        }

        void Pre_Order_Search(TreeNode *n)
        {
            TreeNode *ptr=n;
            if(ptr==NULL){return;}
            std::cout<<ptr->value<<", ";
            Pre_Order_Search(ptr->left);
            Pre_Order_Search(ptr->right);
        }

        void In_Order_Search(TreeNode *n)
        {
            TreeNode *ptr=n;
            if(ptr==NULL){return;}
            Pre_Order_Search(ptr->left);
            std::cout<<ptr->value<<", ";
            Pre_Order_Search(ptr->right);
        }

        void Post_Order_Search(TreeNode *n)
        {
            if(n==NULL){return;}
            Post_Order_Search(n->left);
            Post_Order_Search(n->right);
            std::cout<<n->value<<", ";
        }

        void print2D (TreeNode *n, int s)
        {
            if(n==NULL){return;}
            int space=s+Spaces;
            print2D(n->right,space);
            std::cout<<"\n";
            for (int j=5;j<space;j++){std::cout<<" ";}
            std::cout<<n->value<<std::endl;
            print2D(n->left,space);
        }

        int Height(TreeNode *n)
        {
            if(n==NULL){return -1;}
            else
            {
                int lheight=Height(n->left);
                int rheight=Height(n->right);
                if(lheight>rheight){return lheight+1;}
                else{return rheight+1;}
            }
        }
        void height_ptr()
        {
            int height=Height(Root);
            if(height==-1){return;}
            else
            {
                for(int i=height; i>=0; i--){BFS(Root,i);}
            }
        }
        
        void BFS(TreeNode *n, int height)
        {
            if(n==NULL){return;}
            if(height==0){std::cout<<n->value<<", "; return;}
            BFS(n->left, height-1);
            BFS(n->right, height-1);
        }

        TreeNode *Get_left(TreeNode *ptr)
        {
            while(ptr->right!=NULL){ptr=ptr->right;}
            return ptr;
        }

        TreeNode *Get_right(TreeNode *ptr)
        {
            while(ptr->left!=NULL){ptr=ptr->left;}
            return ptr;
        }

        TreeNode *DeleteNode(TreeNode *ptr, int value)
        {
            if(ptr==NULL){return NULL;}
            else if(value<ptr->value){ptr->left=DeleteNode(ptr->left,value);}
            else if(value>ptr->value){ptr->right=DeleteNode(ptr->right,value);}
            else
            {
                if(ptr->left==NULL)
                {
                    TreeNode *temp=ptr->right;
                    delete ptr;
                    return temp;
                }
                else if(ptr->right==NULL)
                {
                    TreeNode *temp=ptr->left;
                    delete ptr;
                    return temp;
                }
                else
                {
                    TreeNode *left_ptr=Get_left(ptr->left);
                    TreeNode *right_ptr=Get_right(ptr->right);
                    int left=ptr->value-left_ptr->value;
                    int right=right_ptr->value-ptr->value;
                    if(left<=right)
                    {
                        ptr->value=left_ptr->value;
                        ptr->left=DeleteNode(ptr->left,left_ptr->value);
                    }
                    else if(right<=left)
                    {
                        ptr->value=right_ptr->value;
                        ptr->right=DeleteNode(ptr->right,right_ptr->value);
                    }
                }
            }
            int dif_height=(Height(ptr->left))-(Height(ptr->right));
            if(dif_height>1 && ptr->left->left!=NULL){ptr=Left_left(ptr);}
            else if(dif_height<-1 && ptr->right->right!=NULL){ptr=Right_right(ptr);}
            else if(dif_height>1 && ptr->left->left==NULL){ptr=Left_right(ptr);}
            else if(dif_height<-1 && ptr->right->right==NULL){ptr=Right_left(ptr);}
            return ptr;
        }
};
int main ()
{
    BST bst;
    int option,value;
    do
    {
        std::cout<<"What Opertion Do You Want To Perform?\n";
        std::cout<<"1. Insert Node\n";
        std::cout<<"2. Search Node\n";
        std::cout<<"3. Delete Node\n";
        std::cout<<"4. Print Binary Search Tree Values\n";
        std::cout<<"5. Clear Screen\n";
        std::cout<<"0. Exit Program\n";
        std::cout<<"Select ="; std::cin>>option;

        TreeNode *n=new TreeNode();

        switch(option)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                std::cout<<"Input Value Of The Node To Be Inserted ="; std::cin>>value;
                n->value=value;
                bst.Root=bst.Insertion_Recursive(bst.Root,n);
                break;
            }
            case 2:
            {
                std::cout<<"Input Value Of Node To Search ="; std::cin>>value;
                n=bst.Search(value);
                if(n!=NULL)
                {
                    std::cout<<"Node Found. Node Value Is ="<<n->value<<std::endl;
                }
                else{std::cout<<"Node With Value Of "<<value<<"Isn't Exist\n";}
                break;
            }
            case 3:
            {
                if(bst.Is_Empty()){std::cout<<"Tree Is Empty\n";}
                else
                {
                    std::cout<<"Input Value Of Node To Delete ="; std::cin>>value;
                    n=bst.Search(value);
                    if(n==NULL){std::cout<<"Node Not Found\n";}
                    else
                    {
                        bst.Root=bst.DeleteNode(bst.Root,value);
                        std::cout<<"Node Deleted\n";
                    }
                }
                break;
            }
            case 4:
            {
                bst.print2D(bst.Root,5);
                std::cout<<"(";
                bst.height_ptr();
                std::cout<<")\n";
                std::cout<<"Height Of Three Is ="<<bst.Height(bst.Root)<<std::endl;
                break;
            }
            case 5:
            {
                system("CLS");
                break;
            }
            default:
            {
                std::cout<<"Invalid Input\n";
                break;
            }
        }
    }while(option!=0);

    return 0;
}