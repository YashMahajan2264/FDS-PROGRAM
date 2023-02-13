#include<iostream>
#include<string.h>
#define max 50
using namespace std;
class Stack
{
    private:
    char a[max];
    int top;

    public:
    Stack()
    {
        top=-1;
    }
    void push(char s);
    void reverse();
    void convert(char str[]);
    void palindrome();
};
void Stack::push(char s)
{
    top++;
    a[top]=s;
    a[top+1]='\0';
    cout<<endl<<s<<" is pushed onto stack";
}
void Stack::reverse()
{
    char str[max];
    cout<<"\nReverse string is...\n";
    for(int i=top,j=0;i>=0;i--,j++)
    {
        cout<<a[i];
        str[j]=a[i];
    }
    cout<<endl;
}
void Stack::convert(char str[])
{
    int j=0,k=0,len=strlen(str);
    for(int j=0,k=0;j<len;j++)
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
            k++;
        }
        
    }
    str[k]='\0';
    cout<<endl<<"the converted strind is "<<str<<endl;
}
void Stack::palindrome()
{
    char str[max];
    int j=0;
    for(int i=top,j=0;i>=0;i--,j++)
    {
        str[j]=a[i];
    }
    str[j]='\0';
    if(strcmp(str,a)==0)
    {
        cout<<"the given string is palindrome..";
    }
    else
    {
        cout<<"the given string is not palindrome..";
    }
}
int main()
{
   Stack stk;
   char str[max];
   cout<<"Enter the string to be converted:";
   cin.getline(str,50);
   int i=0;
   stk.convert(str);
   while(str[i]!='\0')
   {
    stk.push(str[i]);
    i++;
   } 
   stk.palindrome();
   stk.reverse();
   return 0;
}