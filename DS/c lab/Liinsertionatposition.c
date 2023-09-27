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

void position(int e)
{

 
    node *t;
    node *a;
    int n;
    printf("\nEnter the element after which new element has to be inserted \n");
    scanf("%d",&n);
    t=head;
    while(t->next !=NULL && t->data!=n)
    {
      t=t->next;

    }
    if(t->next == NULL)
    {
        printf("Element not found\n");

    }
    else{
    a=(node*)malloc(sizeof(node));
    a->data=e;
    a->next=t->next;
    t->next=a;
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
}
int menu()
{
 int ch;
 printf("\nEnter the option \n1-Insert \n 2-Diplay\n 3-insertafterelement\n 4-Exit\n");
 scanf("%d",&ch);
 return ch;
}
int  main()
{
	int ch;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch (ch){
	
	    case 1:
	    	   printf("Enter the element");
	    	   scanf("%d",&ch);
	    	   insert(ch);
	    	   break;
	    case 2:
	    	  display();
	    	  break;
	    case 3:
              printf("Enter the element");
	    	  scanf("%d",&ch);
	    	  position(ch);
	    	  break;
	    default:
	    	printf("Invalid choise");
	   	break;
	   }
    }
 return 0;

}