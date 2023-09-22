#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
typedef  struct node queue;
queue *f=NULL;
queue *r=NULL;
void enqueue(int e)
{
    queue *t;
    t=(queue *)malloc(sizeof(queue));
    t->data=e;
    t->next=NULL;
    if(r==NULL)
    {
        r=f=t;

    }
    else{
        r->next=t;
        r=t;

    }
}


void dequeue()
{
    if(f==NULL)
    {
        printf("Queue is empty\n");
    }
    else{
        printf("%d",f->data);
        f=f->next;
        if(f==NULL)
        {
            r=NULL;

        }
    }
}
int menu()
{
    int ch;
    printf("\nEnter the choice\n 1-enqueue\n 2-dequeue\n 3-exit\n");
    scanf("%d",&ch);
    return ch;
    
}
int  main()
{
   int ch ,e;
   for(ch=menu();ch!=3;ch=menu())
   {
    switch (ch)
    {
    case 1:
        printf("Enter the element to enqueue\n");
        scanf("%d",&e);
        enqueue(e);
        break;
    case 2:
        dequeue();
        break;
    default:
        printf("Enter valid choice\n");
        break;
    }
   }
return 0;

}

