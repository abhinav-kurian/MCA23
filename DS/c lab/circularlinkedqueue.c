#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node queue;
queue * rear=NULL;
queue * front=NULL;
void enqueue(int e)
{
    queue * t =(queue *)malloc(sizeof(queue));
    t->data=e;
    t->next=NULL;
    if(rear==NULL)
    {
        front=rear=t;
        rear->next=rear;

    }
    else{
        t->next=rear;
        rear->next=t;
        rear=t;
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("queue is empty ");

    }
    else if(front==rear)
    {
        printf("%d\n",front->data);
        front=rear=NULL;
    }
    else{
        printf("%d\n",front->data);
        front=front->next;
        rear->next=front;

    }
}
int menu()
{
    int ch;
    printf("\n Enter the choice \n1-enqueue \n2-dequeue\n3- exit\n");
    scanf("%d",&ch);
    return ch;
}
void main()
    {
    int ch , e;
    for(ch=menu();ch!=3;ch=menu())
    {
        switch (ch){
            case 1 :
                    printf("Enter the element\n");
                    scanf("%d",&e);
                    enqueue(e);
                    break;
           case 2:
                    dequeue();
                    break;
           default :
                    printf("Enter the correct option \n");
                    break;

        }
    }
    }