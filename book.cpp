#include<iostream>
#include<string.h>
#include<windows.h>
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
status=0;
next=NULL;
}
};
slot *head;
void display()
{
int i=1;
slot *temp=head;
cout<<"Sr.No\tStart time\tEnd time\tmax duration\tmin duration\tstatus\n";
while(temp!=NULL)
{
cout<<i<<"\t"<<temp->starttime<<"\t\t"<<temp->endtime<<"\t\t"<<temp->max<<"\t\t"<<temp->min<<"\t\t";
if(temp->status==0)
cout<<"-Free-\n";
else if(temp->status==1)
cout<<"Book\n";
i++;
temp=temp->next;
}
}
void bookappointment()
{
slot *temp=head;
int start;
cout<<"\nenter the start time of appointment: ";
cin>>start;
while(temp!=NULL)
{
if(temp->starttime==start)
{
if(temp->status==0)
{
temp->status=1;
cout<<"\nSlot book successfully\n";
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
cout<<"\nenter the start time of appointment: ";
cin>>start;
while(temp!=NULL)
{
if(temp->starttime==start)
{
if(temp->status==1)
{
temp->status=0;
cout<<"\nSlot cancel successfully\n";
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
void sort_appointment()
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
cout<<"\nSlots are sorted successfully\n";
display();
}
int main()
{
int start,end,max,min;
int n;
cout<<"\nEnter the no of slots today: ";
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"\nEnter the start time: ";
cin>>start;
cout<<"Enter the end time: ";
cin>>end;
cout<<"Enter the max duration: ";
cin>>max;
cout<<"Enter the min duration: ";
cin>>min;
slot *newslot=new slot(start,end,max,min);
if(head==NULL)
head=newslot;
else
{
slot *q=head;
while(q->next!=NULL)
{
q=q->next;
}
q->next=newslot;
}
}
display();
char c='y';
int ch;
while(c=='y')
{
cout<<"\n******MENU******\n";
cout<<"1.Book appointment\n2.Cancel appointment\n3.Display\n4.Sort\nEnter your choice: ";
cin>>ch;
switch(ch)
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
sort_appointment();
break;
}
default:
cout<<"Invalid choice";
}
cout<<"\nDo you want to continue(y/n): ";
cin>>c;
}

return 0;
}