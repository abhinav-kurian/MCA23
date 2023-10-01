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
void display(node *t)
{
    if(t!=NULL)
    {
        display(t->next);
    }
    
    printf(" %d ",t->data);
}
int  main()
{
   int n,i,e;
   printf("Enter the no. of Elements \n");
   scanf("%d",&n);
   for(i=1;i<=n;i++){
    printf("Enter the element %d\n",i);
    scanf("%d",&e);
    insert(e);
   }
   printf("The reversed LIinked list is\n ");
    display(head);
}