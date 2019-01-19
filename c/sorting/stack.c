#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int data;
};

int a[] =
#if 1 
{9,1,5,6,4,3,8,2,7,0};
#else
{1,11,22,33,44,55,66,77,88};
#endif
int n = sizeof(a)/sizeof(int);

static int peek(struct node *top)
{
	return top->data;
}

static int pop(struct node **top)
{
	struct node *tmp, *t;
	int data;

	tmp = *top;
	t = *top;
	*top = t->next;
	tmp->next = NULL;
	data = tmp->data;
	free(tmp);
	return data;
}

static void push(struct node **top, int data)
{

	struct node *tmp = (struct node *)calloc(1, sizeof(struct node));
	tmp->data = data;
	tmp->next = *top;
	*top = tmp;
}

#define isEmpty(__top) (__top == NULL) 

int main(int argc, char **argp)
{
	struct node *s1 = NULL, *s2 = NULL;
	int i = 0;
	int element, tmp;

	for (i = n-1; i >= 0; i--)
		push(&s2, a[i]);

	while (!isEmpty(s2)) {
		element = pop(&s2);
		if (isEmpty(s1)) {
			push(&s1, element);
		} else {
			while (element > peek(s1)) {
				tmp = pop(&s1);
				push(&s2, tmp);
			}
			push(&s1, element);
		}
	}
#if 1 
	while (!isEmpty(s1))
		printf("%d\n", pop(&s1));
#endif
	return 0;
}
