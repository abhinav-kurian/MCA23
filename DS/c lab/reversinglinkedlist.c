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
// Function to display the linked list in reverse order without using recursion
void displayReverse(struct node* t) {
    struct node* current = t;
    struct node* prev = NULL;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    t = prev;

    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void display(node *t)
{
    if(t->next !=NULL)
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
    displayReverse(head);
  
}