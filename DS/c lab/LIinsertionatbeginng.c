#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;

void insert(int e)
{
   
        node *t;
        t = (node *)malloc(sizeof(node));
        t->data = e;
        t->next = head;
        head = t;
    
}
void display()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        node *t;
        t = head;
        while (t != NULL)

        {
            printf("%d\t", t->data);
            t = t->next;
        }
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(23);
    display();
    return 0;
}