#include<iostream>
#include<string.h>
#define max 50
using namespace std;


class STACK
{
    private:
    char a[max];
    int top;

    public:
    STACK()
    {
        top=-1;
    }
    void push(char);
    void reverse();
    void convert(char []);
    void palinderome();

};
void STACK::push(char c)
{
    top++;
    a[top]=c;
    a[top+1]='\0';
    cout<<c<<"is pushed on stack"<<endl;
}
void STACK::reverse()
{
    char str[max];
    int i,j;
    cout<<"Reverse string is"<<endl;
    for(i=top,j=0;i>=0;i--,j++)
    {
        cout<<a[i];
        str[j]=a[i];

    }
    cout<<endl;
}
void STACK::convert(char str[])
{
    int j,k,len=strlen(str);
    for(j=0,k=0;j<len;j++)
    {
        if(((int)str[j]>=97 && (int)str[j]<=122) || ((int)str[j]>=65 && (int)str[j]<=90))
        {
            if((int)str[j]<=90)
            {
                str[k]=(char)((int)str[j]+32);
            }
        }
        else
        {
            str[k]=str[j];
        }
        k++;
    }
    str[k]='\0';

    cout<<"The converted string is "<<str<<endl;
}
void STACK::palinderome()
{
    char str[max];
    int i,j;
    for(i=top,j=0;i>=0;i--,j++)
    {
        str[j]=a[i];
    }
    str[j]='\0';

    if(strcmp(str,a)==0)
    {
        cout<<"The given string is palindrone.";
    }
    else
    {
        cout<<"The given string is not palindrome.";
    }
}
int main()
{
    STACK stk;
    int i=0;
    char str[max];
    cout<<"Enter the string to get converted and checked for palindrome"<<endl;
    cin.getline(str,50);
    stk.convert(str);
    while(str[i]!='\0')
    {

        stk.push(str[i]);
        i++;
    }
    stk.reverse();
    stk.palinderome();
    return 0;
}