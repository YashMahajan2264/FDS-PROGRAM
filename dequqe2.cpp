#include<iostream>
using namespace std;
class q
{
    private:
    int front,rear;
    int data[10];
    public:
    q()
    {
        front=rear=-1;
    }
    void enqueuefront(int y);
    void enqueuerear(int y);
    void dequeuefront();
    void dequeuerear();
    void display();
};
void q::enqueuefront(int y)
{
    if(front==-1)
    {
        front=rear=0;
        data[front]=y;
    }
    else if(front==0)
    {
        cout<<"\nCannot inserted at front\n";
    }
    else
    {
        front--;
        data[front]=y;
    }
}
void q::enqueuerear(int y)
{
    if(rear==-1)
    {
        front=rear=0;
        data[rear]=y;
    }
    else if(rear==9)
    {
        cout<<"\nCan not inserted at rear\n";
    }
    else
    {
        rear++;
        data[rear]=y;
    }
}
void q::dequeuefront()
{
    if(front==-1)
    {
        cout<<"\nQueue is empty\n";
    }
    else if(front==rear)
    {
        int x=data[front];
        front=rear=-1;
        cout<<"\nThe deleted element is "<<x<<endl;
    }
    else
    {
        int x=data[front];
        front++;
        cout<<"\nThe deleted element is "<<x<<endl;
    }
}
void q::dequeuerear()
{
    if(rear==-1)
    {
        cout<<"\nQueue is empty\n";
    }
    else if(front==rear)
    {
        int x=data[rear];
        front=rear=-1;
        cout<<"\nThe deleted element is "<<x<<endl;
    }
    else
    {
        int x=data[rear];
        rear--;
        cout<<"\nThe deleted element is "<<x<<endl;
    }
}
void q::display()
{
    if(front==-1)
    {
        cout<<"\nQueue is empty\n";
    }
    else
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
    int ch;
    q y;
    do
    {
        cout<<"\n********MENU*******\n";
        cout<<"1.Enqueue front\n2.Enqueue rear\n3.Dequeue front\n4.Dequeue rear\n5.Display\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int m;
                cout<<"Enter the element yo add :";
                cin>>m;
                y.enqueuefront(m);
                break;
            }
            case 2:
            {
                int m;
                cout<<"Enter the element yo add :";
                cin>>m;
                y.enqueuerear(m);
                break;
            }
            case 3:
            {
                y.dequeuefront();
                break;
            }
            case 4:
            {
                y.dequeuerear();
                break;
            }
            case 5:
            {
                y.display();
                break;
            }
            default:
            cout<<"Invalid choice";

        }
    } while (ch!=6);
    return 0;
    
}