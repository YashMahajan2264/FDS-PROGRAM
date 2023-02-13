#include<iostream>
using namespace std;
class slot
{
    public:
    int starttime,endtime,min,max;
    bool status;
    slot *next;

    slot(int start,int end,int min,int max)
    {
        starttime=start;
        endtime=end;
        this->min=min;
        this->max=max;
        status=0;
        next=NULL;
    }

};
slot *head;
void display()
{
    slot *temp=head;
    int i=1;
    cout<<"\nSr.No\tstartTime\tendTime\tMax\tMin\tStatus\n";
        while(temp!=NULL)
        {
            cout<<i<<"\t"<<temp->starttime<<"\t\t"<<temp->endtime<<"\t"<<temp->max<<"\t"<<temp->min<<"\t";
            if(temp->status==0)
            {
                cout<<"-Free-\n";
            }
            else if(temp->status==1)
            {
                cout<<"Booked\n";
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
        if(temp->starttime==start)
        {
            if(temp->status==0)
            {
                temp->status=1;
                cout<<"\nSlot booked successfully\n";
                break;
            }
            else if(temp->status==1)
            {
                cout<<"\nSlot is already book,so cann't book this slot\n";
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
    cout<<"Enter the start of appointment: ";
    cin>>start;
    while(temp!=NULL)
    {
        if(temp->starttime==start)
        {
            if(temp->status==1)
            {
                temp->status=0;
                cout<<"\nSlot cancel successfully\n";
                break;
            }
            else if(temp->status==0)
            {
                cout<<"\nSlot is already free i.e.cancelled\n";
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
            if(current->starttime<temp->starttime)
            {
                int val;
                val=current->starttime;
                current->starttime=temp->starttime;
                temp->starttime=val;

                val=current->endtime;
                current->endtime=temp->endtime;
                temp->endtime=val;

                val=current->max;
                current->max=temp->max;
                temp->max=val;
                
                val=current->min;
                current->min=temp->min;
                temp->min=val;

                bool val1=current->status;
                current->status=temp->status;
                temp->status=val1;

            }
            current=current->next;
        }
        temp=temp->next;
    }
    cout<<"\nSlots are sorted successfully\n";
    display();
}
int main()
{
    int n,Starttime,Endtime,Min,Max;
    cout<<"Enter How many slots you want";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the start time of appointment:";
        cin>>Starttime;
        cout<<"Enter the end time of appointment:";
        cin>>Endtime;
        cout<<"Enter the Max time:";
        cin>>Max;
        cout<<"Enter the min time:";
        cin>>Min;
        slot *newslot=new slot(Starttime,Endtime,Min,Max);
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
        cout<<"*******************\n";
        cout<<"******MENU*******\n";
        cout<<"1.Book appointment\n2.Cancel appointment\n3.Display\n4.Sort slots\n5.Exit\nEnter your choice";
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
            case 5:
            {
                exit(0);
            }
        }
        cout<<"\nDo you want to continue(y/n):";
        cin>>ch;
    } 
    cout<<"PROGRAM ENDS";
    return 0;
    
}