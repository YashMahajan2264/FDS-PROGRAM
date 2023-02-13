#include<iostream>
#include<windows.h>
#define max 50
using namespace std;
class dequeue
{
    private:
    int front,rear;
    int data[max];

    public:
    dequeue()
    {
        front=rear=-1;
    }
    void enqueuefront(int x);
    void enqueuerear(int x);
    void dequeuefront();
    void dequeuerear();
    void display();
};
void dequeue::enqueuefront(int x)
{
    if(front==-1)
    {
        front=rear=0;
        data[front]=x;
    }
    else if(front==0)
    {
        cout<<"\nCan not inserted at front\n";
        return;
    }
    else
    {
        front--;
        data[front]=x;
    }
}
void dequeue::enqueuerear(int x)
{
    if(rear==max-1)
    {
        cout<<"\nCan not inserted at rear\n";
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
void dequeue::dequeuefront()
{
    if(front==-1)
    {
        cout<<"\nqueue is empty\n";
        return;
    }
    else if(front==rear)
    {
        int y=data[front];
        front=rear=-1;
        cout<<"\nThe deleted element is "<<y<<endl;
    }
    else
    {
        int y=data[front];
        front++;
        cout<<"\nThe deleted element is "<<y<<endl;
    }
}
void dequeue::dequeuerear()
{
     if(rear==-1)
    {
        cout<<"\nqueue is empty\n";
        return;
    }
    else if(front==rear)
    {
        int y=data[front];
        front=rear=-1;
        cout<<"\nThe deleted element is "<<y<<endl;
    }
    else
    {
        int y=data[rear];
        rear--;
        cout<<"\nThe deleted element is "<<y<<endl;
    }
}
void dequeue::display()
{
    if(front!=-1)
    {
        for(int i=front;i!=rear;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<data[rear]<<endl;
    }
}
int main()
{
    dequeue yaah;
    int ch;
    do
    {
        cout<<"\n***************\n";
        cout<<"******MENU********\n";
        cout<<"1.Enqueuefront\n2.Enqueuerear\n3.Dequeuefront\n4.Dequeuerear\n5.Display\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int y;
                cout<<"\nEnter data element :";
                cin>>y;
                yaah.enqueuefront(y);
                yaah.display();
                break;
            }
            case 2:
            {
                int y;
                cout<<"\nEnter the data element: ";
                cin>>y;
                yaah.enqueuerear(y);
                yaah.display();
                break;
            }
            case 3:
            {
                yaah.dequeuefront();
                break;
            }
            case 4:
            {
                yaah.dequeuerear();
                break;
            }
            case 5:
            {
                yaah.display();
                break;
            }
            default:
            {
                cout<<"INVALID CHOICE";
            }
        }
    } while (ch!=6);
    return 0;
    
}