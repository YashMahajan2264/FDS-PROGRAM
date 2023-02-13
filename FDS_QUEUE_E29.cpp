#include<iostream>
using namespace std;
const int Max=10;

class queue
{
    private:
    int arr[Max];
    int front,rear;

    public:
    queue()
    {
        front=rear=-1;
    }
    void addq(int x);
    int delq();
    void display();
        

};
void queue::addq(int x)
{
    if(rear==Max-1)
    {
        cout<<"Queue is full";
        return;
    }
    rear++;
    arr[rear]=x;
    if(front==-1)
    {
        front=0;
    }
}
int queue::delq()
{
    if(front==-1)
    {
        cout<<"Queue is Empty";
        return -1;
    }
    int value=arr[front];
    arr[front]=0;
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    return value;

}
void queue::display()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty";
        return;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

}
int main()
{
    queue q;
    int select,element;
    do
    {
        cout<<"\n1.Add job\n 2.Delete job\n 3.Display\n 4.Exit program\n Select choice";
        cin>>select;
        switch(select)
        {
            case 1:
            {
               cout<<"Enter Data";
               cin>>element;
               q.addq(element);
               break;
            }
            case 2:
            {
                int n;
                n=q.delq();
                if(n!=-1)
                {
                    cout<<"The deleted element is "<<n;
            
                }
                break;

            }
            case 3:
            {
                cout<<"**********QUEUE*********"<<endl;
                q.display();
                break;
            }
            case 4:
            {
                cout<<"Exiting program";
                break;
            }


        }
    
    } while (select!=4);

    return 0;
    
}