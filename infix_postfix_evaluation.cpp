#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
using namespace std;
#define max 50
char stack[max];
int top=-1;
void push(char c)
{
    stack[++top]=c;
}
char pop()
{
    return(stack[top--]);
}
int pr(char s)
{
    switch(s)
    {
        case '#':return 0;
        case '(':return 1;
        case '-':
        case '+':return 2;
        case '*':
        case '/':return 3;
    }
}
int isOperand(char s)
{
    if(s=='+' || s=='-' || s=='*' || s=='/' || s=='(' || s==')')
    {
        return 0;
    }
    return 1;
}
int isDigit(int x)
{
    if(x=='1' ||x=='0' || x=='2' || x=='3' || x=='4' || x=='5' || x=='6' || x=='7' || x=='8' || x=='9')
    {
        return 1;
    }
    return 0;
}
int main()
{
    char infix[max],postfix[max],ch,ele;
    int i=0,j=0;
    cout<<"\nEnter the infix expression:\t";
    cin>>infix;
    push('#');
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else
        {
            if(isOperand(ch))
            {
                postfix[j++]=ch;
            }
            else
            {
                if(ch==')')
                {
                    while(stack[top]!='(')
                    {
                        postfix[j++]=pop();
                    }
                    ele=pop();
                }
                else
                {
                    while(pr(stack[top])>=pr(ch))
                    {
                        postfix[j++]=pop();
                    }
                    push(ch);
                }
            }
            
        }
    }
    while((stack[top])!='#')
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    cout<<"\nThe postfix expression :\t"<<postfix<<endl;

    return 0;
}
