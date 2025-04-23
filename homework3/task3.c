#include <stdio.h>

#define N 10

int main(void)
{
	int a[N];
	int *ptr = a;
	
	for(int i = 0; i < N; i++)
	{
		*ptr = i + 1;
		ptr++;
	}
	
	ptr = a;
	printf("Filled array: \n");
	for(int i = 0; i < N; i++)
	{
		printf("%d ", *(ptr + i));
	}
	printf("\n");
	return 0;
}
