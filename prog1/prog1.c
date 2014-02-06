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
void read_int(int list[], int max_size, int *arrElements)
{
	int i = 0;
	int num;
	
	for( i = 0; i < max_size; i++ )
    {
		scanf( "%d", &num );
		if(num <= 0)
		{
			*arrElements = *arrElements + i;
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
 */
void print_integers(int list[], int size)
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
				return;
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
				return;
			}
		}
		else 
		{
			printf( "Sequences are not match");
			return;
		}

        //printf( "%d ", list[i] );
    }

    printf ( "Hot Stuff \n" );
}

/*
 * Program execution begins from here.
 * parameters: none
 */
int main()
{
    int list[100];
	int max_size = 100;
	int arrElements = 0;

    printf( "Enter a list of integers separete by spaces: " );

	//call a by-reference functiong using operator & to change value of arrElements
	read_int( list, max_size, &arrElements);
	//printf("Array size %d", arrElements);

    print_integers( list, arrElements);

	scanf( "%d", &max_size );
}





