
#include<iostream>
#include<cstdlib>
using namespace std;
class List
{
    struct node
    {
        int data;
        node *prev,*next;
        node(int d=int(),node*p=NULL,node *n=NULL):data(d),prev(p),next(n) {}
    };
    node *head,*tail;
    int size;
public:
    void Init()
    {
        head=new node;
        tail=new node;
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    node *Begin()
    {
        return head->next;
    }
    node *End()
    {
        return tail;
    }
    node *Find(int m)
    {
        node *t=new node;
        for(t=head->next; t!=NULL; t=t->next)
            if(t->data==m)
                break;
        return t;
    }



    node *Insert(node *current,int item)
    {
        node *p=current;
        p->prev->next=new node(item,p->prev,p);
        p->prev=p->prev->next;
        size++;
        return  p->prev;
    }

    node* Erase(int n)
    {
        node *p=Find(n);
        p->prev->next=p->next;
        p->next->prev=p->prev;
        size--;
        return p->next;
    }

    void Push_back(int item)
    {
        Insert(End(),item);
    }

    void Sort()
    {
        node *p=new node;
        node *t=new node;
        for(p=head->next; p->next!=NULL; p=p->next)
        {
            node *min=p;
            for(t=p->next; t->next!=NULL; t=t->next)
            {
                if(min->data>t->data)
                {
                    min=t;
                }
            }
            if(min!=p)
                {
                    int temp;
                    temp=p->data;
                    p->data=min->data;
                    min->data=temp;
                }
        }
    }
    void Reverse()
    {
        node *p=new node,*t=new node;
        for(p=head->next,t=tail->prev; p<=t; p=p->next,t=t->prev)
        {
            int temp;
            temp=p->data;
            p->data=t->data;
            t->data=temp;
        }
        cout<<endl;
    }
    void display()
    {
        node *p=new node;
        for(p=head->next; p->next!=NULL; p=p->next)
            cout<<p->data<<' ';
        cout<<endl;
    }
};
