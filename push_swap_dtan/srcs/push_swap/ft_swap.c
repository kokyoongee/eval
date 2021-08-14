#include "push_swap.h"

void	sa(t_list **stack_a, int to_print)
{
	ft_swap_stack(stack_a);
	if (to_print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **stack_b, int to_print)
{
	ft_swap_stack(stack_b);
	if (to_print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b, int to_print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (to_print)
		ft_putstr_fd("ss\n", 1);
}
