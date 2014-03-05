/*
 * Filename: prog1.c
 * This program reads integers from keyboard than compaire
 * if the amptitude of the second half matching the first half
 * 
 * Author Romeo Mai
 * Assignement: Spring 2014 ICS-365 #1
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * reads a list of integers from the keyboard into an array.
 * parameter: list - the array
 * parameter: max_size - maximum size of the array
 * parameter: *arrElements - number of elements in the list array
 */
void read_int(int list[], int max_size, int *arrLength)
{
	int i = 0;
	int num;
	
	for( i = 0; i < max_size; i++ )
    {
		scanf( "%d", &num );
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
 * prints a list of integers.
 * parameter: list - the array
 * parameter: size - size of the array
 * return: 1 if true, else 0
 */
int print_integers(int list[], int size)
{
    int i;
	int j = size/2;	//start index of second sequence

    printf ( "You entered: " );

    for ( i = 0; i < j-1; i++ )
    {
		if ( list[i] <= list[i+1])
		{
			printf( "%d - %d vs ", list[i], list[i+1]);
			if( list[i+j] <= list[i+j+1])
			{
				printf( "%d - %d \n", list[i+j], list[i+j+1]);
			}
			else
			{
				printf( "Sequences are not match");
				return 0;
			}
		}
		else if( list[i] > list[i+1] )
		{
			printf( "%d - %d vs ", list[i], list[i+1]);
			if ( list[i+j] > list[i+j+1] )
			{
				//printf( "%d",list[4]);
				printf( "%d - %d \n", list[i+j], list[i+j+1]);
			}
			else
			{
				printf( "Sequences are not match");
				return 0;
			}
		}
		else 
		{
			printf( "Sequences are not match");
			return 0;
		}

        //printf( "%d ", list[i] );
		return 0;
    }

    printf ( "Hot Stuff \n" );
	return 1;
}

int GetSortOrder()
{
	char strInput[100];
	char up[] = "up";
	char down[] = "down";
	int i;
	
	while(1)
	{
		printf("Enter sort order (up | down) : ");
		//scanf( "%s", strInput );
		gets(strInput);		/* better method read compare whole string */

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

void mySwap(int *p, int *q)
{
	int x;
	x = *p;
	*p = *q;
	*q = x;
}

void bubblesort(int list[], int arrLength, int isAscending)
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
int main()
{
	int list[100];// = {10, 2, 1, 3, 40, 20};
	int max_size = 100;
	int arrLength;
	int i;
	int str_maxSize;
	char ch = 'y';

	int isAscending;
	
	while(1)
	{
		printf("\n");
		isAscending = GetSortOrder();
		printf("Enter a sequence of numbers: ");
		read_int(list, max_size, &arrLength);

		bubblesort(list, arrLength, isAscending);

		printf("Result: \n");
		for(i = 0; i < arrLength; i++)
			printf("%d\n", list[i]);
	

		printf("\nPress 'y' to restart the program or press anything else to exit ... ");
		ch = getch();
		if(ch != 'y')
		{
			return 0;
		}
	}

	return 0;
}