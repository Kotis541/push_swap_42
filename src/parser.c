/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:24:13 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/06 11:16:49 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	has_value(t_stack *stack, long num)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	push_number(t_stack *stack_a, char *s)
{
	long	num;

	if (!is_valid_number(s))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	num = ft_atol(s);
	if (num > INT_MAX || num < INT_MIN || has_value(stack_a, num))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	add_to_stack(stack_a, num);
}

static void	parse_arg(char *arg, t_stack *stack_a)
{
	char	**parts;
	int		i;

	parts = ft_split(arg, ' ');
	if (!parts)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (parts[i])
		i++;
	while (i-- > 0)
		push_number(stack_a, parts[i]);
	free_split(parts);
}

void	validate_and_parse(int argc, char *argv[], t_stack *stack_a)
{
	int	a;

	a = argc - 1;
	while (a >= 1)
		parse_arg(argv[a--], stack_a);
}
