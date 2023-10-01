#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;
struct node *head=NULL;
void insert(int e)
{
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->data=e;
        head->next=NULL;
        head->prev=NULL;
    }
    else{
        node *t;
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;

        }
        t->next=(node*)malloc(sizeof(node));
        t->next->data=e;
        t->next->next=NULL;
        t->next->prev=t;

    }
}
void display()
{
    node *t;
    if(head==NULL)
    {
        printf("linked list is empty\n");

    }
    else{
        t=head;
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t=t->next;
        }

    }
}
int  main()
{
    insert(10);
    insert(20);
    insert(23);
    display();
    return 0;
}

