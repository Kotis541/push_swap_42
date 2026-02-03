#include "../push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	if (tmp->value > tmp->next->value && tmp->value < tmp->next->next->value)
		sa(a);
	else if(tmp->value < tmp->next->value && tmp->value > tmp->next->next->value)
		rra(a);
	else if(tmp->value > tmp->next->value && tmp->next->value > tmp->next->next->value)
	{
		sa(a);
		rra(a);
	}
	else if(tmp->value > tmp->next->value && tmp->next->value < tmp->next->next->value)
		ra(a);
	else if(tmp->value < tmp->next->value && tmp->next->value > tmp->next->next->value)
	{
		sa(a);
		ra(a);
	}
}

int find_pos(t_stack *a)
{
    t_node *tmp;
    int pos;
    int min;
    int min_pos;

    tmp = a->top;
    pos = 0;
    min = tmp->value;
    min_pos = 0;
    
    while (tmp)
    {
        if (tmp->value < min)
        {
            min = tmp->value;
            min_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return (min_pos);
}


void sort_four(t_stack *a, t_stack *b)
{
    int min_pos;
    int i;
    
    min_pos = find_pos(a);
    i = 0;
    
    if (min_pos <= 2)  
    {
        while (i < min_pos)
        {
            ra(a);
            i++;
        }
    }
    else
    {
        while (i < (a->size - min_pos))
        {
            rra(a);
            i++;
        }
    }
    
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void    sort_five(t_stack *a, t_stack *b)
{
    int     min_pos;
    int     i;

    min_pos = find_pos(a);
    i = 0;
    if (min_pos <= 2)
    {
        while (i < min_pos)
        {
            ra(a);
            i++;
        }
    }
    else
    {
        while (i < (a->size - min_pos))
        {
            rra(a);
            i++;
        }
    }
    pb(a, b);
    sort_four(a, b);
    pa(a, b);
}