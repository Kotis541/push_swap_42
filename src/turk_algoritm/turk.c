/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:36:56 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/05 13:36:56 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
		while (i--)
			ra(a);
	}
	else
	{
		i = a->size - min_pos;
		while (i--)
			rra(a);
	}
}

static t_move	find_cheapest_move(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_cost	cost;
	t_move	best_move;
	int		min_cost;
	int		current;

	tmp = b->top;
	min_cost = INT_MAX;
	while (tmp)
	{
		cost = calculate_cost(tmp, a, b);
		current = combined_cost(cost.cost_a, cost.cost_b);
		if (current < min_cost)
		{
			min_cost = current;
			best_move.cost_a = cost.cost_a;
			best_move.cost_b = cost.cost_b;
		}
		tmp = tmp->next;
	}
	return (best_move);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_move	move;

	if (is_ordered(a))
		return ;
	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	while (b->size)
	{
		move = find_cheapest_move(a, b);
		execute_move(a, b, move.cost_a, move.cost_b);
	}
	final_rotate(a);
}
