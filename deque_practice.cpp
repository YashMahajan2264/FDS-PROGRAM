#include<iostream>
#define max 10
using namespace std;
class deque
{
    private:
    int front,rear;
    int data[max];

    public:
    deque()
    {
        front=rear=-1;
    }
    void enqeuefront(int x);
    void enqeuerear(int x);
    void deqeuefront();
    void deqeuerear();
    void display();
};
void deque::enqeuefront(int x)
{
    if(front==0)
    {
        cout<<"Can not inserted at front";
        
    }
    else if(front==-1)
    {
        front=rear=0;
        data[front]=x;
    }
    else
    {
        front--;
        data[front]=x;
    }
}
void deque::enqeuerear(int x)
{
    if(rear==max-1)
    {
        cout<<"Can not inserted at rear";
        
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
void deque::deqeuefront()
{
    if(front==-1)
    {
        cout<<"Queue is empty";
    }
    else if(front==rear)
    {
        int x=data[front];
        front=rear=-1;
        cout<<"The deleted element is "<<x<<endl;
    }
    else
    {
        int x=data[front];
        front++;
        cout<<"The deleted element is "<<x<<endl;
    }
    
}
void deque::deqeuerear()
{
    if(rear==-1)
    {
        cout<<"queue is empty";
    }
    else if(front==rear)
    {
        int x=data[rear];
        front=rear=-1;
        cout<<"The deleted element is "<<x<<endl;

    }
    else
    {
        int x=data[rear];
        rear--;
        cout<<"The deleted elemnet is "<<x<<endl;
    }
}
void deque::display()
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
    deque k;
    int ch;
    do
    {
        cout<<"**************\n";
        cout<<"*****MENU*****\n";
        cout<<"1.Enqeuefront\n2.Enqeuerear\n3.Deqeuefront\n4.Deqeuerear\n5.Display\nEnter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int y;
                cout<<"Enter the element to be added:";
                cin>>y;
                k.enqeuefront(y);
                break;
            }
            case 2:
            {
                int y;
                cout<<"Enter the element to be added: ";
                cin>>y;
                k.enqeuerear(y);
                break;
            }
            case 3:
            {
                k.deqeuefront();
                break;
            }
            case 4:
            {
                k.deqeuerear();
                break;
            }
            case 5:
            {
                k.display();
                break;
            }
        }
    } while (ch!=6);
    return 0;
    
}