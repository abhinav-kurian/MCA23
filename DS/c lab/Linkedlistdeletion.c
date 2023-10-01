
#include<stdio.h>
#include<malloc.h>
struct node{
     int data;
     struct node *next;
};
typedef struct node node;
node *head = NULL;
node *t =NULL;

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
    t=head;
    while(t !=NULL)

    {
        printf("%d\t",t->data);
        t=t->next;
        
    }

    }
}
void deletefrombegin()
{
    if(head==NULL)
    {
        printf("List is Empty");

    }
    else{
        t=head;
        head =head->next;
        free(t);
    }

}
void deletefromend()
{
    if(head==NULL)
    {
        printf("\nLinked list is empty\n ");

    }
    else{
        
        t=head;
        while(t->next->next != NULL)
        {
         
          t=t->next;
        }
        free(t->next->next);
         t->next = NULL; 

    }
}
void deletelement()
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
        free(t);
    }
    else
    {
        t = head;
        prev = NULL;

        while (t != NULL && t->data !=e )
        {
            prev = t;
            t = t->next;
        }

        if (t == NULL)
        {
            printf("Element not found\n");
        }
        else
        {
            prev->next = t->next;
            free(t);
        }
    }
}


int menu()
{
    int ch;
    printf("\nEnter the choice\n 1-insert \n 2-display \n 3-delete from beginning \n 4-delete from last\n 5-delete specific element \n 6-exit\n");
    scanf("%d",&ch);
    return ch;
    
}
int  main()
{
   int ch ,e;
   for(ch=menu();ch!=6;ch=menu())
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
        deletefrombegin();
        break;
    case 4:
         deletefromend();
         break;

    case 5:
        deletelement();
        break;
    default:
        printf("Enter valid choice\n");
        break;
    }
   }
return 0;

}