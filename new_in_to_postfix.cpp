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
int pr(char ele)
{
    switch(ele)
    {
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 3;
    }
}
int main()
{
    char  infix[max],postfix[max],ch,element;
    int i=0,k=0;
    cout<<"\nEnter the infix expression: ";
    cin>>infix;
    push('#');
    while((ch=infix[i++])!='\0')
    {
        if(ch == '(')
            push(ch);
        else
        {
            if(isalnum(ch))
                postfix[k++]=ch;
            else
            {
                if(ch==')')
                {
                    while(s[top]!='(')
                       postfix[k++]=pop();
                    element=pop();
                }
                else
                {
                    while(pr(s[top])>=pr(ch))
                       postfix[k++]=pop();
                    push(ch);
                }
            }
        }
            

    }
    while(s[top]!='#')
       postfix[k++]=pop();
    postfix[k]='\0';
    cout<<endl<<"The postfix expression is "<<postfix<<endl;
    return 0;
}