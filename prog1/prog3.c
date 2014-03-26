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
#include <stdlib.h>
#include <ctype.h>
#include<conio.h>

#define insert  1;
#define print 2;
#define exit 3;


struct int_node
{
	int node;
	struct int_node *next;
};

int GetUserInput(char strInput[100])
{
	char c_insert[] = "insert";	// 1
	char c_print[] = "print";		// 2
	char c_exit[] = "exit";		// 3
	int i;

	int _numRequest = 0;

	//scanf("%s", strInput);
	gets(strInput);		/* better method read in whole string */

	for(i = 0; strInput[i]; i++)
	{
		strInput[i] = tolower(strInput[i]);
	}

	if(strcmp(strInput, c_insert) == 0)
		_numRequest = 1;
	else if (strcmp(strInput, c_print) == 0)
		_numRequest = 2;
	else if (strcmp(strInput, c_exit) == 0)
		_numRequest = 3;

	return _numRequest;
}

int readint()
{
	int i;
	int num;

	scanf("%d", &num);
	while (fgetc(stdin) != '\n')
		;
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

	struct int_node *root;
	struct int_node *currNode;

	root = (struct int_node *) malloc( sizeof(struct int_node) );
	root->next = 0;
	root->node = 0;

	while(1)
	{
		printf("\n");
		
		/* by pass next node error*/
		if(root->next != 0)
			currNode = root->next;
		else
			currNode = root;

		if( currNode != 0)
		{
			while ( currNode->next != 0)
			{
				/* sort node tree */
				if(currNode->node > currNode->next->node)
				{
					int tmp = currNode->node;
					currNode->node = currNode->next->node;
					currNode->next->node = tmp;
					currNode = root;
				}
				else
				{
					currNode = currNode->next;
				}
			}
		}

		printf("Enter a request (insert | print | exit) : ");
		numRequest = GetUserInput(uInput);

		//insert
		if(numRequest == 1)
		{
			struct int_node *node;

			printf("enter a number: ");
			num = readint();
			node = (struct int_node *) malloc( sizeof( struct int_node) );
			node->next = 0;
			node->node = num;

			currNode->next = node; 
		}
		//print
		else if(numRequest == 2)
		{
			currNode = root->next;
			while (currNode != NULL)
			{
				printf( "%d ", currNode->node);
				currNode = currNode->next;
			}
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
	}
	return 1;
}