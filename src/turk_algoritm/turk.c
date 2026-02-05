#include "../push_swap.h"

static void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	double_rotate(a, b, &cost_a, &cost_b);
	single_rotate(a, &cost_a, ra, rra);
	single_rotate(b, &cost_b, rb, rrb);
	pa(a, b);
}

static void	final_rotate(t_stack *a)
{
	int	min_pos;
	int	i;

	min_pos = find_pos(a);
	if (min_pos <= a->size / 2)
	{
		i = min_pos;
		while (i--);
		{
			ra(a);
		}
	}
	else 
	{
		i = a->size - min_pos;
		while (i--)
		{
			rra(a);
		}
	}
}

static void	find_cheapest_move(t_stack *a, t_stack *b,  t_node **best, int *best_a, int *best_b)
{
	t_node *tmp;
	int		cost_a;
	int		cost_b;
	int		min_cost;
	int		current;

	tmp = b->top;
	min_cost = INT_MAX;
	while (tmp)
	{
		calculate_cost(tmp, a, b, &cost_a, &cost_b);
		current = combined_cost(cost_a, cost_b);
		if (current < min_cost)
		{
			min_cost = current;
			*best = tmp;
			*best_a = cost_a;
			*best_b = cost_b;
		}
		tmp = tmp->next;
	}
}

void	turk_sort(t_stack *a,  t_stack *b)
{
	t_node	*best;
	int		cost_a;
	int		cost_b;

	if (is_ordered(a))
		return ;
	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	while (b->size)
	{
		find_cheapest_move(a, b, &best, &cost_a, &cost_b);
		execute_move(a, b, cost_a, cost_b);
	}
	final_rotate(a);
}