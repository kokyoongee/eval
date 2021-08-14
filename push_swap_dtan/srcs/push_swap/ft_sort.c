#include "push_swap.h"

int	ft_sort_a(t_list **stack_a, t_list **stack_b, int partition_size)
{
	int	median;
	int	count;
	int	offset;

	if (partition_size <= 3)
	{
		ft_sort_base_case_a(stack_a, stack_b, partition_size);
		return (1);
	}
	count = partition_size;
	offset = 0;
	median = ft_get_median(*stack_a, partition_size);
	while (count != partition_size / 2 + partition_size % 2)
	{
		if ((*stack_a)->content < median && count--)
			pb(stack_a, stack_b, 1);
		else if (++offset)
			ra(stack_a, 1);
	}
	while (partition_size / 2 + partition_size % 2 != ft_lstsize(*stack_a)
		&& offset-- > 0)
		rra(stack_a, 1);
	if (ft_sort_a(stack_a, stack_b, partition_size / 2 + partition_size % 2))
		return (ft_sort_b(stack_a, stack_b, partition_size / 2));
	return (0);
}

int	ft_sort_b(t_list **stack_a, t_list **stack_b, int partition_size)
{
	int	median;
	int	count;
	int	offset;

	if (partition_size <= 3)
	{
		ft_sort_base_case_b(stack_a, stack_b, partition_size);
		return (1);
	}
	count = partition_size;
	offset = 0;
	median = ft_get_median(*stack_b, partition_size);
	while (count != partition_size / 2)
	{
		if ((*stack_b)->content >= median && count--)
			pa(stack_a, stack_b, 1);
		else if (++offset)
			rb(stack_b, 1);
	}
	while (partition_size / 2 != ft_lstsize(*stack_b) && offset-- > 0)
		rrb(stack_b, 1);
	if (ft_sort_a(stack_a, stack_b, partition_size / 2 + partition_size % 2))
		return (ft_sort_b(stack_a, stack_b, partition_size / 2));
	return (0);
}
