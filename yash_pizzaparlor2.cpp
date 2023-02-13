#include<iostream>
#include<windows.h>
#define max 10
using namespace std;
class pizza
{
    private:
    int front,rear;
    int order[max];

    public:
    pizza()
    {
        front=rear=-1;
    }
    bool AcceptOrder(int id);
    void ServeOrder();
    void Display();
};
bool pizza::AcceptOrder(int id)
{
    if(front==-1)
    {
        front=rear=0;
        order[rear]=id;
        return true;
    }
    else
    {
        int pos=(rear+1)%max;
        if(pos==front)
        {
            cout<<"\nCafe is full so can not accept the order";
            return false;
        }
        else
        {
            rear=pos;
            order[rear]=id;
            return true;
        }
        if(front==-1)
        {
            front=0;
        }
    }
}
void pizza::ServeOrder()
{
    if(front==-1)
    {
        cout<<"Cafe is Empty";
        return;
    }
    else
    {
        cout<<"\nOrder id no :"<<order[front]<<" is proceed\n";
        front=(front+1)%max;
    }
}
void pizza::Display()
{
    if(front==-1)
    {
        cout<<"cafe is Empty.";
    }
    else
    {
        cout<<"\nTOTAL ORDER ID'S ARE:\n";
        for(int i=front;i!=rear;i=(i+1)%max)
        {
            cout<<order[i]<<" ";
        }
        cout<<order[rear]<<endl;

    }
}
int main()
{
    int ch;
    pizza k;
    int id=0;
    do
    {
        cout<<"\n****************\n";
        cout<<"*******MENU******\n";
        cout<<"1.ACCEPT ORDER\n2.SERVE ORDER\n3.DISPLAY\n4.EXIT\nEnter your choice";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                id++;
                if(k.AcceptOrder(id))
                {
                    cout<<"Order is accepted your order id is "<<id<<endl;
                    break;
                }
                else
                {
                    id--;
                }
            }
            case 2:
            {
                k.ServeOrder();
                break;
            }
            case 3:
            {
                k.Display();
                break;
            }
            case 4:
            {
                exit(0);
            }
        }
    } while (ch!=5);
    return 0;
    
}