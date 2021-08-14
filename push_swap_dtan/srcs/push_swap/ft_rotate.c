#include "push_swap.h"

void	ra(t_list **stack_a, int to_print)
{
	ft_rotate_stack(stack_a);
	if (to_print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **stack_b, int to_print)
{
	ft_rotate_stack(stack_b);
	if (to_print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b, int to_print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (to_print)
		ft_putstr_fd("rr\n", 1);
}
