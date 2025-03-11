#include <stdio.h>

#define ONE 1

int CountBinaryOnes(int number)
{
	int counter = 0;
	int bits = sizeof(number) * 8;
	
	for(int i = bits - 1; i >= 0; i--)
	{
		int bit = (number >> i) & 1;
		if(bit == ONE)
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	int number, count = 0;
	printf("Enter your number: \n");
	scanf("%d", &number);
	if(number <= 0)
	{
		printf("Your number must be positive!");
		return 1;
	}
	printf("Count of ones in binary representation is: ");
	count = CountBinaryOnes(number);
	printf("%d\n", count);
	return 0;
}
