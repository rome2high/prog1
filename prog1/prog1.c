/*
 * Filename: prog1.c
 * This program reads integers from keyboard than compaire
 * if the amptitude of the second half matching the first half
 * 
 * Author Romeo Mai
 * Assignement: Spring 2014 ICS-365 #1
 */

#include <stdio.h>

/*
 * reads a list of integers from the keyboard into an array.
 * parameter: list - the array
 * parameter: max_size - maximum size of the array
 * parameter: *arrElements - number of elements in the list array
 */
void read_int_p1(int list[], int max_size, int *arrElements)
{
	int i = 0;
	int num;
	
	for( i = 0; i < max_size; i++ )
    {
		scanf( "%d", &num );
		if(num <= 0)
		{
			*arrElements = i;
			return;
		}
		// else continued
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
int print_integers_p1(int list[], int size)
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

int check_Sequences_p1(int list[], int totalNumEnter)
{
	int i;
	int j;
	int retVal;

	retVal = 1;

	for ( i = 0; i < totalNumEnter/2; i++ )
    {
		//second sequence start index
		j = i + totalNumEnter/2;

		if ( list[i] <= list[i+1])
		{
			retVal++;
			if( list[j] <= list[j+1])
			{
				retVal--;
			}
		}
		else if( list[i] > list[i+1] )
		{
			retVal++;
			if ( list[j] > list[j+1] )
			{
				retVal--;
			}
		}
    }

	return retVal;
}

int check_Sequences_2_p1(int list[], int totalNumEnter)
{
	int i;
	int j;
	int retVal;

	retVal = 1;

	for ( i = 0; i < totalNumEnter/2; i++ )
    {
		//second sequence start index
		j = i + totalNumEnter/2;

		if ( list[i] <= list[i+1])
		{
			retVal++;
		}
		if( list[j] <= list[j+1])
		{
			retVal--;
		}
		if(retVal != 1)
		{
			return retVal;
		}
    }

	return retVal;
}

/*
 * Program execution begins from here.
 * parameters: none
 */
int main_p1()
{
    int list[100];
	int max_size = 100;
	int totalNumEnter;
	
	totalNumEnter = 0;


	//call a by-reference functiong using operator & to change value of arrElements
	//while (totalNumEnter < 4) {
	//	printf( "Enter a list of 4 or more integers separete by spaces and end with 0:\n" );
	//	read_int( list, max_size, &totalNumEnter);
	//}

	printf( "Enter a list of 4 or more integers separete by spaces and end with 0:\n" );
	read_int_p1( list, max_size, &totalNumEnter);

	if(check_Sequences_p1(list,totalNumEnter) == 1)
	{
		printf( "[MATCH] Two sequences are order equivalent\n" );
	}
	else
	{
		printf( "[UNMATCH] Two sequences are NOT order equivalent\n" );
	}
	
	printf( "Enter a number and hit ENTER to exit the program\n" );
	scanf( "%d", &totalNumEnter );
    
	return 0;
}