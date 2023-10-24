#include<stdio.h>
#include<malloc.h>
struct node{
    int c;
    int e;
    struct node *next;
};
typedef struct node poly;
void insert(poly **head,int c,int e)
{
if(*head==NULL)
{
    *head=(poly*)malloc(sizeof(poly));
    (*head)->c=c;
    (*head)->e=e;
    (*head)->next=NULL;
}
else{
    struct node*t;
    t= *head;
    while(t->next !=NULL)
    {
        t=t->next;
    }
    t->next=(poly*)malloc(sizeof(poly));
    t->next->c=c;
    t->next->e=e;
    t->next->next=NULL;
}
}
void display(poly *head)
{
if(head==NULL)
{
    printf("Polynomial is empty\n");

}
else{
    struct node *t;
    t=head;
    while(t!=NULL)
    {
        printf("%d X ^%d ",t->c,t->e);
        if(t->next!=NULL)
        {
            printf(" + ");
        }
         t=t->next;
    }

}

}
int main()
{
	int i,n1;
	poly  *p1=NULL;
	printf("enter the no of terms\n");
	scanf("%d",&n1);
	printf("enter the polynomial 1\n");

	for(i=0;i<n1;i++)
	{
		int c,e;
        printf("Enter the coeffient\n");
        scanf("%d",&c);
        printf("Enter the exponential\n");
        scanf("%d",&e);
		insert(&p1,c,e);
	}
	display(p1);
}