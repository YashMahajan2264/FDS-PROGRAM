#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Node
{
    public:
    int prn;
    string name;
    Node *next;
    friend class linkedlist;
};
class linkedkist
{
    private:
    Node *first;
    public:
    linkedkist()
    {
        first=NULL;
    }
    void insert_president()
    {
        Node *temp;
        temp=new Node();
        int pr;
        string nm;
        cout<<"Enter the prn and name of president\n";
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
        Node *temp,*q;
        int pr;
        string nm;
        temp=new Node();
        cout<<"Enter the prn and name of secretary\n";
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
        display();
        Node *temp,*q;
        int pr;
        string nm;
        int index;
        temp=new Node();
        cout<<"Enter the prn and name\n";
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
            cout<<"Enter the index position:";
            cin>>index;
            for(int i=0;i<index;i++)
            {
                q=q->next;
                if(q->next==NULL)
                {
                    cout<<"less number of member";
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
        Node *temp;
        temp=first;
        first=first->next;
        free(temp);
        display();
    }
    void delete_secretary()
    {
        Node *temp,*q;
        temp=first;
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
        int pr;
        cout<<"Enter the prn of member to be delted";
        cin>>pr;
        Node *temp,*q;
        temp=first;
        q=first;
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
        Node *q;
        q=first;
        if(first==NULL)
        {
            cout<<"\n*****CLUB IS EMPTY****\n";

        }
        else
        {
            cout<<"\nMEMBERS OF CLUB:\n";
            while(q!=NULL)
            {
                cout<<q->name<<"\t"<<q->prn<<endl;
                q=q->next;
            }
        }
    }
    void count()
    {
        int i=0;
        Node *temp;
        temp=first;
        while(temp!=NULL)
        {
            i++;
            temp=temp->next;
        }
        cout<<"The total Members of club are "<<i;
    }
    void reverse1()
    {
        reverse(first);
    }
    void reverse(Node *ptr)
    {
        cout<<"Members in reverse order:\n";
        if(ptr==NULL)
        {
            return;
        }
        else
        {
            reverse(ptr->next);
        }
       
        cout<<"\n"<<ptr->prn;

        cout<<"\t"<<ptr->name;

    }
    void concat(linkedkist l1,linkedkist l2)
    {
        Node *ptr;
        ptr=l1.first;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=l2.first;
        l1.display();
    }


};
int main()
{
    linkedkist l1,l2;
    int ch;
    do
    {
        cout<<"\n******LINKED LIST******\n";
        cout<<"1.Insert president\n2.Insert secretary\n3.Insert Member\n4.Delete president\n5.Delete secreatry\n6.Delete member\n7.Display\n8.count\n9.Reverse\n10.concatenate\n11.Exit\n";
        cout<<"Enter your choice";
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
               break; 
            }
            case 11:
            {
                cout<<"\nProgram ended";
                exit(0);
            }
        }
    } while (ch!=12);
    return 0;
    
}