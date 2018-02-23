#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}*list_pointer;

list_pointer head,current;

void init()
{
	head = (list_pointer)malloc(sizeof(struct node));
	head->data=0;
	head->llink=head;
	head->rlink=head;
}

void insert(int value)
{
	list_pointer ptr = (list_pointer)malloc(sizeof(struct node));
	ptr->data = value;
	current = head->rlink;
	
	while((current != head) && (current->data > ptr->data))
		current = current->rlink;
	ptr->llink = current->llink;
	ptr->rlink = current;
	current->llink->rlink = ptr;
	current->llink        = ptr;
		
	return ;
}

void traverse()
{
	current = head->rlink;
	while(current != head)
	{
		printf("data = %d \n",current->data);
		current = current->rlink;
	}
	return ;
}

int main()
{
	int i=0;
	int data[5] = {10,20,30,40,50};
	int length  = sizeof(data)/sizeof(int);
	init();
	
	while(i<length)	
	{
		insert(data[i]);
		i++;
	}
	traverse();
	return 0;
}
