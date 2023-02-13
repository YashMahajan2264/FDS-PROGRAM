#include<iostream>
using namespace std;
#define max 10
class queue
{
    private:
    int front,rear,data[max];
    public:
    queue()
    {
        front=rear=-1;
    }
    void add_job(int id)
    {
        if(rear==max-1)
        {
            cout<<"\nQueue is full so cannot add job\n";
        }
        else if(rear==-1)
        {
            front=rear=0;
            data[rear]=id;
            cout<<"\nYour added element is:"<<id<<endl;
        }
        else
        {
            rear++;
            data[rear]=id;
            cout<<"\nYour added element is:"<<id<<endl;
        }
    }
    int delq()
    {
        if(rear==-1)
        {
            cout<<"queue is empty\n";
        }
        else if(rear==front)
        {
            int y=data[rear];
            front=rear=-1;
            return y;
        }
        else
        {
            int y=data[front];
            front++;
            return y;
        }
        
    }
    void display()
    {
        if(front==-1)
        {
            cout<<"\nqueue is empty\n";
            return;
        }
        else
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
    }
};
int main()
{
    int ch;
    queue q;
    do
    {
        cout<<"\n**************\n";
        cout<<"******MENU******\n";
        cout<<"1.Add job\n2.Delete job\n3.Display\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int ele;
                cout<<"Enter the element :";
                cin>>ele;
                q.add_job(ele);
                break;
            }
            case 2:
            {
                int x=q.delq();
                if(x!=-1)
                {
                    cout<<"The deleted job is "<<x<<endl;
                }
                break;
            }
            case 3:
            {
                cout<<"\n*******QUEUE******\n";
                q.display();
            }
            default:
            cout<<"INVALID CHOICE";
        }
    } while (ch!=4);
    return 0;
}