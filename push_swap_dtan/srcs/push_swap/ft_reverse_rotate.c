#include "push_swap.h"

void	rra(t_list **stack_a, int to_print)
{
	ft_reverse_rotate_stack(stack_a);
	if (to_print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **stack_b, int to_print)
{
	ft_reverse_rotate_stack(stack_b);
	if (to_print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b, int to_print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (to_print)
		ft_putstr_fd("rrr\n", 1);
}
