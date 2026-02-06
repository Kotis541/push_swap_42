/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:48:31 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/05 13:48:31 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sb(t_stack *b)
{
	int	tmp;

	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	write(1, "sb\n", 3);
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

void	rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*first;

	first = b->top;
	tmp = b->top;
	if (b->size < 2)
		return ;
	b->top = b->top->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
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
