#include<iostream>
#include<string.h>
#define max 50
using namespace std;
class stack
{
    private:
    char a[max];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    void push(char c);
    void reverse();
    void convert(char str[]);
    void palindrome();
};
void stack::push(char c)
{
    top++;
    a[top]=c;
    a[top+1]='\0';
    cout<<endl<<c<<" is pushed on stack.";
}
void stack::reverse()
{
    char str[max];
    int i,j=0;
    for(i=top,j=0;i>=0;i--,j++)
    {
        cout<<a[i];
        str[i]=a[i];
    }
    cout<<endl;
    cout<<"The reverse string is "<<str<<endl;
}
void stack::convert(char str[])
{
    int j=0,k=0,len=strlen(str);
    for(j=0,k=0;j<len;j++)
    {
        if(((int)str[j]>=65 && (int)str[j]<=90) || ((int)str[j]>=97 && (int)str[j]<=122))
        {
            if((int)str[j]<=90)
            {
                str[k]=(char)((int)str[j]+32);
            }
            else
            {
                str[k]=str[j];
            }
        }
        k++;
    }
    str[k]='\0';
    cout<<"\nThe converted string is "<<str<<endl;
}
void stack::palindrome()
{
    char str[max];
    int i,j;
    for(i=top,j=0;i>=0;i--,j++)
    {
        str[j]=a[i];
    }
    str[j]='\0';
    if(strcpy(str,a)==0)
    {
        cout<<"\nThe given string is palindrome\n";
    }
    else
    {
        cout<<"\nThe given string is not palindrome\n";
    }
}
int main()
{
    stack stk;
    char str[max];
    cout<<"enter the string that is to br converted :";
    cin.getline(str,max);
    stk.convert(str);
    int i=0;
    while(str[i]!='\0')
    {
        stk.push(str[i]);
        i++;
    }
    stk.palindrome();
    stk.reverse();
    return 0;
}