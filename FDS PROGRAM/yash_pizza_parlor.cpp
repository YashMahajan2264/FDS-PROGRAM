#include<iostream>
#include<windows.h>
#define Max 10
using namespace std;

class pizzaparlor
{
    private:
    int front,rear;
    int order[Max];

    public:
    pizzaparlor()
    {
        front=rear=-1;
    }
    bool addorder(int id);
    void serveorder();
    void display();
};
bool pizzaparlor::addorder(int id)
{
    if(front==-1)
    {
        front=rear=0;
        order[rear]=id;
        return true;
    }
    else
    {
        int pos=(rear+1)%Max;
        if(pos==front)
        {
            cout<<"\nCafe is full so cannot accept the order.";
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
void pizzaparlor::serveorder()
{
    if(front==-1)
    {
        cout<<"\nCafe is empty.";
        return;
    }
    else
    {
        cout<<"Order ID no:"<<order[front]<<"is proceed."<<endl;
        front=(front+1)%Max;
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
        cout<<"\nOrder id's :";
        for(int i=front;i!=rear;i=(i+1)%Max)
        {
            cout<<order[i]<<" ";
        }
        cout<<order[rear];
    }
}
void intro()
{
    char name[50]={"\n***YASH CAFE'S***\n"};
    for(int i=0;i!='\0';i++)
    {
        cout<<name[i];
    }
}
int main()
{
    int ch;
    int id=0;
    pizzaparlor zatu;
    do
    {
        cout<<"\n*******************";
        intro();
        cout<<"\n******MENU******\n";
        cout<<"1.Acceppt order\n2.Serve order\n3.Display\n4.Exit\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                id++;
                if(zatu.addorder(id))
                {
                    cout<<"Order is accepted and order id is "<<id<<endl;
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
            case 4:
            {
                cout<<"PROGRAM ****** ENDED";
                exit(0);
            }
        }
    } while (ch!=5);

    return 0;
    
    
}