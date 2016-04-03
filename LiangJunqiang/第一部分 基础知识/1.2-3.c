#include <stdio.h>
#include <math.h>
#define MAX 100
int main()
{
	int n;
	long a, b;
	for(n = 1; n < MAX; n++)
	{
		a = 100 * n * n;
		b = (long)pow((double)2, (double)n);
		if(a <= b)
			break;
	}
	printf("%d\n", n);
	return 0;
 } 
