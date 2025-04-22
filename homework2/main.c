#include <stdio.h>

#define N 5

void PrintMatrix(int a[N][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void PrintArray(int a[N])
{
	for(int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
}

void Task1()
{
	int number = 1;
	int a[N][N];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			a[i][j] = number;
			number++;
		}
	}
	printf("Filled matrix of size %dx%d: \n", N, N);
	PrintMatrix(a);
	printf("\n");
}

void Task2()
{
	int a[N];
	
	for(int i = 0; i < N; i++)
	{
		a[i] = i + 1;
	}
	
	printf("Array before swiping elements: \n");
	PrintArray(a);
	printf("\n");
	
	for(int i = 0; i < N / 2; i++)
	{
		int temp = a[i];
		a[i] = a[N - 1 - i];
		a[N - 1 - i] = temp;
	}
	
	printf("Array after swiping elements: \n");
	PrintArray(a);
	printf("\n\n");
}

void Task3()
{
	int a[N][N];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(i + j >= N - 1) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	
	printf("Triangle filled matrix: \n");
	PrintMatrix(a);
	printf("\n\n");
}

void Task4()
{
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int k = 1, i = 0, j = 0;
	int a[N][N];
	
	while(k <= N * N)
	{
		a[i][j] = k;
		if(i == i1 && j < N - j2 - 1) ++j;
		else if(j == N - j2 - 1 && i < N - i2 - 1) ++i;
		else if(i == N - i2 - 1 && j > j1) --j;
		else --i;
		
		if((i == i1 + 1) && (j == j1) && (j1 != N - j2 - 1))
		{
			++i1;
			++i2;
			++j1;
			++j2;
		}
		++k;
	}
	
	printf("Spiral filled matrix: \n");
	PrintMatrix(a);
	printf("\n");
}

int main(void)
{
	Task1();
	Task2();
	Task3();
	Task4();
	return 0;
}
