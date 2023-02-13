#include<iostream>
#include<windows.h>
#define max 20
using namespace std;
class pizzaparlor
{
    private:
    int front,rear;
    int data[max];

    public:
    pizzaparlor()
    {
        front=rear=-1;
    }
    bool AcceptOrder(int id);
    void serveorder();
    void display();
};
bool pizzaparlor::AcceptOrder(int id)
{
    if(front==-1)
    {
        front=rear=0;
        data[rear]=id;
        return true;
    }
    else
    {
        int pos=(rear+1)%max;
        if(pos==front)
        {
            cout<<"\nCafe is full so can not accept order\n";
            return false;
        }
        else
        {
            rear=pos;
            data[rear]=id;
            return true;
        }
        if(front==-1)
        {
            front=0;
        }
    }

}
void pizzaparlor::serveorder()
{
    if(front==-1)
    {
        cout<<"\nCafe is Empty\n";
        return;
    }
    else
    {
        cout<<"\nOrder id's "<<data[front]<<" is proceed\n";
        front=(front+1)%max;
    }
}
void pizzaparlor::display()
{
    if(front==-1)
    {
        cout<<"\nCafe is empty\n";

    } 
    else
    {
        cout<<"Order id's:\n";
        for(int i=front;i!=rear;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<data[rear]<<endl;
    }
}
int main()
{
    pizzaparlor zatu;
    int ch,id=0;
    do
    {
        cout<<"\n***************\n";
        cout<<"*********MENU*******\n";
        cout<<"1.Add order\n2.Serve order\n3.Display\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                id++;
                if(zatu.AcceptOrder(id))
                {
                    cout<<"\nOrder is accepted and your order id is "<<id<<endl;
                    break;
                }
                else
                {
                    id--;
                    break;
                }
            }
            case 2:
            {
                zatu.serveorder();
                break;
            }
            case 3:
            {
                zatu.display();
                break;
            }
            default:
            {
                cout<<"INVALID CHOICE";
            }
        }
    } while (ch!=4);
    return 0;
}