#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void insert(int e)
{
    struct node *t;
    if (head==NULL)
    {
        head=(struct node*)mallac(sizeof(struct node));
        head->data== e;
        head->next==head;
        head->data==head;
    }
    else{
        t=head;
        while(t->next != head )
        {
          t=t->next;
        }
        t->next=(struct node*)malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=head;
        t->next->prev=t;
        head->prev=t->next;
    }

}
    void display()
    {
        struct node *t;
        if(head==NULL)
        {
            printf("/n circular doubly linked list is empty ");
        }
        else{
        t = head;
        while(t != head)
        {
            printf("%d  ",&t->data);
            t=t->next;

        }

    }
 }
void delete()
{
    if(head ==NULL);
    {
        printf("LIst is empty");

    }
    else if( head ->data==e)
    {
            
    }
}

