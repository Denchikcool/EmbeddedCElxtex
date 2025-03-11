#include <stdio.h>

void PrintBinary(unsigned int number)
{
	int bits = sizeof(number) * 8;
	
	for(int i = bits - 1; i >= 0; i--)
	{
		int bit = (number >> i) & 1;
		printf("%d", bit);
		if(i % 8 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int main()
{
	unsigned int number;
	printf("Enter your number: \n");
	scanf("%u", &number);
	printf("Binary representation is: \n");
	PrintBinary(number);
	return 0;
}
