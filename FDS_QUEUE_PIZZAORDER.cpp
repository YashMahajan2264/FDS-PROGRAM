#include<iostream>
#include<windows.h>
#define Max 50
using namespace std;

class PizzaParlor
{
    private:
    int rear,front;
    int orders[Max];

    public:
    PizzaParlor()
    {
        front=rear=-1;
    }
    bool addorder(int id);
    void serveorder();
    void display();
};
bool PizzaParlor::addorder(int id)
{
    if(front==-1)
    {
        front=rear=0;
        orders[front]=id;
        return true;
    }
    else
    {
        int pos=(rear+1)%Max;
        if(pos==front)
        {
            cout<<"\nCafe is full so order cannot be accepted";
            return false;
        }
        else
        {
            rear=pos;
            orders[rear]=id;
            return true;
        }
    }
}
void PizzaParlor::serveorder()
{
    if(front==-1)
    {
        cout<<"\nCafe is empty\n";
        return;
    }
    else
    {
        cout<<"\nOrder id:"<<orders[front]<<"is proceed\n";
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%Max;
        }
    }
}
void PizzaParlor::display()
{
    int i=0;
    if(front==-1)
    {
        cout<<"\nCafe is empty.No order\n";
        return;
    }
    else
    {
        cout<<"Order id's :";
        for(int i=front;i!=rear;i=((i+1)%Max))
        {
            cout<<orders[i]<<" ";
        }
        cout<<orders[rear];
    }
}
void intro()
{
    char name[Max]={"YASH CAFE"};
    for(int i=0;i!='\0';i++)
    {
        Sleep(50);
        cout<<name[i];
    }
}
int main()
{
    int ch,id=0;
    PizzaParlor yash;
    do
    {
        cout<<"\n************";
        intro();
        cout<<"************";
        cout<<"\n****MENU****";
        cout<<"\n1.Accept Order\n2.Serve order\n3.Dispaly order's\n4.Exit\n";
        cout<<"Choice";
        cin>>ch;
        switch (ch)
        {
            case 1:
            {
                id++;
                if(yash.addorder(id))
                {
                    cout<<"\nThank you for your order.Your order id is:"<<id<<endl;
                }
                else
                {
                    id--;
                }
                break;
            }
            case 2:
            {
                yash.serveorder();
                break;
            }
            case 3:
            {
                yash.display();
                break;
            }
            case 4:
            {
                cout<<"\n*********EXITING THROUGH PROGRAM************\n";
                break;
            }
            
        
        }
        
    
    } while (ch!=5);
    cout<<"\n******Thank you for visiting**********";
}