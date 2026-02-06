/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:53:50 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/06 14:29:49 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_ordered(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = stack_a->top;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	validate_and_parse(argc, argv, &a);
	if (is_ordered(&a))
		return (free_stack(&a), 0);
	if (a.size == 2)
		sort_two(&a);
	else if (a.size == 3)
		sort_three(&a);
	else if (a.size == 4)
		sort_four(&a, &b);
	else if (a.size == 5)
		sort_five(&a, &b);
	else
		turk_sort(&a, &b);
	free_stack(&a);
	if (b.size > 0)
		free_stack(&b);
}
