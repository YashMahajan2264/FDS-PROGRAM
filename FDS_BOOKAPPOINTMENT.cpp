#include<iostream>
using namespace std;

class slot
{
    public:
    int startTime,endTime,max,min;
    bool status;
    slot *next;
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
    cout<<"Sr.No\tStartTime\tEndTime\tMin\tMax\tStatus"<<endl;
    int i=1;
    slot *temp=head;
    while(temp!=NULL)
    {
        cout<<i<<"\t"<<temp->startTime<<"\t\t"<<temp->endTime<<"\t"<<temp->max<<"\t"<<temp->min<<"\t";
    
    if(temp->status==0)
    {
        cout<<"-Free-"<<endl;
    }
    else{
        cout<<"Booked"<<endl;
    }
    i++;
    temp=temp->next;
    }

}

void bookappointment()
{
    int start;
    cout<<"Enter the start time of the booking appointment";
    cin>>start;
    slot *temp=head;
    while(temp!=NULL)
    {

    
    if(temp->startTime==start)
    {
        if(temp->status==0)
        {
            temp->status=1;
            cout<<"Slot booking successfully"<<endl;
            break;
        }
        else if(temp->status==1)
        {
            cout<<"Sorry,slot is already booked"<<endl;

            break;
        }
       
    }
    temp=temp->next;
    }
}
void cancelappointment()
{
    int start;
    cout<<"enter the StartTime to cancel appointment";
    cin>>start;
    slot *temp=head;
    while(temp!=NULL)
    {
        if(temp->startTime==start)
        {
            if(temp->status==1)
            {
                temp->status=0;
                cout<<"Slot Cancelled successfully"<<endl;
                break;
            }
            else if(temp->status==0)
            {
                cout<<"Sorry,Slot is already free"<<endl;
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
                int val;
                val=current->startTime;
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

                bool val1=current->status;
                current->status=temp->status;
                temp->status=val1;
            }
            current=current->next;
        }
        temp=temp->next;
    }
    cout<<"ALL BOOKINGS ARE SORTED SUCCESSFULLY"<<endl;
    display();
}
int main()
{
    int n;
    cout<<"enter the no. of slot for today";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int start,end,min,max;
        cout<<"\nEnter the start time for the slot";
        cin>>start;
        cout<<"Enter the end time for the slot";
        cin>>end;
        cout<<"Enter the max duration";
        cin>>max;
        cout<<"Enter the min duration";
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
        char cont='y';
        int choice;
        while(cont=='y')
        {
            cout<<"------------------------------"<<endl;
            cout<<"---------MENU---------\n";
            cout<<"1.Dispaly Appointment List\n2.Book Apppointment\n3.Cancel Appontment\n4.Sort Appointment\n";
            cout<<"Enter your choice";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    display();
                    break;
                }
                case 2:
                {
                    bookappointment();
                    break;
                }
                case 3:
                {
                    cancelappointment();
                    break;
                }
                case 4:
                {
                    sortappointment();
                    break;
                }
                default:
                {
                    cout<<"\nINVALID CHOICE\n";
                }

            }
            cout<<"Do you want to continue(y/n)";
            cin>>cont;
        }
       
    
    cout<<"Program ended successfully"<<endl;
    return 0;
}
