#include <cstdio>
#include <cstdlib>

typedef struct	s_list {
	int			i;
	struct		s_list *next;
} 				t_list;


t_list *od__number(t_list *list, UnaryPredicate )
{
	t_list *new_list = NULL;
	t_list *head = NULL;
	t_list *current = NULL;

	if (list == NULL)
		return NULL;
	head = new_list;
	while (list)
	{
		if ((list->i % 2) == 0)
		{
			if (current)
			{
				new_list = (t_list*)malloc(sizeof(t_list));
				new_list->next = NULL;
				new_list->i = list->i;
				current->next = new_list;
				current = current->next;
			}
			else
			{
				new_list = (t_list*)malloc(sizeof(t_list));
				new_list->i = list->i;
				current = new_list;
				head = new_list;
				new_list->next = NULL;
			}
		}
		list = list->next;
	}
	return head;
}

void ft_print_nodes(t_list *list)
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

	ft_print_nodes(&nol);
	new_list = od__number(&nol);
	ft_print_nodes(new_list);
	return (0);
}
