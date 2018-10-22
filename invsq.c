#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
	double a, x0;
	int n;
	printf("Enter a value of \"a\" (a > 0) and \"x0\" (x0 > 0) and \"n\" (n > 0): ");
	scanf("%lf %lf %d", &a, &x0, &n);
	
	
	double x[n];
	double e[n-1];
	x[0] = x0;

	for (int i = 1; i <= n; i++)
	{
		x[i] = x[i-1] * (1.5 - 0.5 * a * pow(x[i-1],2));
		e[i] = (x[i] - (1/sqrt(a))) * sqrt(a);
		
		if (e[i] < 0)
		{
			e[i] = e[i] * -1;
		}
		
		printf("%d %.15e %.2e\n", i, x[i], e[i]);
	}
}
