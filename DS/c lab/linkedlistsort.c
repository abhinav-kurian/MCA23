#include<stdio.h>
#include<malloc.h>
struct node{
     int data;
     struct node *next;
};
typedef struct node node;
node *head = NULL;

void insert(int e)
{

 if(head==NULL)
 {
    head=(node *)malloc(sizeof(node));
    head->data=e;
    head->next=NULL;
 }
 else
 {
    node *t;
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
        
    }
    t->next=(node *)malloc(sizeof(node));
    t->next->data=e;
    t->next->next=NULL;

 }

}
void display()
{
    if(head==NULL)
    {
        printf("Linked list is empty");

    }
    else{
     node *t;
    t=head;
    while(t !=NULL)

    {
        printf("%d\t",t->data);

        t=t->next;
        
    }

    }
    printf("\n");
}
void sort()
{
    node *t,*d;
    int i;
    for(t=head;t!=NULL;t=t->next)
   {
    for(d=t->next;d!=NULL;d=d->next)
    {
       if(t->data>d->data)
       {
        i=t->data;
        t->data=d->data;
        d->data=i;
       }
    }

   }
   
}
int  main()
{
    insert(29);
    insert(26);
    insert(10);
    insert(12);
    insert(50);
    insert(8);
    display();
    sort();
    printf("after sort\n");
    display();

    return 0;
}
