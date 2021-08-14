#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int to_print)
{
	t_list	*el;

	el = ft_pop_stack(stack_b);
	if (!el)
		return ;
	ft_push_stack(stack_a, el);
	if (to_print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b, int to_print)
{
	t_list	*el;

	el = ft_pop_stack(stack_a);
	if (!el)
		return ;
	ft_push_stack(stack_b, el);
	if (to_print)
		ft_putstr_fd("pb\n", 1);
}
