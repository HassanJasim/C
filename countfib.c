#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
	int n, x[50], div2 = 0, div3 = 0, div5 = 0, div6 = 0, div10 = 0, div15 = 0, rest = 0;
	printf("Enter a positive number n: ");
	scanf("%d", &n);
	
	x[0] = 1;
	x[1] = 1;
	int i = 1;
	printf("1");
	while ( n > x[i] )
	{	
		printf(" %d", x[i]);
		x[i+1] = x[i] + x[i-1];
		
		if(x[i] % 2 == 0)
			div2++;
		if(x[i] % 3 == 0)
			div3++;
		if(x[i] % 5 == 0)
			div5++;
		if(x[i] % 6 == 0)
			div6++;
		if(x[i] % 10 == 0)
			div10++;
		if(x[i] % 15 == 0)
			div15++;
		if(x[i] % 2 != 0 && x[i] % 3 != 0 && x[i] % 5 != 0 && x[i] % 6 != 0 && x[i] % 10 != 0 && x[i] % 15 != 0)
			rest++;
		
		i++;
	}
	printf("\n");
	printf("Divisible by: \n");
	printf("2  %d\n", div2);
	printf("3  %d\n", div3);
	printf("5  %d\n", div5);
	printf("6  %d\n", div6);
	printf("10 %d\n", div10);
	printf("15 %d\n", div15);
	printf("-  %d\n", rest);
}
