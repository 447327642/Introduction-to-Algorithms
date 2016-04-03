#include <stdio.h> 
#include <math.h>
#define MAX	1000
int main()
{
	double a, b;
	int n;
	for(n = 2; n < MAX; n++)
	{
		a = (double)n / 8.0;
		b = log((double)n) / log((double)2);
		if(a >= b)
			break;
	}
	printf("n > 2 且 2 < %d 时，插入排序优于归并排序\n", n);
	return 0;
}
