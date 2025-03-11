#include <stdio.h>

int ReplaceThirdByte(int number, unsigned char newByte)
{
	number = number & ~(0xFF << 16);
	number = number | (newByte << 16);
	return number;
}

void PrintBinary(int number)
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
	int number, newNumber;
	unsigned char newByte;
	
	printf("Enter positive number: \n");
	scanf("%d", &number);
	if(number <= 0)
	{
		printf("You must enter positive number!");
		return 1;
	}
	printf("\nEnter new value to third byte: \n");
	scanf("%hhu", &newByte);
	printf("Binary representation of old number: \n");
	PrintBinary(number);
	newNumber = ReplaceThirdByte(number, newByte);
	printf("New number in binary representation: \n");
	PrintBinary(newNumber);
	printf("New number in decimer representation: %d\n", newNumber);
	return 0;
}
