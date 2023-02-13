#include<iostream>
#include<conio.h>
using namespace std;
class stack
{
    private:
    char infix[50];
    char postfix[50];

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
            cout<<"\nStack is Overflow\n";
        }
        else
        {
            top=top+1;
            stack_array[top]=symbol;
        }
    }
    char pop()
    {
        if(empty())
        {
            return('#');
        }
        else
        {
            return (stack_array[top--]);
        }
    }
    int empty()
    {
        if(top==-1)
           return 1;
        else
           return 0;
    }
    int full()
    {
        if(top==49)
           return 1;
        else
           return 0;
    }
    int isWhitespace(char symbol)
    {
        if(symbol==' ' || symbol=='\t' || symbol=='\0')
           return 1;
        else
           return 0;
    }
    int precedace(char symbol)
    {
        switch(symbol)
        {
            case '/':return 4;
            case '*':return 3;
            case '+':return 2;
            case '-':return 1;
            case '(':return 0;
            default :
              return -1;

        }
        
    }
    void read()
    {
        cout<<"Enter the postfix expression: ";
        cin>>infix;
    }
    void conver_postfix()
    {
        int prior,p;
        p=0;
        char entry;
        for(int i=0;infix[i]!='\0';i++)
        {
            if(!isWhitespace(infix[i]))
            {
                switch(infix[i])
                {
                    case '(':
                    {
                        push(infix[i]);
                        break;
                    }
                    case ')':
                    {
                        while((entry=pop())!='(')
                        {
                            postfix[p++]=entry;
                            break;
                        }

                    }
                    case '/':
                    case '*':
                    case '+':
                    case '-':
                    if(!empty())
                    {
                        prior=precedace(infix[i]);
                        entry=pop();
                        while(prior<=precedace(entry))
                        {
                            postfix[p++]=entry;
                            if(!empty())
                               entry=pop();
                            else 
                               break;
                        }
                        if(prior>precedace(entry))
                        {
                            push(entry);
                        }
                        
                    
                    }
                    push(infix[i]);
                    break;
                    default:
                    {
                        postfix[p++]=infix[i];
                        break;
                    }
                    
                }
            }
        }
        while(!empty())
        {
            postfix[p++]=pop();
        }
        postfix[p]='\0';
        cout<<"The postfix expression: "<<postfix<<endl;
        
    }
};
int main()
{
    char ch='y';
    stack stk;
    while(ch=='y')
    {
        stk.read();
        stk.conver_postfix();
        cout<<"enter your choice(y/n)";
        cin>>ch;
    }
    return 0;
}
