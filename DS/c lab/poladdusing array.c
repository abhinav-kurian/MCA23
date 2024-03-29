#include<stdio.h>

int i;

struct poly
{
    int coeff;
    int exp;
};

struct poly p[10];

int read(int degree)
{
    
	printf("Enter the elements of polynomial: \n");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("Enter the constant term:",i);
			scanf("%d",&p[i].coeff);
		}
		else
		{
		    printf("Enter the coefficient of x^%d:",i);
		    scanf("%d",&p[i].coeff);
		}
	}
}

int disp(int degree)
{
    
    printf("The Polynomial is: \n");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("%d",p[i].coeff);
		}
		else
		{
		    printf("%dx^%d+",p[i].coeff,i);
	    }
	}
}



int main()
{
	int degree;
	printf("Enter the degree of the polynomial: ");
	scanf("%d",&degree);
	read(degree);
	disp(degree);
}
