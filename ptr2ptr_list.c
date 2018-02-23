#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *n_node;
	struct Node *p_node;
}list_ptr,list_node;

list_ptr *current = NULL;
list_ptr *head    = NULL;
list_ptr **list   = NULL;

list_ptr *Create_Node(int data)
{
	list_node *n = (list_node *)malloc(sizeof(struct node));
	n->data = data;
	n->n_node = NULL;
	n->p_node = NULL;
	
	return n;
}

void Insert_Node(list_node *n)
{
	if(head == NULL)
	{
		printf("Create Head \n");
		head = n;
		current = head;
	}
	else
	{
		n->p_node = current;
		current->n_node = n;
		current = n;
	}
}

int main()
{
	int var[5] = {0,1,2,3,4};
	
	for (int i=0; i<5; i++)
	{
		list_node *in_node = Create_Node(var[i]);
		Insert_Node(in_node); 	
	}
	
//	for (list_ptr *show = head; show->n_node; show = show->n_node)
//		printf("data is %d \n", show->data);
	for (list_ptr **list = &head; *list != NULL; *list = (*list)->n_node)
		printf("data is %d \n", (**list).data);
	
}

