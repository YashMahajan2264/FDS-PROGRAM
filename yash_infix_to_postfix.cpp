#include<iostream>
#include<cstring>
#include<string.h>
#include<stack>
#define Max 30
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
class Stack
{
    private:
    Node *top;
    public:
    Stack()
    {
        top=NULL;
    }
    void push(int x)
    {
        Node *t=new Node();
        if(t==NULL)
        {
            cout<<"Stack is overflow";
        }
        else
        {
            t->data=x;
            t->next=top;
            top=t;
        }
    }
    int pop()
    {
        int x=-1;
        if(top==NULL)
        {
            cout<<"stack is empty";
        }
        else
        {
            x=top->data;
            top=top->next;
            
        }
        return x;
    }
    int isEmpty()
    {
        Node *t=new Node();
        int r= t ? 1 : 0;
        delete t;
        return r;
    }
    int isFull()
    {
        return top ? 0 : 1;
    }
    int stackTop()
    {
        if(top)
        {
            return top->data;
        }
        return -1;
    }
    int isOperand(char x)
    {
        if( x =='+' || x =='-' || x =='*' || x =='/' || x =='^' || x=='(' || x==')')
        {
            return 0;
        }
        return 1;
    }
    int outprecedance(char x)
    {
        if(x=='+' || x=='-')
           return 1;
        else if(x=='*' || x=='/')
        {
            return 3;
        }
        else if(x=='^')
           return 6;
        else if(x=='(')
           return 7;
        else if(x==')')
           return 0;
    }
    int inprecedance(char x)
    {
        if(x=='+' || x=='-')
           return 2;
        else if(x=='*' || x=='/')
           return 4;
        else if(x=='^')
           return 5;
        else if(x=='(')
           return 0;
    }
    char* convert(char* infix)
    {
        char *postfix=new char[strlen(infix)+1];
        int i=0,j=0;
        stack<char> stk;
        while(infix[i]!='\0')
        {
            if(isOperand(infix[i]))
            {
                postfix[j++]=infix[i++];
            }
            else
            {
                if(stk.empty() ||outprecedance(infix[i])>inprecedance(stk.top()))
                {
                   stk.push(infix[i++]);

                }
                else if(outprecedance(infix[i])==inprecedance(stk.top()))
                {
                   stk.pop();
                }
                else
                {
                    postfix[j++]=stk.top();
                    stk.pop();
                }

            }
            
            

        }
        while(!stk.empty() && stk.top()!=')')
            {
                postfix[j++]=stk.top();
                stk.pop();
            }
            postfix[j]='\0';

            return postfix;
            
    }
};
int main()
{
    char infix[]={"((a+b)*c)-d^e^f"};
    Stack stk;
    cout<<stk.convert(infix);
    return 0;
}
