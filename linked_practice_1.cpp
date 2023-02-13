#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class slot
{
    public:
    int prn;
    string name;
    slot *next;
    friend class linkedlist;
};
class linkedlist
{
    private:
    slot *head;
    public:
    linkedlist()
    {
        head=NULL;
    }
    void addpresident()
    {
        slot *temp;
        temp=new slot();
        int pr;
        string nm;
        cout<<"\nEnter the name and prn of president: ";
        cin>>nm>>pr;
        temp->name=nm;
        temp->prn=pr;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
        display();
    }
    void addsecretary()
    {
        slot *temp,*q;
        q=head;
        temp=new slot();
        int pr;
        string nm;
        cout<<"\nEnter the name and prn of secretary: ";
        cin>>nm>>pr;
        temp->name=nm;
        temp->prn=pr;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=temp;
            display();

        }
    }
    void addmember()
    {
            slot *temp,*q;
            q=head;
            temp=new slot();
            int pr;
            string nm;
            cout<<"\nEnter the name and prn of member: ";
            cin>>nm>>pr;
            temp->name=nm;
            temp->prn=pr;
            temp->next=NULL;
            if(head==NULL)
           {
                head=temp;
           }
           else
           {
               int index;
               cout<<"Enter the index position: ";
               cin>>index;
               for(int i=0;i<index;i++)
               {
                q=q->next;
                if(q->next==NULL)
                {
                    cout<<"Less number of member";
                    return;
                }
               }
               temp->next=q->next;
               q->next=temp;


            }
        display();
    }
    void delete_president()
    {
        slot *t=head;
        head=head->next;
        free(t);
        display();

    }
    void delete_secretary()
    {
        slot *temp,*q;
        temp=head;
        while(temp->next!=NULL)
        {
            q=temp;
            temp=temp->next;
        }
        q->next=NULL;
        free(temp);
        display();
    }
    void delete_member()
    {
        slot *temp,*q;
        temp=head;
        int pr;
        cout<<"Enter the prn no of member to be deleted:";
        cin>>pr;
        while(temp->next!=NULL)
        {
            if(temp->prn==pr)
            {
            q->next=temp->next;
            free(temp);
            }
            q=temp;
            temp=temp->next;
        }
        display();
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"Club is empty.";
            return;
        }
        else
        {
            slot *temp=head;
            cout<<"******CLUB******\n";
            while(temp!=NULL)
            {
                cout<<temp->name<<"\t"<<temp->prn<<"\n";
                temp=temp->next;

            }
        }
    }
    void count()
    {
        int i=0;
        slot *temp;

        temp=head;
        while(temp!=NULL)
        {
            i++;
            temp=temp->next;
        }
        cout<<"Total members of club are:"<<i<<endl;
    }
    void reverse1()
    {
        reverse(head);
    }
    void reverse(slot *ptr)
    {
        if(ptr==NULL)
        {
            return;
        }
        else
        {
            cout<<"\nreverse members are:";
            reverse(ptr->next);
            cout<<"\n"<<ptr->name<<"\t"<<ptr->prn;
        }
    }
    void concatenate(linkedlist l1,linkedlist l2)
    {
        slot *ptr;
        ptr=l1.head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=l2.head;
    }

    
};
int main()
{
    linkedlist l1,l2;
    int ch;
    do
    {
        cout<<"\n******MENU******\n";
        cout<<"1.Add president\n2.Add secretary\n3.Add member\n4.Delete president\n5.Delete secretary\n6.Delete member\n7.Display\n8.Count\n9.Reverse list\n10.Concatentae\n11.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                l1.addpresident();
                break;
            }
            case 2:
            {
                l1.addsecretary();
                break;
            }
            case 3:
            {
                l1.addmember();
                break;
            }
            case 4:
            {
                l1.delete_president();
                break;
            }
            case 5:
            {
                l1.delete_secretary();
                break;
            }
            case 6:
            {
                l1.delete_member();
                break;
            }
            case 7:
            {
                l1.display();
                break;
            }
            case 8:
            {
                l1.count();
                break;
            }
            case 9:
            {
                l1.reverse1();
                break;
            }
            case 10:
            {
                l2.addpresident();
                l2.addsecretary();
                l2.addmember();
                l1.concatenate(l1,l2);
                l1.display();
                break;
            }
            default:
            {
                cout<<"Invalid choice.";
            }
        }
    } while (ch!=11);
    return 0;
    
}