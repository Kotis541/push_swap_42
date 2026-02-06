/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:24:13 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/06 12:26:56 by vokotera         ###   ########.fr       */
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

static int	push_number(t_stack *stack_a, char *s)
{
	long	num;

	if (!is_valid_number(s))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	num = ft_atol(s);
	if (num > INT_MAX || num < INT_MIN || has_value(stack_a, num))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	add_to_stack(stack_a, num);
	return (0);
}

static int	parse_arg(char *arg, t_stack *stack_a)
{
	char	**parts;
	int		i;

	parts = ft_split(arg, ' ');
	if (!parts)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (parts[i])
		i++;
	while (i-- > 0)
	{
		if (push_number(stack_a, parts[i]))
		{
			free_split(parts);
			return (1);
		}
	}
	free_split(parts);
	return (0);
}

int	validate_and_parse(int argc, char *argv[], t_stack *stack_a)
{
	int	a;

	a = argc - 1;
	while (a >= 1)
	{
		if (parse_arg(argv[a--], stack_a))
			return (1);
	}
	return (0);
}
