#include<iostream>
using namespace std;
class slot
{
    public:
    int startTime,endTime,max,min;
    bool status;
    slot  *next;
    slot(int start,int end,int max,int min)
    {
        startTime=start;
        endTime=end;
        this->max=max;
        this->min=min;
        status=0;
        next=NULL;
    }
};
slot *head;
void display()
{
    slot *temp=head;
    int i=1;
    cout<<"\nSr.No\tStart time\tEnd time\tMax time\tMin time\tstatus\n";
    while(temp!=NULL)
    {
        cout<<i<<"\t"<<temp->startTime<<"\t\t"<<temp->endTime<<"\t\t"<<temp->max<<"\t\t"<<temp->min<<"\t\t";
        if(temp->status==0)
        {
            cout<<"-Free-"<<endl;
        }
        else if(temp->status==1)
        {
            cout<<"Booked"<<endl;
        }
        i++;
        temp=temp->next;
    }
}
void bookappointment()
{
    slot *temp=head;
    int start;
    cout<<"Enter the start time of appointment: ";
    cin>>start;
    while(temp!=NULL)
    {
        if(temp->startTime==start)
        {
            if(temp->status==0)
            {
                temp->status=1;
                cout<<"Slot book successfully..\n";
                break;
            }
            else if(temp->status==1)
            {
                cout<<"Slot is already booked..\n";
                break;
            }
        }
        temp=temp->next;
    }
}
void cancelappointment()
{
    slot *temp=head;
    int start;
    cout<<"Enter the start time of appointment: ";
    cin>>start;
    while(temp!=NULL)
    {
        if(temp->startTime==start)
        {
            if(temp->status==1)
            {
                temp->status=0;
                cout<<"Slot cancelled successfully..\n";
                break;
            }
            else if(temp->status==0)
            {
                cout<<"Slot is already free..\n";
                break;
            }
        }
        temp=temp->next;
    }    
}
void sortappointment()
{
    slot *temp=head;
    while(temp->next!=NULL)
    {
        slot *current=temp->next;
        while(current!=NULL)
        {
            if(current->startTime<temp->startTime)
            {
                int val=current->startTime;
                current->startTime=temp->startTime;
                temp->startTime=val;

                val=current->endTime;
                current->endTime=temp->endTime;
                temp->endTime=val;

                val=current->max;
                current->max=temp->max;
                temp->max=val;

                val=current->min;
                current->min=temp->min;
                temp->min=val;

                bool st=current->status;
                current->status=temp->status;
                temp->status=st;
            }
            current=current->next;
        }  
        temp=temp->next;
    }
    cout<<"\nSlots are sorted successfully\n:";
    display();
}
int main()
{
    int n;
    cout<<"Enter how many slots you wanted: ";
    cin>>n;
    int start,end,max,min;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter start time:";
        cin>>start;
        cout<<"Entee end time: ";
        cin>>end;
        cout<<"Enter the maximum duration: ";
        cin>>max;
        cout<<"Enter the minimum duration: ";
        cin>>min;
        slot *newslot=new slot(start,end,max,min);
        if(head==NULL)
        {
            head=newslot;
        }
        else
        {
            slot *temp=head;
            while(temp->next!=NULL)
            { 
                temp=temp->next;   
            }
            temp->next=newslot;
        }
    }
    display();
    char ch='y';
    int choice;
    while(ch=='y')
    {
        cout<<"***************\n";
        cout<<"*****MENU*******\n";
        cout<<"1.Book appointment\n2.Cancel appointment\n3.Display\n4.Sort\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                bookappointment();
                break;
            }
            case 2:
            {
                cancelappointment();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                sortappointment();
                break;
            }
        }
        cout<<"Do you want to continue:(y/n)";
        cin>>ch;
    }
    return 0;
}