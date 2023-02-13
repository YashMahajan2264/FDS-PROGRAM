#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class node
{
    public:
    int prn;
    string name;
    node *next;
    friend class linkedlist;
};
class linkedlist
{
    private:
    node *head;
    public:
    linkedlist()
    {
        head=NULL;
    }
    void insert_president()
    {
        node *temp;
        temp=new node();
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
        void insert_secretary()
        {
            node *temp;
            temp=new node();
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
                node *q=head;
                while(q->next!=NULL)
                {
                    q=q->next;
                }
                q->next=temp;
            }
            display();

        }
    void insert_member()
    {
        node *temp;
        temp=new node();
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
            node *q=head;
            int index;
            cout<<"\nEnter the index position: ";
            cin>>index;
            for(int i=0;i<index;i++)
            {
                q=q->next;
                if(q->next==NULL)
                {
                    cout<<"Less no of members\n";
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
        node *temp=head;
        head=head->next;
        free(temp);
        display();
    }
    void delete_secretary()
    {
        node *temp,*q;
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
        node *q,*temp;
        q=head;
        temp=head;
        int pr;
        cout<<"\nEnter the prn of member to be deleted: ";
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
        node *temp;
        temp=head;
        cout<<"\n*****LINKED LIST*****\n";
        while(temp!=NULL)
        {
            cout<<temp->name<<"\t"<<temp->prn<<endl;
            temp=temp->next;
        }
    }
    void count()
    {
        node *t=head;
        int c=0;
        while(t!=NULL)
        {
            c++;
            t=t->next;
        }
        cout<<"\nThe total member of club are "<<c<<endl;
    }
    void reverse1()
    {
        reverse(head);
    }
    void reverse(node *ptr)
    {
        if(ptr==NULL)
        {
            return;
        }
        else
        {
            reverse(ptr->next);
        }
        cout<<endl<<ptr->name<<"\t"<<ptr->prn;
    }
    void concatenate(linkedlist l1,linkedlist l2)
    {
        node *ptr;
        ptr=l1.head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=l2.head;
        l1.display();
    }
    

};
int main()
{
    linkedlist l1,l2;
    int ch;
    do
    {
        cout<<"\n*********************\n";
        cout<<"*********MENU********\n";
        cout<<"1.Add president\n2.Add secretary\n3.Add member\n4.Delete president\n5.Delete secretary\n6.Delete member\n7.Display\n8.Count\n9.Reverse\n10.Concatenate\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                l1.insert_president();
                break;
            }
            case 2:
            {
                l1.insert_secretary();
                break;
            }
            case 3:
            {
                l1.insert_member();
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
                l2.insert_president();
                l2.insert_secretary();
                l2.insert_member();
                l1.concatenate(l1,l2);
                break;
            }
            default:
            {
                cout<<"INVALID CHOICE";
            }
        }
    } while (ch!=11);
    return 0;
    
}
