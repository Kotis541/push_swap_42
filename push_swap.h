/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:20:10 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/06 12:28:56 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "Libft/Libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
}	t_cost;

typedef struct s_move
{
	int	cost_a;
	int	cost_b;
}	t_move;

int		validate_and_parse(int argc, char *argv[], t_stack *stack_a);
void	add_to_stack(t_stack *stack, long num);
int		is_valid_number(char *str);
long	ft_atol(const char *nptr);
void	check_duplicates(int argc, char *argv[]);
int		is_ordered(t_stack *stack_a);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
int		find_pos(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	turk_sort(t_stack *a, t_stack *b);
void	single_rotate(t_stack *stack, int *cost,
			void (*rot)(t_stack *), void (*rev)(t_stack *));
void	double_rotate(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
int		combined_cost(int cost_a, int cost_b);
t_cost	calculate_cost(t_node *node, t_stack *a, t_stack *b);
int		find_target_position(int value, t_stack *a);

#endif