#include<iostream>
#include<string.h>
#define max 5
using namespace std;
class pizza
{
    private:
    int front,rear;
    int data[max];
    public:
    pizza()
    {
        front=rear=-1;
    }
    bool addorder(int id);
    void serveorder();
    void display();
};
bool pizza::addorder(int id)
{
    if(front==-1)
    {
        front=rear=0;
        data[front]=id;
        return true;
    }
    else
    {
        int pos=(rear+1)%max;
        if(pos==front)
        {
            cout<<"\nCafe is full so cannot accept the order\n";
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
void pizza::serveorder()
{
    if(front==-1)
    {
        cout<<"\nCafe is empty\n";
    }
    else
    {
        cout<<"order id="<<data[front]<<" is served"<<endl;
        front=(front+1)%max;
    }
}
void pizza::display()
{
    if(front!=-1)
    {
        cout<<"\nOrder id's=";
        for(int i=front;i!=rear;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<data[rear]<<endl;
    }
}
int main()
{
    int ch,id=0;
    pizza y;
    do
    {
        cout<<"\n*******MENU*******\n";
        cout<<"1.Accept order\n2.Serve order\n3.Dispaly\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                id++;
                if(y.addorder(id))
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
                y.serveorder();
                break;
            }
            case 3:
            {
                y.display();
                break;
            }
            default:
            cout<<"\nInvalid choice\n";
        }
    } while (ch!=4);
    return 0;
    
}
