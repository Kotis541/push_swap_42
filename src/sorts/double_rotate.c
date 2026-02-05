#include "../push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

    tmp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = tmp;
	tmp = b->top->value;
    b->top->value = b->top->next->value;
    b->top->next->value = tmp;
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*first;

	first = b->top;
	tmp = b->top;
	if (b->size < 2)
		return;
	b->top = b->top->next; 
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	first = a->top;
	tmp = a->top;
	if (a->size < 2)
		return ;
	a->top = a->top->next;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*last;
	t_node	*tmp;
	
	if (a->size >= 2)
	{
		tmp = a->top;
		while(tmp->next->next)
		tmp = tmp->next;
		a->top = last;
		tmp->next = NULL;
	}
	if (b->size >= 2)
	{
		tmp = b->top;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		last->next = b->top;
		b->top = last;
		tmp->next = NULL;
	}
}