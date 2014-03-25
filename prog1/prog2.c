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

/*
 * reads a list of integers from the keyboard into an array.
 * parameter: list - the array
 * parameter: max_size - maximum size of the array
 * parameter: *arrElements - number of elements in the list array
 */
void read_int_p2(int list[], int max_size, int *arrLength)
{
	int i = 0;
	int num;
	
	for(i = 0; i < max_size; i++)
    {
		scanf("%d", &num);
		if(num <= 0)
		{
			*arrLength = i;
			return;
		}
		list[i] = num;
	}
	return;
}

/*
 * reads user sort order selection and a list of integers from the keyboard into an array.
 * return: an integer; 1 if ascending, 0 if decending
 */
int GetSortOrder_p2()
{
	char strInput[100];
	char up[] = "up";
	char down[] = "down";
	int i;
	
	while(1)
	{
		printf("Enter sort order (up | down) : ");
		//scanf("%s", strInput);
		gets(strInput);		/* better method read in whole string */

		for(i = 0; strInput[i]; i++)
		{
			strInput[i] = tolower(strInput[i]);
		}

		if(strcmp(strInput,up) == 0)
		{
			return 1;
		}
		else if (strcmp(strInput, down) == 0)
		{
			return 0;
		}
		else
		{
			printf("ERROR: You entered %s \n", strInput);
		}
	}
}

/*
 * swap the the value of two pointers
 * parameter: *p , *q
 */
void mySwap_p2(int *p, int *q)
{
	int x;
	x = *p;
	*p = *q;
	*q = x;
}

/*
 * sorting an array list
 * parameter: list[] - array
 * parameter: arrLength - integer array length
 * parameter: isAscending - boolean
 */
void bubblesort_p2(int list[], int arrLength, int isAscending)
{
	int i, j;
	int *p, *q;

	for (i = arrLength; i > 0; i--)
	{
		for (j = 1 ; j < i; j++)
		{
			if(isAscending)
			{
				if (list[j-1] > list[j])
				{
					p = &list[j-1];
					q = &list[j];
					mySwap(p, q);
				}
			}
			else
			{
				if (list[j-1] < list[j])
				{
					p = &list[j-1];
					q = &list[j];
					mySwap(p, q);
				}
			}
		}
	}
}

/*
 * Program execution begins from here.
 * parameters: none
 */
int main_p2()
{
	int list[100];
	int max_size = 100;
	int arrLength;
	int str_maxSize;
	char ch = 'y';
	int i;
	int isAscending;
	
	while(1)
	{
		printf("\n");
		isAscending = GetSortOrder();
		printf("Enter a sequence of numbers (end string with a 0): ");
		read_int(list, max_size, &arrLength);

		bubblesort(list, arrLength, isAscending);

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