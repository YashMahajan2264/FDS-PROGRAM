#include<iostream>
#include<string.h>
using namespace std;
class slot
{
	public:
		int starttime,endtime,max,min;
		bool status;
		slot *next;
		slot(int start,int end,int max,int min)
		{
			starttime=start;
			endtime=end;
			this->max=max;
			this->min=min;
			next=NULL;
			status=0;
			
		}
};
slot *head;
void display()
{
	slot *temp=head;
	cout<<"sr.no/tstart time\tend time\tmax duration\tmin duration\tstatus\n";
	int i=1;
	while(temp!=NULL)
    {
    	cout<<i<<"\t"<<temp->starttime<<"\t\t"<<temp->endtime<<"\t\t"<<temp->max<<"\t"<<temp->min<<"\t";
    	if(temp->status==0)
    	{
    		cout<<"-Free-\n";
		}
		else if(temp->status==1)
		{
			cout<<"Booked\n";
		}
		temp=temp->next;
	}
}
void bookappointment()
{
	slot *temp=head;
	int start;
	cout<<"\nEnter the start time of appointment: ";
	cin>>start;
	while(temp!=NULL)
	{
		if(temp->starttime==start)
		{
			if(temp->status==0)
			{
				temp->status=1;
				cout<<"\nSlot booked successfully\n";
	     	}
	     	else if(temp->status==1)
	     	{
			 cout<<"\nSlot is already booked\n";	
			}
		}
		temp=temp->next;
	}
	display();
}
void cancelappointment()
{
slot *temp=head;
	int start;
	cout<<"\nEnter the start time of appointment: ";
	cin>>start;
	while(temp!=NULL)
	{
		if(temp->starttime==start)
		{
			if(temp->status==1)
			{
				temp->status=0;
				cout<<"\nSlot cancelled successfully\n";
	     	}
	     	else if(temp->status==0)
	     	{
			 cout<<"\nSlot is already free\n";	
			}
		}
		temp=temp->next;
	}
	display();	
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
				int val=current->starttime;
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
}
int main()
{
	int n;
	cout<<"Enter the number of today slot: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int start,end,max,min;
		cout<<"Enter the start time of slot: ";
		cin>>start;
		cout<<"Enter the end time of slot: ";
		cin>>end;
		cout<<"Enter the max duration: ";
		cin>>max;
		cout<<"Enter the min duration: ";
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
		display();
	}
	int ch;
	do
	{
		cout<<"\n******MENU******\n";
		cout<<"1.Display\n2.Book Appointment\n3.Cancel appointment\n4.Sort\nEnter your choice: ";
		cin>>ch;
		switch(ch)
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
				cout<<"Invalid choice";
		}
	}while(ch!=5);
	return 0;
}