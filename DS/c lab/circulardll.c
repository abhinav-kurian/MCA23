#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;
node *head;
void insert(int e)
{
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->data=e;
        head->next=head; 
        head->prev=head;        
    }
    else{
    node *t;
    t=head;
    while(t->next!=head)
    {
        t=t->next;
    }
    t->next=(node *)malloc(sizeof(node));
    t->next->data=e;
    t->next->next=head;
    t->next->prev=t;
    head->prev=t->next;
    }

}
void display()
{
    if(head==NULL)
    {
        printf("Linked list is empty\n");

    }
    else{
        node *t;
        t=head;
        do{
            printf("%d\t",t->data);
            t=t->next;
        }
        while(t != head);

    }    
}
void delete()
{
    int e;
    printf("\nEnter the element to delete\n");
    scanf("%d",&e);
    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else if( head->data ==e && head->next==head )
    {
        head=NULL;
    }
    else if(head->data==e && head->next!=head)
    {
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;
    }
    else{
        node *t;
        t=head;
        t=t->next;
        while(t != head && t->data != e)
        {
            t=t->next;
        }
        if(t == head )
        {
            printf("Element not found\n");
        }
        else{
            
            t->prev->next = t->next;
            t->next->prev=t->prev;
            
        }
    }
}

int menu()
{
    int ch;
    printf("\nEnter the choice\n 1-insert \n 2-display \n 3-delete\n 4-exit\n");
    scanf("%d",&ch);
    return ch;
    
}
int  main()
{
   int ch ,e;
   for(ch=menu();ch!=4;ch=menu())
   {
    switch (ch)
    {
    case 1:
        printf("Enter the element to insert\n");
        scanf("%d",&e);
        insert(e);
        break;
    case 2:
        display();
        break;
    case 3:
     delete();
    break;
    }
   }
return 0;

}

