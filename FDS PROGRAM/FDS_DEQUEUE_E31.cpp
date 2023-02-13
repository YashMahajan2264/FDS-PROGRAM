#include<iostream>
using namespace std;
const int Max=10;

class dequeue
{
    private:
    int rear,front;
    int data[Max];

    public:
    dequeue()
    {
        front=rear=-1;
    }
    void equeuefront(int x);
    void equeuerear(int x);
    void dequeuefront();
    void dequeuerear();
    void display();
};
void dequeue::equeuefront(int x)
{
    if(front==0)
    {
        cout<<"Data cannot insert at front";
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
void dequeue::equeuerear(int x)
{
    if(rear==Max-1)
    {
        cout<<"Data cannot insert at rear";
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
        cout<<"\nQueue is empty";
    }
    else if(front==rear)
    {
        int t=data[front];
        front=rear=-1;
        cout<<"\nThe deleted element is "<<t<<endl;
    }
    else
    {
        int t=data[front];
        front++;
        cout<<"\nThe deleted element is "<<t<<endl;
    }


}
void dequeue::dequeuerear()
{
    if(rear==-1)
    {
        cout<<"\nqueue is empty";
    }
    else if(front==rear)
    {
        int y=data[rear];
        front=rear=-1;
        cout<<"\nThe deleted element is "<<y<<endl;
    }
    else
    {
        int y=data[rear];
        rear--;
        cout<<"\nThe deletd elemnt is "<<y<<endl;
    }

}
void dequeue::display()
{
    if(front!=-1)
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    dequeue d;
    int x,y;
    do
    {
        cout<<"\n1.insert at front\n2.insert at rear\n3.delete at front\n4.delete at rear\n5.display\n6.exit\n";
        cin>>x;
        switch (x)
        {
        case 1:
        {
            cout<<"The element to be inserted=";
            cin>>y;
            d.equeuefront(y);
            break;
        }
        case 2:
        {
            cout<<"The element to be inserted=";
            cin>>y;
            d.equeuerear(y);
            break;
        }
        case 3:
        {
            d.dequeuefront();
            break;
        }
        case 4:
        {
            d.dequeuerear();
            break;
        }
        case 5:
        {
            cout<<"The queue is---"<<endl;
            d.display();
            break;
        }
        case 6:
        {
            cout<<"************exiting the program***********"<<endl;
            break;
        }
        
        default:
            break;
        }
    } while (x!=7);

    return 0;
    
    
}