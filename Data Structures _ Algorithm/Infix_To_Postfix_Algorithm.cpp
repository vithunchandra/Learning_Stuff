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

std::string Infix_to_Postfix(std::stack <char> s, std::string infix)
{
    int size=infix.size();
    char temp;
    std::string postfix;
    for(int i=0; i<size; i++)
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') || (infix[i]>='0' && infix[i]<='9')){postfix.push_back(infix[i]);}
        else if(infix[i]=='('){s.push(infix[i]);}
        else if(infix[i]==')')
        {
            temp=s.top();
            while(temp!='(' && !s.empty())
            {
                postfix.push_back(temp);
                s.pop();
                temp=s.top();
            }
            if(s.top()=='('){s.pop();}
        }
        else if(infix[i]=='+' || '-' || '*' || '/' || '^')
        {
            if(s.empty()){s.push(infix[i]);}
            else if((predesence(infix[i])==predesence(s.top())) && (infix[i]=='^')){s.push(infix[i]);}
            else if(predesence(infix[i])>predesence(s.top())){s.push(infix[i]);}
            else
            {
                while(!s.empty() && predesence(infix[i])<=predesence(s.top()))
                {
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
    }
    while(!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}

int main()
{
    std::string infix,postfix;
    std::stack <char> s;
    std::cout<<"Insert Formula in Infix State ="; std::cin>>infix;
    postfix=Infix_to_Postfix(s,infix);
    std::cout<<"Postfix ="<<postfix<<std::endl;

    return 0;
}