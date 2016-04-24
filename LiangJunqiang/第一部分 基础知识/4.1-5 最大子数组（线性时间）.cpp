#include <stdio.h>
#define Negative_infinity ((1 << (sizeof(int)*8 - 1)) | 1)
using namespace std;
void FIND_MAXIMUM_SUBARRAY(int a[], int &size, int &s, int &e, int &max);
int main()
{
	int A[100], size, s, e, max;
	FIND_MAXIMUM_SUBARRAY(A, size, s, e, max);
	if(s == -1 && e == -1)
		printf("max is %d start from %d to %d\n", max, max, max);
	else
		printf("max is %d start from %d to %d\n", max, s + 1, e + 1);
	return 0;
}

void FIND_MAXIMUM_SUBARRAY(int a[], int &size, int &s, int &e, int &max)
{
	int i;
	int neg_max = Negative_infinity;
	bool neg_flag = true;
	printf("input the array size: ");
	scanf("%d", &size);
	printf("input %d number:\n", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] >= 0)
			neg_flag = false;
		if(neg_max < a[i])
			neg_max = a[i];
	}
	if(neg_flag == true)
	{
		max = neg_max;
		return;
	}
	int add = 0, l = 0, r = 0;
	s = -1;
	e = -1;
	max = Negative_infinity;
	while(r < size)
	{
		add += a[r];
		if(add >= 0)
		{
			if(add >= max)
			{
				max = add;
				s = l;
				e = r;
			}
			r++;
		}
		else
		{
			r++;
			l = r;
			if(r < size)
				add = 0;
		}
	}
	
}









