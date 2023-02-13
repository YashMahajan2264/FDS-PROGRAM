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
        cout<<"\nEnter the name and prn of president:";
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
        node *temp,*q;
        temp=new node();
        int pr;
        string nm;
        cout<<"\nEnter the name and prn of secretary:";
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
            q=head;
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
        int pr;
        string nm;
        cout<<"\nEnter the name and prn of member:";
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
            q=head;
            cout<<"Enter the index position:";
            cin>>index;
            for(int i=0;i<index;i++)
            {
                q=q->next;
                if(q->next==NULL)
                {
                    cout<<"\nLess no of member\n";
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
        node *temp,*q;
        temp=head;
        q=head;
        int pr;
        cout<<"\nEnter the prn no of member to be delted:";
        cin>>pr;
        while(temp->next!=NULL)
        {
            if(temp->prn==pr)
            {
                q->next=temp->next;
                free(temp);
                display();
                return;
            }
            q=temp;
            temp=temp->next;
        }
    }
    void display()
    {
        node *temp;
        if(head==NULL)
        {
            cout<<"\nCLUB IS EMPTY\n";
        }
        else
        {
            temp=head;
            cout<<"\nCLUB MEMBERS ARE:\n";
            while(temp!=NULL)
            {
                cout<<temp->name<<"\t"<<temp->prn<<endl;
                temp=temp->next;
            }
        }
    }
    void count()
    {
        node *temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        cout<<"\nThe total members of club are "<<c<<endl;
    }
    void reverse1()
    {
        reverse(head);
    }
    void reverse(node *ptr)
    {
        if(ptr==head)
        {
            return;
        }
        else
        {
            reverse(ptr->next);
        }
        cout<<"\n"<<ptr->name<<"\t"<<ptr->prn;
    }
    void concat(linkedlist l1,linkedlist l2)
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
    int ch;
    linkedlist l1,l2;
    do
    {
        cout<<"\n********************\n";
        cout<<"********MENU**********\n";
        cout<<"1.ADD PRESIDENT\n2.ADD SECRETARY\n3.ADD MEMBER\n4.DELETE PRESIDENT\n5.DELETE SECRETARY\n6.DELETE MEMBER\n7.DISPLAY CLUB\n8.COUNT\n9.REVERSE\n10.CONCATENATE\n11.EXIT\nEnter ypur choice";
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
                l1.concat(l1,l2);
            }
            case 11:
            {
                exit(0);
            }
        }
    }while(ch!=12);
    return 0;
} 