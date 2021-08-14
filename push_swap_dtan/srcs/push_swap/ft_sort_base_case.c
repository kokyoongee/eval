#include "push_swap.h"
#include <stdio.h>
void	ft_push_partition(t_list **stack_a, t_list **stack_b,
			int partition_size)
{
	while (partition_size > 0)
	{
		pa(stack_a, stack_b, 1);
		partition_size--;
	}
}

void	ft_sort_base_case_a(t_list **stack_a, t_list **stack_b,
			int partition_size)
{
	if (partition_size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, 1);
	}
	else if (partition_size == 3)
	{
		if (partition_size != ft_lstsize(*stack_a))
			ft_sort_base_case_a_partition_helper(stack_a, stack_b);
		else
			ft_sort_base_case_a_helper(stack_a, stack_b);
	}
}

void	ft_sort_base_case_b(t_list **stack_a, t_list **stack_b,
			int partition_size)
{
	if (partition_size == 1)
		pa(stack_a, stack_b, 1);
	else if (partition_size == 2)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b, 1);
		pa(stack_a, stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
	else if (partition_size == 3)
	{
		if (partition_size != ft_lstsize(*stack_b))
			ft_sort_base_case_b_partition_helper(stack_a, stack_b);
		else
			ft_sort_base_case_b_helper(stack_a, stack_b);
		ft_push_partition(stack_a, stack_b, partition_size);
	}
}
