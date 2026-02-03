#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

// Parsing & validation
void	validate_and_parse(int argc, char *argv[], t_stack *stack_a);
void	add_to_stack(t_stack *stack, long num);
int		is_valid_number(char *str);
long	ft_atol(const char *nptr);
void	check_duplicates(int argc, char *argv[]);
int		is_ordered(t_stack *stack_a);

// Sorting functions
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void    sort_five(t_stack *a, t_stack *b);
int		find_pos(t_stack *a);

// Stack operations
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

#endif