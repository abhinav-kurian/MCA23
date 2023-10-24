#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
void insert( int e)
{
    struct node *p;
    struct node *x;
    if(root==NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=e;
        root->left=NULL;
        root->right=NULL;

    }
    else{
        p=root;
        while(p!=NULL)
        {
            x=p;
            if( p->data<e)
            {
                p=p->right;
            }
            else{
                p=p->left;
            }
        }
        if( x->data < e)
        {
            x->right=(struct node*)malloc(sizeof(struct node));
            x->right->data=e;
            x->right->right=NULL;
            x->right->left=NULL;

        }
        else{
            x->left=(struct node*)malloc(sizeof(struct node));
            x->left->data=e;
            x->left->right=NULL;
            x->left->left=NULL;
        }
    }
}
void display(struct node *r)
{
   if(r !=NULL)
   {
        display(r->left);
        printf("%d\t",r->data);
        display(r->right);
   }
}
int main()
{
    insert(10);
    insert(30);
    insert(20);
    insert(50);
    display(root);

}