/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:37:39 by vokotera          #+#    #+#             */
/*   Updated: 2026/02/06 11:11:28 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

void	add_to_stack(t_stack *stack, long num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new_node->value = num;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size += 1;
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i])
	{
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	size_t		i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	check_duplicates(int argc, char *argv[])
{
	int	a;
	int	b;

	a = 1;
	b = 0;
	while (a < argc)
	{
		b = a + 1;
		while (b < argc)
		{
			if (ft_atol(argv[a]) == ft_atol(argv[b]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			b++;
		}
		a++;
	}
}
