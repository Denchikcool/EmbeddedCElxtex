#include <stdio.h>

void PrintNegativeBinary(int number)
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
	int number;
	printf("Enter negative number: \n");
	scanf("%d", &number);
	if(number >= 0)
	{
		printf("You must enter negative number!");
		return 1;
	}
	printf("Binary representation of negative number is: \n");
	PrintNegativeBinary(number);
	return 0;
}
