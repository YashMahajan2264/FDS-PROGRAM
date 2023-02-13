#include<iostream>
#include<math.h>
#include<string.h>
#define max 50
using namespace std;
int isDigit(int x)
{
    if(x=='1' ||x=='0' || x=='2' || x=='3' || x=='4' || x=='5' || x=='6' || x=='7' || x=='8' || x=='9')
    {
        return 1;
    }
    return 0;
}
int stack[max];
int top=-1;
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    return(stack[top--]);
}

int main()
{
    int n1,n2,n3,num;
    char exp[max];
    char *e;
    cout<<"\nEnter the given postfix expression";
    cin>>exp;
    e=exp;
    while(*e!='\0')
    {
        if(isDigit(*e))
        {
            num=*e-48;
            push(num);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(*e)
            {
                case '+':
                {
                    n3=n2+n1;
                    break;
                }
                case '-':
                {
                    n3=n2-n1;
                    break;
                }
                case '*':
                {
                    n3=n2*n1;
                    break;
                }
                case '/':
                {
                    n3=n2/n1;
                    break;
                }

            }
            push(n3);
        }
        e++;
    }
    cout<<"\nThe result of expression:\n"<<exp<<":\t"<<pop();
    
    return 0;
}
