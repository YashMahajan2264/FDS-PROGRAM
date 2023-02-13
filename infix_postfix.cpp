#include<iostream>
#include<string.h>
#include<cstdlib>
#include<cstdio>
#include<math.h>
#define max 50
using namespace std;
char str[max];
int top=-1;
void push(char c)
{
    str[++top]=c;
}
char pop()
{
    return(str[top--]);
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
int isOperand(char x)
{
    if(x=='/'||x=='*'||x=='+'||x=='-'||x=='('||x==')')
    {
        return 0;
    }
    return 1;
}
int main()
{
    char infix[max],postfix[max],ch,ele;
    cout<<"Enter the postfix expression: ";
    cin>>infix;
    push('#');
    int i=0,j=0;
    while((ch==infix[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else
        {
            if(isalnum(ch))
            {
                postfix[j++]=ch;
            }
            else
            {
                if(ch==')')
                {
                    while(str[top]!='(')
                    {
                        postfix[j++]=pop();
                    }
                    ele=pop();
                }
                else
                {
                    while((pr(str[top]))>=(pr(ch)))
                    {
                        postfix[j++]=pop();
                    }
                    push(ch);
                }
            }
        }
    }
    while(str[top]!='#')
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    cout<<"The postfix expression is :"<<postfix<<endl;
    return 0;
}