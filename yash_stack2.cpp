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
    void plaindrome();
};
void stack::push(char c)
{
    top++;
    a[top]=c;
    a[top+1]='\0';
    cout<<"\n"<<c<<" is pushed on to stack";
}
void stack::reverse()
{
    char str[max];
    cout<<"\nREVERSE STRING :\n";
    for(int i=top,j=0;i>=0;i--,j++)
    {
        cout<<a[i];
        str[j]=a[i];
    }
    cout<<endl;
}
void stack::convert(char str[])
{
    int j=0,k=0,len=strlen(str);
    for(j=0,k=0;j<len;j++)
    {
        if(((int)str[j]>=97 && (int)str[j]<=122) || ((int)str[j]>=65 && (int)str[j]<=90))
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
    cout<<endl<<"The converted string is "<<endl<<str<<endl;
}
void stack::plaindrome()
{
    char str[max];
    int j;
    for(int i=top,j=0;i>=0;i--,j++)
    {
        str[j]=a[i];
    }
    str[j]='\0';
    if(strcmp(str,a)==0)
    {
        cout<<"\nThe given string is plaindrome\n";
    }
    else
    {
        cout<<"\nThe given string is not plaindrome\n";
    }
}
int main()
{
    stack stk;
    char str[max];
    cout<<"\nEnter the string to be converted and reverse and also check for the plaindrome\n\n";
    cin.getline(str,max);
    stk.convert(str);
    int i=0;
    while(str[i]!='\0')
    {
        stk.push(str[i]);
        i++;
    }
    stk.plaindrome();
    stk.reverse();
    return 0;
}