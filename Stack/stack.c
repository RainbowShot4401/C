#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct stk
{
	int data[MAX_SIZE];
	int top;
}stack;

stack var = {.data = {0},.top = -1};

int is_full()
{
	if(var.top < (MAX_SIZE-1))
		return 0;
	else
		return 1;	
}

void push(int value)
{
	var.top++;
	var.data[var.top] = value;

	if(is_full())
	{	
		int i=0;
		printf("is full \n");
		while(i<MAX_SIZE)
		{
			printf("data is %d\n",var.data[i]);
			i++;	
		}

	}
}

void pop()
{
	var.data[var.top] = NULL;
	var.top--;
}

int main()
{
	int info[MAX_SIZE] = {5,4,3,2,1};
	int length = sizeof(info)/sizeof(int);
	int i=0;	

	while(i<length)
	{
		push(info[i]);
		i++;
	}
		
	return 0;
}
