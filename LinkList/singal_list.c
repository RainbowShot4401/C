#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
        struct node *next;
}list_node,*list_pointer;

list_pointer head,current,previous;

int init_node()
{
	head = (list_pointer)malloc(sizeof(struct node));
	head->data = 0;
	head->next = NULL;
	return 0;
}

void traverse()
{
	printf("---------------------------------------------\n");
	if(head->next != NULL)
	{
		current = head->next;
		while(current)
		{
			printf("data = %d \n",current->data);
			current = current->next;
		}
	}else
		printf("traverse failue \n");
	printf("---------------------------------------------\n");
}

int count()
{
	int amount = 0;
	current = head->next;
	
	while(current)
	{
		current = current->next;
		amount++;
	}
	return amount;
}

int insert_node_big(int value)
{
	list_pointer ptr;

	ptr = (list_pointer)malloc(sizeof(struct node));
	ptr->data = value;
	previous = head;
	current  = head->next;
	
	while((current != NULL) && (current->data > ptr->data))
	{
		previous = current;
		current  = current->next;
	}
	ptr->next      = current;
	previous->next = ptr;
	return 0;
}

int delet_node(int value)
{
	int i;
	current  = head->next;
	previous = head;
	
	while(current)
	{
		if(current->data == value)
		{
			previous->next = current->next;
			free(current);
		}
		previous = current;
		current  = previous->next;
	}
	printf("after delet.... \n");
	traverse();
	return 0;
}

int main()
{	
	int i=0;
	int data_value[4] = {50,20,30,10};
	int length = sizeof(data_value)/sizeof(int);

	init_node();	
	while(i<length)
	{
		int ret = insert_node_big(data_value[i]);
		if(ret)
			printf("insert error \n");
		i++;
	}	
	traverse();
	//delet_node(50);
	printf("count = %d\n",count());
	return 0;
}
