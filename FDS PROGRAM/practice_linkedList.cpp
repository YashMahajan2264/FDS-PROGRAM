#include<iostream>
#include<stdlib.h>
#include<string.h>
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
    node *first;
    public:
    linkedlist()
    {
        first=NULL;
    }
    void insert_president()
    {
        node *temp;
        temp=new node();
        int pr;
        string nm;
        cout<<"Enter the prn and name of president :";
        cin>>pr>>nm;
        temp->prn=pr;
        temp->name=nm;
        temp->next=NULL;
        if(first==NULL)
        {
            first=temp;
        }
        else
        {
            temp->next=first;
            first=temp;
        }
        display();
    }
    void insert_secretary()
    {
        node *temp,*q;
        temp=new node();
        int pr;
        string nm;
        cout<<"Enter the prn and name of secreatry: ";
        cin>>pr>>nm;
        temp->prn=pr;
        temp->name=nm;
        temp->next=NULL;
        if(first==NULL)
        {
            first=temp;
        }
        else
        {
            q=first;
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
        node *temp,*q;
        temp=new node();
        q=first;
        int pr;
        string nm;
        cout<<"Enter the prn and name: ";
        cin>>pr>>nm;
        temp->prn=pr;
        temp->name=nm;
        temp->next=NULL;
        if(first==NULL)
        {
            first=temp;
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
                    cout<<"Less no of members.";
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
        node *t;
        t=first;
        first=first->next;
        free(t);
        display();
    }
    void delete_secretary()
    {
        node *t,*q;
        t=first;
        q=first;
        while(t->next!=NULL)
        {
            q=t;
            t=t->next;
        }
        q->next=NULL;
        free(t);
        display();
    }
    void delete_member()
    {
        node *temp,*q;
        temp=first;
        q=first;
        int pr;
        cout<<"Enter the prn of member to be deleted: ";
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
        node *t;
        if(first==NULL)
        {
            cout<<"******CLUB IS EMPTY******";
        }
        else
        {
            t=first;
            while(t!=NULL)
            {
                cout<<t->name<<"\t"<<t->prn<<"\n";
                t=t->next;
            }

        }
    }
    void count()
    {
        node *t;
        t=first;
        int i=0;
        while(t!=NULL)
        {
            i++;
            t=t->next;
        }
        cout<<"Total number of members is: "<<i<<endl;
    }
    void reverse1()
    {
        return reverse(first);
    }
    void reverse(node *ptr)
    {
        cout<<"****REVERSE MEMBER ORDER:******";
        if(ptr==NULL)
        {
            return;
        }
        else
        {
            reverse(ptr->next);
        }
        cout<<"\n"<<ptr->name<<"\t"<<ptr->prn;
    }
    void concatenate(linkedlist l1,linkedlist l2)
    {
        node *ptr;
        ptr=l1.first;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=l2.first;
        display();
    }


};
int main()
{
    linkedlist l1,l2;
    int ch;
    do
    {
        cout<<"******************\n";
        cout<<"******MENU********\n";
        cout<<"1.Add president\n2.Add secretary\n3.Add member\n4.Delete president\n5.Delete secretary\n6.Delete member\n7.Display\n8.Count\n9.Concatenate\n10.Reverse\nEnter Your Choice: ";
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
                l2.insert_president();
                l2.insert_secretary();
                l2.insert_member();
                l1.concatenate(l1,l2);
                break;
            }
            case 10:
            {
                l1.reverse1();
                break;
            }
        }
    } while(ch!=11);
    return 0;
    
}