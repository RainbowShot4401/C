#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int coef;
	int exp;
}NonZeroTerm;

#define MAX_SIZE 100

typedef struct
{
	int count;
	NonZeroTerm term[MAX_SIZE];
}polynomial;


void show_attach(polynomial *p)
{
	int i =0;
	while(i<p->count)
	{
		printf("---------------------------------\n");
		printf("冪次 = %d \n",p->term[i].exp);
		printf("coef = %d \n",p->term[i].coef);
		printf("exp  = %d \n",p->term[i].exp);
		printf("---------------------------------\n");
		i++;
	}
	return ;
}

void show_count(polynomial *p)
{
	int i =0;
	while(i<p->count)
	{
		printf("---------------------------------\n");
		printf("* count *\n");
		printf("---------------------------------\n");
		printf("冪次 = %d \n",p->term[i].exp);
		printf("coef = %d \n",p->term[i].coef);
		printf("exp  = %d \n",p->term[i].exp);
		printf("---------------------------------\n");
		i++;
	}
	return ;
}


void attach(polynomial *p,int var1,int var2)
{
	if(p->count < MAX_SIZE)
	{
		p->term[p->count].coef = var1;
		p->term[p->count].exp  = var2;
		p->count++;
	}
	return;
}

void p_add(polynomial *a, polynomial *b, polynomial *c)
{
	int i=0,count;
	
	if(a->count >= b->count)
		count = a->count;
	else
		count = b->count;
	
	while(i<count)
	{
		if(a->term[i].exp == b->term[i].exp)
		{
			int var1,var2;
			
			var1 = a->term[i].coef + a->term[i].coef;
			var2 = a->term[i].exp;
			attach(c, var1, var2);
 		}
		else
		{
			if(a->term[i].exp > b->term[i].exp)
			{
				attach(c, a->term[i].coef, a->term[i].exp);
				attach(c, b->term[i].coef, b->term[i].exp);
			}
			else
			{
				attach(c, b->term[i].coef, b->term[i].exp);
				attach(c, a->term[i].coef, a->term[i].exp);
			}
		}
		i++;
	}
	show_count(c);
	return ;
}

int main()
{
	polynomial a,b,c;
	a.count = 0;
	b.count = 0;
	c.count = 0;
	
	attach(&a,5,4);
	attach(&a,2,3);
	attach(&a,3,0);
	
	attach(&b,5,4);
	attach(&b,2,2);
	attach(&b,3,0);
	
	show_attach(&a);
	show_attach(&b);
	p_add(&a, &b, &c);
    //show_attach(&c);
	
	return 0;
}
