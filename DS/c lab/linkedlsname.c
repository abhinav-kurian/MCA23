#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node{
    char data[20];
    struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(char b[])
{
    if(head==NULL)
{
    head=(node*)malloc(sizeof(node));
    strcpy(head->data,b);
    head->next=NULL;

}
else
{
    node *t;
    t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=(node*)malloc(sizeof(node));
     strcpy(t->next->data,b);
     t->next->next=NULL;
}
}

void display()
{
    if(head==NULL)
    {
        printf("\nLinked list is empty\n");

    }
    else{
        node *t;
        t=head;
        while(t!=NULL)
        {
            printf("%s \t",t->data);
            t=t->next;

        }

    }
}
void delete(char c[])
{
    node *t, *prev;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (strcmp(head->data, c) == 0)
    {
        // If the element to delete is in the head node
        t = head;
        head = head->next;
        free(t);
    }
    else
    {
        t = head;
        prev = NULL;

        while (t != NULL && strcmp(t->data, c) != 0)
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
void sort()
{
   node *t;
   node *d;
   char temp[20];
   for(t=head;t!=NULL;t=t->next)
   {
    for(d=t->next;d!=NULL;d=d->next)
    {
        if(strcmp(t->data,d->data)>0)
        {
            strcpy(temp,t->data);
            strcpy(t->data,d->data);
            strcpy(d->data,temp);

        }
    }
   }
}
void reverse(node *t)
{
    if(t->next !=NULL)
    { 
       reverse(t->next);
     }
    printf(" %s\t ",t->data);

}
void count()
{
    int count =0;
    node *t;
        t=head;
        while(t!=NULL)
        {
            printf("%s \t",t->data);
            t=t->next;
            count++;

        }
         printf("\nNo of name is %d",count);

    }


int menu ()
{
    int ch;
    printf("\n Enter the choice \n1-Insert\n 2-display \n 3-delete\n 4-sort\n 5-reverse\n 6-count\n 7- exit\n");
    scanf("%d",&ch);
    return ch;
}
int main()
{
    int ch;
    char b[20];
    char c[20];
    for(ch=menu();ch!=7;ch=menu())
    {
        switch (ch)
        {
        case 1:
            printf("Enter the name\n");
            scanf("%s",b);
            insert(b);
            break;
        case 2 :
            display();
            break;
        case 3:
            printf("Enter the element to  delete\n");
            scanf("%s",c);
            delete(c);
            break;
        case 4:
            sort();
            break;
        case 5:
            reverse(head);
            break;
        case 6:
           count();
            break;
        default:
            printf("Enter the correct choice\n");
            break;
        }

    }
}
