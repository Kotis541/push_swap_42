#include "../push_swap.h"

void	sa(t_stack *a)
{
    int	tmp;

    tmp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = tmp;
    write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
    int	tmp;

    tmp = b->top->value;
    b->top->value = b->top->next->value;
    b->top->next->value = tmp;
    write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
    t_node	*tmp;

	if (b->size == 0)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	if (a->size == 0)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
	a->size--;
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*first;

	first = a->top;
	tmp = a->top;
	if (a->size < 2)
		return ;
	a->top = a->top->next;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*first;

	first = b->top;
	tmp = b->top;

	if (b->size < 2)
		return;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack	*a)
{
	t_node	*last;
	t_node	*tmp;
	
	if (a->size < 2)
		return ;
	tmp = a->top;
	while(tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = a->top;
	a->top = last;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*tmp;

	if (b->size < 2)
		return ;
	tmp = b->top;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = b->top;
	b->top = last;
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
