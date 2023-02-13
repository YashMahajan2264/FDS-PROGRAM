#include<iostream>
#include<cstdio>
#include<cstdlib>
#define max 50
using namespace std;
char s[max];
int top=-1;
void push(char c)
{
    s[++top]=c;
}
char pop()
{
    return(s[top--]);
}
int pr(char m)
{
    switch(m)
    {
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 3;
    }
}
int isOperand(char x)
{
    if(x=='/' || x=='+' || x=='-' || x=='*' || x=='(' || x==')' ||x=='^')
    {
        return 0;
    }
    return 1;
}
int main()
{
    int i=0,j=0;
    char infix[max],postfix[max],ch,ele;
    cout<<"Enter the infix expression:";
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
                    while(s[top]!='(')
                    {
                        postfix[j++]=pop();
                    }
                    ele=pop();
                }
                else
                {
                    while(pr(s[top])>=pr(ch))
                    {
                        postfix[j++]=pop();
                    }
                    push(ch);
                }
            }
        }
    }
    while((s[top])!='#')
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    cout<<"\nThe postfix expression is \n\n"<<postfix<<endl;
}