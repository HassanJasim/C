#include <stdio.h>
int main ()
{
	int n = 0; 
	int block, remainder;

	while(n <= 0 || n > 50)
	{	
		printf("Enter the number of squares between 0 and 50: ");
		scanf("%d", &n);
	}

	block = n/5;
	remainder = n%5;

	for (int i = 0; i < block; i++)
	{
		printf("### ### ### ### ###\n");
		printf("### ### ### ### ###\n");
		printf("### ### ### ### ###\n");
		printf("\n");
	}
	for (int i = 0; i < remainder; i++)
	{
		printf("### ");
	}
	printf("\n");
	for (int i = 0; i < remainder; i++)
	{
		printf("### ");
	}
	printf("\n");
	for (int i = 0; i < remainder; i++)
	{
		printf("### ");
	}
	printf("\n");
}
