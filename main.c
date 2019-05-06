#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list {
	int			i;
	struct		s_list *next;
} 				t_list;

int		odd(int a)
{
	return (a % 2 == 0) ? 0 : 1;
}

int		even(int a)
{
	return (a % 2 == 0) ? 1 : 0;
}

t_list *filter(t_list *list, int (*pred)())
{
	t_list *new_list = NULL;
	t_list *head = NULL;
	t_list *previous_node = NULL;

	if (list == NULL)
		return NULL;
	while (list)
	{
		if (pred(list->i))
		{
			if (previous_node)
			{
				new_list = (t_list*)malloc(sizeof(t_list));
				new_list->i = list->i;
				new_list->next = NULL;
				previous_node->next = new_list;
				previous_node = previous_node->next;
			}
			else
			{
				new_list = (t_list*)malloc(sizeof(t_list));
				new_list->i = list->i;
				previous_node = new_list;
				head = new_list;
				new_list->next = NULL;
			}
		}
		list = list->next;
	}
	return head;
}

void print_nodes(t_list *list)
{
	if (!list)
	{
		printf("[]\n");
		return;
	}
	printf("[");
	while(list)
	{
		printf("%d", list->i);
		if (list->next != NULL)
			printf(",");
		list = list->next; 
	}
	printf("]\n");
}


int main (void)
{
	t_list *new_list;
	t_list nol;
	t_list one;
	t_list two;
	t_list three;

	nol.i = 0;
	one.i = 1;
	two.i = 2;
	three.i = 3;
	nol.next = &one;
	one.next = &two;
	two.next = &three;
	three.next = NULL;

	print_nodes(&nol);
	new_list = filter(&nol, &odd);
	print_nodes(new_list);
	free(new_list);
	new_list = filter(&nol, &even);
	print_nodes(new_list);
	free(new_list);
	new_list = filter(three.next, &odd);
	print_nodes(new_list);
	return (0);
}
