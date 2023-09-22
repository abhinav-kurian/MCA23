#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main(){

    int *p;
    p=(char *)malloc(100*sizeof(char));

    printf("enter string : ");
    scanf("%s",p);

    printf("%s",*p);

    int y=strlen(p);

    p=realloc(p,y*sizeof(char));

    printf("enter string again: ");
    scanf("%s",p);
    
    return 0;
}
