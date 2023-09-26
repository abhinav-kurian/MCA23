#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *next;
	
};
struct node *head=NULL;
void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=e;
		head->next=head;
	}
	else
	{
		t=head;
		while(t->next!=head)
		{
			t =t->next;
			
		}
		t->next =(struct node*)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=head;
	}
}
void display()
{
	struct node *t;
	if(head==NULL)
	{
		printf("\n circular linked list is empty");
		
	}
	else
	{ 
		t=head;
		do{
			printf("%d\n",t->data);
			t=t->next;
		}
		while(t!=head);	
	}
}
void deletion()
{
	int e;
	struct node *t;
	printf("Enter the element to delete");
	scanf("%d",&e);
	if(head==NULL) //no elements
	{
		printf("circular list is empty");
	}
	else if(head->data==e && head->next==head)//head with only one element
	{
		head = NULL;
	}
	else if(head->data==e )//from head with more than one element
	{
		t = head;
		while(t->next != head)
		{
			t=t->next;
		}
		head=head->next;
		t->next=head;
	}
	else//intemediate node
	{
		t=head;
		while(t->next!=head && t->next->data!=e)
		{ 
	       t=t->next;
	    }
	    if(t->next==head)
	    {
	    	printf("Element not found");
		}
		else
		{
		    
			t->next=t->next->next;
		}
	}
}
int menu()
{
 int ch;
 printf("Enter the option \n1-Insert \n 2-Diplay\n 3-Delete\n 4-Exit\n");
 scanf("%d",&ch);
 return ch;
}
void main()
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
	    	  deletion();
	    	  break;
	    default:
	    	printf("Invalid choise");
	   	break;
	   }
}

}