/*
 * Filename: prog2.c
 * This program reads char[] and int[] from keyboard then sort
 * the int[] the order based on user input
 * 
 * Author Romeo Mai
 * Assignement: Spring 2014 ICS-365 #2
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<conio.h>

int GetUserInput(char strInput[100])
{
	char insert[] = "insert";	// 1
	char print[] = "print";		// 2
	char exit[] = "exit";		// 3
	int i;

	int _numRequest = 0;

	//scanf("%s", strInput);
	gets(strInput);		/* better method read in whole string */

	for(i = 0; strInput[i]; i++)
	{
		strInput[i] = tolower(strInput[i]);
	}

	if(strcmp(strInput,insert) == 0)
		_numRequest = 1;
	else if (strcmp(strInput, print) == 0)
		_numRequest = 2;
	else if (strcmp(strInput, exit) == 0)
		_numRequest = 3;

	return _numRequest;
}

int readint()
{
	int num;

	scanf("%d", num);

	return num;
}

/*
 * Program execution begins from here.
 * parameters: none
 */
int main()
{
	int list[100];
	int max_size = 100;
	int arrLength;
	int str_maxSize;
	char ch = 'y';
	int i;
	int isAscending;

	char uInput[100];
	int numRequest;
	int num;
	
	while(1)
	{
		printf("\n");
		printf("Enter a request (insert | print | exit) : ");
		numRequest = GetUserInput(uInput);

		
		if(numRequest == 1)
		{
			//insert
			printf("Insert block");
			printf("enter a number: ");
			
			num = readint();
			
			printf("You entered: %d", num);

		}
		else if(numRequest == 2)
		{
			//print
			printf("Print block");
		}
		else if (numRequest == 3)
		{
			//exit
			return 1;
		}
		else if(numRequest == 0)
		{
			printf("ERROR: unknow request '%s' \n", uInput);
		}

		//read_int_p2(list, max_size, &arrLength);

		//bubblesort_p2(list, arrLength, isAscending);

		continue;

		printf("Result: \n");
		for(i = 0; i < arrLength; i++)
			printf("%d\n", list[i]);
	

		printf("\nPress 'y' to restart the program or press anything else to exit ... ");
		ch = getch();
		if(ch != 'y')
		{
			return 1;
		}
	}
	return 1;
}