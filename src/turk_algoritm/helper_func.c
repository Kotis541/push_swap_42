/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:34:05 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/05 13:34:05 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	single_rotate(t_stack *stack, int *cost,
	void (*rot)(t_stack *), void (*rev)(t_stack *))
{
	while (*cost > 0)
	{
		rot(stack);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rev(stack);
		(*cost)++;
	}
}

void	double_rotate(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

int	combined_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;
	int	max_val;

	abs_a = cost_a;
	if (cost_a < 0)
		abs_a = -cost_a;
	abs_b = cost_b;
	if (cost_b < 0)
		abs_b = -cost_b;
	if (abs_a > abs_b)
		max_val = abs_a;
	else
		max_val = abs_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
		return (max_val);
	else
		return (abs_a + abs_b);
}

t_cost	calculate_cost(t_node *node, t_stack *a, t_stack *b)
{
	t_cost	cost;
	t_node	*tmp;
	int		pos_in_b;
	int		target_pos;

	tmp = b->top;
	pos_in_b = 0;
	while (tmp && tmp != node)
	{
		tmp = tmp->next;
		pos_in_b++;
	}
	if (pos_in_b <= b->size / 2)
		cost.cost_b = pos_in_b;
	else
		cost.cost_b = pos_in_b - b->size;
	target_pos = find_target_position(node->value, a);
	if (target_pos <= a->size / 2)
		cost.cost_a = target_pos;
	else
		cost.cost_a = target_pos - a->size;
	return (cost);
}

int	find_target_position(int value, t_stack *a)
{
	t_node	*tmp;
	int		pos;
	int		target;
	int		min_pos;
	int		closest_bigger;

	tmp = a->top;
	pos = 0;
	min_pos = find_pos(a);
	target = min_pos;
	closest_bigger = INT_MAX;
	while (tmp)
	{
		if (tmp->value > value && tmp->value < closest_bigger)
		{
			closest_bigger = tmp->value;
			target = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (target);
}
