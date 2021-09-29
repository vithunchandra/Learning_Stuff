#include <iostream>
#include <stack>
#include <string>

int predesence(char s)
{   
    if(s=='(' || s==')'){return -1;}
    else if(s=='+' || s=='-'){return 1;}
    else if(s=='*' || s=='/'){return 2;}
    else if(s=='^'){return 3;}
}

std::string Infix_to_Prefix(std::stack <char> s, std::string infix)
{
    int size=infix.size();
    int infix_size=size;
    char temp;
    std::string prefix;
    std::string reverse_infix;
    for(int i=infix_size; i>0; i--)
    {
        if(infix[i-1]=='('){reverse_infix.push_back(')');}
        else if(infix[i-1]==')'){reverse_infix.push_back('(');}
        else{reverse_infix+=infix[i-1];}
    }
    int size_2=reverse_infix.size();
    for(int i=0; i<size_2; i++)
    {
        if((reverse_infix[i]>='a' && reverse_infix[i]<='z') || (reverse_infix[i]>='A' && reverse_infix[i]<='Z') || (reverse_infix[i]>='0' && reverse_infix[i]<='9')){prefix.push_back(reverse_infix[i]);}
        else if(reverse_infix[i]=='('){s.push(reverse_infix[i]);}
        else if(reverse_infix[i]==')')
        {
            temp=s.top();
            while(temp!='(')
            {
                prefix.push_back(temp);
                s.pop();
                temp=s.top();
            }
            if(s.top()=='('){s.pop();}
        }
        else if(reverse_infix[i]=='+' || '-' || '*' || '/' || '^')
        {
            if(s.empty()){s.push(reverse_infix[i]);}
            else if((predesence(reverse_infix[i])==predesence(s.top())) && (reverse_infix[i]=='^'))
            {
                prefix.push_back(s.top());
                s.pop();
                s.push(reverse_infix[i]);
            }
            else if(predesence(reverse_infix[i])==predesence(s.top())){s.push(reverse_infix[i]);}
            else if(predesence(reverse_infix[i])>predesence(s.top()))
            {
                s.push(reverse_infix[i]);
            }
            else if(predesence(reverse_infix[i])<predesence(s.top()))
            {
                while(!s.empty() && predesence(reverse_infix[i])<predesence(s.top()))
                {
                    prefix.push_back(s.top());
                    s.pop();
                }
                s.push(reverse_infix[i]);
            }
        }
    }
    while(!s.empty())
    {
        if((s.top()=='(')){s.pop();}
        else
        {
            prefix.push_back(s.top());
            s.pop();
        }
    }
    std::string reverse_prefix;
    int prefix_size=prefix.size();
    for(int i=prefix_size-1; i>=0; i--)
    {
        reverse_prefix+=prefix[i];
    }
    
    return reverse_prefix;
}

int main()
{
    std::string infix,prefix;
    std::stack <char> s;
    std::cout<<"Insert Formula in Infix State ="; std::cin>>infix;
    prefix=Infix_to_Prefix(s,infix);
    std::cout<<"Prefix ="<<prefix<<std::endl;

    return 0;
}