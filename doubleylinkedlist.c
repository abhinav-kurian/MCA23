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
void delete()
{
   int e;
   printf("Enter the element to delete");
   scanf("%d",&e);

    node *t, *prev;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
   
    else if (head->data == e )
    {
        t = head;
        head = head->next;
        if(head != NULL)
            head->prev=NULL;
        free(t);
    }
    else
    {
        t = head;

        while (t != NULL && t->data !=e )
        {
            t = t->next;
        }

        if (t == NULL)
        {
            printf("Element not found\n");
        }
        else
        {
            t->prev->next = t->next;
            if(t->next!=NULL)//condition to check last node
            {
              t->next->prev=t->prev;
              free(t);
            }
            
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
