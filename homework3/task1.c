#include <stdio.h>

void binaryFormat(int number) 
{
	printf("Binary format of number %d is: ", number);

	for (int i = 31; i >= 0; i--) 
	{
		unsigned int temp = (unsigned int)(number >> i) & 1;
		printf("%u", temp);
	}

	printf("\n");
}


int main(void) 
{
	int number, swapValue;
	printf("Enter number positive: \n");

	if (scanf("%d", &number) != 1) {
		printf("Invalid input.\n");
		return 1;
	}
	
	if(number < 0)
	{
		printf("Enter only positive number!");
		return 1;
	}
	
    	binaryFormat(number);

	printf("Enter number to swap in third byte: \n");
	
	if (scanf("%d", &swapValue) != 1) {
		printf("Invalid input.\n");
		return 1;
	}
	
	if(swapValue < 0)
	{
		printf("Enter only positive swap number!");
		return 1;
	}
	
	binaryFormat(swapValue);
	
	char *numberPtr = (char*)&number;
	
	numberPtr += 2;
	
	*numberPtr = (char)swapValue;
	
	printf("Value has changed in third byte. Your number now is: \n");
	binaryFormat(number);

	return 0;
}

