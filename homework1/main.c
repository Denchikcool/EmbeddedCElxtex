#include <stdio.h>

void binaryFormat(int number, int flag) 
{
	int counter = 0;
	printf("Binary format of number %d is: ", number);

    
	for (int i = 31; i >= 0; i--) 
	{
		unsigned int temp = (unsigned int)(number >> i) & 1;
		printf("%u", temp);
		if (flag && number >= 0) 
		{
		    counter += temp;
		}
	}

	printf("\n");
	if (flag && number >= 0) 
	{
		printf("Count of 1: %d\n", counter);
	}
}


void swapByte(int number, int swapValue) 
{
	printf("Before swap: ");
	binaryFormat(number, 0);

	int thirdByte = swapValue & 0xFF;
	int result = (number & 0xFF00FFFF) | (thirdByte << 16);

	printf("After swap: ");
	binaryFormat(result, 0);
}


int main(void) 
{
	int number;
	printf("Enter number: \n");

	if (scanf("%d", &number) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

    	binaryFormat(number, 1);

	if (number >= 0) 
	{
		int swapValue;
		printf("Enter value to swap: ");
		if (scanf("%d", &swapValue) != 1) 
		{
		    printf("Invalid input for swap value.\n");
		    return 1;
		}
		swapByte(number, swapValue);
	}

	return 0;
}

