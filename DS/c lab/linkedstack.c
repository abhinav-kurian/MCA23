#include<stdio.h>
#include<malloc.h>
struct node {
    int data;
    struct node *next;
    
};
struct node *top=NULL;
void push(int e)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=e;
    t->next=top;
    top=t;
}
void pop()
{
    if(top==NULL)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("\n%d\n",top->data);
        top = top->next;

    }
}
int menu()
{
    int ch;
    printf("\nEnter the choice\n 1-push\n 2-pop\n 3-exit\n");
    scanf("%d",&ch);
    return ch;
    
}
int  main()
{
   int ch ,e;
   for(ch=menu();ch!=3;ch=menu())
   {
    switch (ch)
    {
    case 1:
        printf("Enter the element to push\n");
        scanf("%d",&e);
        push(e);
        break;
    case 2:
        pop();
        break;
    default:
        printf("Enter valid choice\n");
        break;
    }
   }
return 0;

}