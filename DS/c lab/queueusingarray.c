#include<stdio.h>
int f=-1;
int r=-1;
int q[5];
void enqueue(int n)
{
    if(r==4)
    {
        printf("queue is full");
    }
    else
    {
      if(f==-1)
      {
        f=0;
      }
      r++;
      q[r]=n;
     // printf("%d\n",q[r]);

    }
}
void dequeue()
{
    if(f==-1)
    {
        printf("queue is empty\n");
    }
   else if(f==r)
    {
        f=-1;
        r=-1;
    }
    else{ 
        printf("%d",q[f]);

     f++;
    
}
    
}
int main()
{
    enqueue(10);
    enqueue(20);
     dequeue();

}