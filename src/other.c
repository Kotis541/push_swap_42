#include "../push_swap.h"
#include <limits.h>

void	validate_and_parse(int argc, char *argv[], t_stack *stack_a)
{
	int a;
	long num;
	
	a = argc - 1;
	check_duplicates(argc, argv);
	while (a >= 1)
	{
		if (!is_valid_number(argv[a]))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		num = ft_atol(argv[a]); 
		if (num > INT_MAX || num < INT_MIN)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		add_to_stack(stack_a, num);
		a--;
	}
}


void	add_to_stack(t_stack *stack,long num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	// if (!new_node)
	// 	error_exit(); // pridat free
	new_node->value = num;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size += 1;
}

int	is_valid_number(char *str)
{
	int i;

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
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
            return (0);
    	}
		i++;
	}
	return (1);
}

long ft_atol(const char *nptr)
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

void check_duplicates(int argc, char *argv[])
{
	int a;
	int b;

	a = 1;
	b = 0;
	while (a < argc)
	{
		b = a + 1;
		while (b < argc)
		{
			if (ft_atol(argv[a]) == ft_atol(argv[b]))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			b++;
		}
		a++;
	}
}

int is_ordered(t_stack *stack_a)
{
	t_node *tmp;

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

int main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack	stack_b;
	// t_node	*c;
	// t_node	*b;
	// t_node	*d;

	// c = malloc(sizeof(t_node));
	// b = malloc(sizeof(t_node));
	// d = malloc(sizeof(t_node));

	// c->value = 2;
	// c->next = b;
	// b->value = 1;
	// b->next = NULL;

	stack_a.top = NULL;
	stack_a.size = 0;

	stack_b.top = NULL;
	stack_b.size = 0;
	validate_and_parse(argc, argv, &stack_a);
	if (!is_ordered(&stack_a) && stack_a.size == 2)
		sort_two(&stack_a);
	else if (!is_ordered(&stack_a) && stack_a.size == 3)
		sort_three(&stack_a);
	else if (!is_ordered(&stack_a) && stack_a.size == 4)
		sort_four(&stack_a, &stack_b);
	else if(!is_ordered(&stack_a) && stack_a.size == 5)
		sort_five(&stack_a, &stack_b);

	printf("%d\n", stack_a.top->value);
	printf("%d\n", stack_a.top->next->value);
	printf("%d\n", stack_a.top->next->next->value);
	printf("%d\n", stack_a.top->next->next->next->value);
	printf("%d\n", stack_a.top->next->next->next->next->value);
	return 0;
}

