#include <iostream>
#include<cstring>
#include <stack>

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
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
    int isOperand(char x)
    {
        if(x=='+' || x=='-' || x=='*'  || x=='/' || x=='^' || x=='(' || x==')')
        {
            return 0;
        }
        return 1;
    }
    int outprecedance(char x)
    {
        if(x=='+' || x=='-')
        {
            return 1;
        }
        else if(x=='*' || x=='/')
        {
            return 3;
        }
        else if(x=='^')
        {
            return 6;
        }
        else if(x=='(')
        {
            return 7;
        }
        else if(x==')')
        {
            return 0;
        }
    }
    int inprecedance(char x)
    {
        if(x=='+' || x=='-')
        {
            return 2;
        }
        else if(x=='*' || x=='/')
        {
            return 4;
        }
        else if(x=='^')
        {
            return 5;
        }
        else if(x=='(')
        {
            return 0;
        }

    }
    char* convert(char* infix)
    {
        char *postfix=new char[strlen(infix+1)];
        stack<char> stk;
        int i=0;
        int j=0;

        while(infix[i]!='\0')
        {
            if(isOperand(infix[i]))
                 postfix[j++]=infix[i++];
            else{
                if(stk.empty() || outprecedance(infix[i])>inprecedance(stk.top()))
                {
                    stk.push(infix[i]);
                }
                else if(outprecedance(infix[i]==inprecedance(stk.top())))
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
        while(!stk.empty() && stk.top()==')')
        {
            postfix[j++]=stk.top();
            stk.pop();
        }
        postfix[j]='\0';
        return postfix;

    }
};
Stack::Stack()
{
    top=nullptr;
}
Stack::~Stack()
{
    Node *p=top;
    top=top->next;
    delete p;
    p=top;
}
void Stack::push(int x)
{
    Node *t=new Node;
    if(t==nullptr)
    {
        cout<<"Stack overflow";
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }



}
int Stack::pop()
{
    Node *p;
    int x=-1;
    if(p==nullptr)
    {
        cout<<"Stack underflow";
    }
    else{
        p=top;
        x=p->data;
        top=top->next;
        delete p;
    }
    return x;
}
int Stack::isFull()
{
    Node *p=new Node;
    int r= p ? 1 : 0;
    delete p;
    return r;
}
int Stack::isEmpty()
{
    return top ? 0 : 1;

}
int Stack::stackTop()
{
    if(top)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    
    char infix[] = "((a+b)*c)-d^e^f";
    Stack stk;
 
    cout << stk.convert(infix) << endl;
}
