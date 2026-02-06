/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:49:03 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/05 13:49:03 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	write(1, "sa\n", 3);
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

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*first;

	first = a->top;
	tmp = a->top;
	if (a->size < 2)
		return ;
	a->top = a->top->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack	*a)
{
	t_node	*last;
	t_node	*tmp;

	if (a->size < 2)
		return ;
	tmp = a->top;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = a->top;
	a->top = last;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}
