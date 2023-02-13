#include<iostream>
#include<string.h>
#define max 10
using namespace std;
class q
{
    private:
    int front,data[max],rear;
    public:
    q()
    {
        front=rear=-1;
    }
    void aadq(int x);
    int delq();
    void display();
};
void  q::aadq(int x)
{
    if(rear==max-1)
    {
        cout<<"Queue is full so cannot insert the job";
        return;
    }
    else if(rear==-1)
    {
        front=rear=0;
        data[rear]=x;
    }
    else
    {
        rear++;
        data[rear]=x;
    }
    
} 
int q::delq()
{
    if(front==-1)
    {
        cout<<"Queue is empty";
    }
    else if(front==rear)
    {
        int x=data[front];
        front=rear=-1;
        return x;
    }
    else
    {
        int x=data[front];
        front++;
        return x;
    }
}
void q::display()
{
    if(front==-1)
    {
        cout<<"Queue is empty";
    }
    else
    {
        cout<<"\n*****QUEUE*****\n";
        for(int i=front;i<=rear;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    q y;
    int ch;
    do
    {
        cout<<"\n*******MENU******\n";
        cout<<"1.Add job\n2.Delete job\n3.Display\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int ele;
                cout<<"Enter the element : ";
                cin>>ele;
                y.aadq(ele);
                break;
            }
            case 2:
            {
                int s=y.delq();
                cout<<"\nThe deleted element is "<<s<<endl;
                break;
            }
            case 3:
            {
                y.display();
                break;
            }
            default:
            cout<<"invalid choice";
        }
    } while (ch!=4);
    return 0;
    
}