#include<iostream>
#include<conio.h>
using namespace std;
class stack
{
    public:
    char stack_array[50];
    int top;
    stack()
    {
        top=-1;
    }
    void push(char symbol)
    {
        if(full())
        {
            cout<<"Stack is overflow";
        }
        else
        {
            top++;
            stack_array[top]=symbol;
        }
    }
    char pop()
    {
        if(empty())
        {
            cout<<"Stack is empty.";
            return('#');
        }
        else
        {
            return stack_array[top--];
        }
    }
    int full()
    {
        if(top==49)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int empty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    private:
    char infix[50];
    char postfix[50];
    public:
    void read()
    {
        cout<<"Enter the infix expression: ";
        cin>>infix;
    }
    int White_space(char symbol)
    {
        if(symbol==' ' || symbol=='\t' || symbol=='\0')
        {
            return 1;
        }
        return 0;
    }
    int prior(char symbol)
    {
        switch(symbol)
        {
            case '/':return(4);
            case '*':return(3);
            case '+':return(2);
            case '-':return(1);
            case '(':return(0);
            default:return -1;
        }
    }
    void convertTOpostfix()
    {
        int prority,p;
        p=0;
        char entry;
        for(int i=0;infix[i]!='\0';i++)
        {
            if(!White_space(infix[i]))
            {
                switch(infix[i])
                {
                    case '(':push(infix[i]);
                             break;
                    case ')':while(entry=pop()!='(')
                             postfix[p++]=infix[i];
                             break;
                    case '/':
                    case '*':
                    case '+':
                    case '-':
                    if(!empty())
                    {
                        prority=prior(infix[i]);
                        entry=pop();
                        while(prority<=prior(entry))
                        {
                            postfix[p++]=entry;
                            if(!empty())
                            {
                                entry=pop();
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(prority>prior(entry))
                        {
                            push(entry);
                        }
                    }
                    push(infix[i]);
                    break;
                    default:postfix[p++]=infix[i];
                }
            }
        }
        while(!empty())
        {
            postfix[p++]=pop();
        }
        postfix[p]='\0';
        cout<<"\nPostfix expression :"<<postfix<<endl;
    }


};
int main()
{
    stack k;
    char ch='y';
    while(ch=='y')
    {
        k.read();
        k.convertTOpostfix();
        cout<<"do you want continue(y/n): ";
        cin>>ch;
    }
    return 0;
}