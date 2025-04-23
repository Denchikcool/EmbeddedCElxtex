#include <stdio.h>
#include <string.h>

#define N 80


int main(void)
{
	char str[N], substr[N];
	char *strPtr = NULL, *substrPtr = NULL, *tempPtr = NULL;
	int match = 1, index = -1;
	
	printf("Enter string: \n");
	fgets(str, N, stdin);
	str[strcspn(str, "\n")] = '\0';
	
	printf("Enter substring: \n");
	fgets(substr, N, stdin);
	substr[strcspn(substr, "\n")] = '\0';
	
	strPtr = str;
	substrPtr = substr;
	
	while(*strPtr != '\0')
	{
		substrPtr = substr;
		if(*strPtr == *substrPtr)
		{
			tempPtr = strPtr;
			while((*substrPtr != '\0') && (*strPtr != '\0'))
			{
				if(*substrPtr == *strPtr)
				{
					strPtr++;
					substrPtr++;
				}
				else
				{
					match = 0;
					break;
				}
			}
			if(!match)
			{
				match = 1;
				strPtr = tempPtr;
				strPtr++;
				tempPtr = NULL;
			}
			else
			{
				if((*strPtr == '\0') && (*substrPtr != '\0'))
				{
					index = -1;
					tempPtr = NULL;
					break;
				}
				else
				{
					index = tempPtr - str;
					break;
				}
			}
		}
		else
		{
			strPtr++;
		}
	}
	
	
	printf("Pointer of beginning of substring in string = %p\n", tempPtr);
	printf("Substring starting with index = %d\n", index);
}
