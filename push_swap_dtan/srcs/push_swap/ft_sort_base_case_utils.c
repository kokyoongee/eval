#include "push_swap.h"

void	ft_run_instructions(t_list **stack_a, t_list **stack_b,
			char *instructions, int to_print)
{
	char	**arr;
	int		i;

	arr = ft_split(instructions, ' ');
	i = -1;
	while (arr[++i])
	{
		if (ft_strncmp(arr[i], "sa", 2) == 0)
			sa(stack_a, to_print);
		else if (ft_strncmp(arr[i], "sb", 2) == 0)
			sb(stack_b, to_print);
		else if (ft_strncmp(arr[i], "pa", 2) == 0)
			pa(stack_a, stack_b, to_print);
		else if (ft_strncmp(arr[i], "pb", 2) == 0)
			pb(stack_a, stack_b, to_print);
		else if (ft_strncmp(arr[i], "ra", 2) == 0)
			ra(stack_a, to_print);
		else if (ft_strncmp(arr[i], "rb", 2) == 0)
			rb(stack_b, to_print);
		else
			ft_satisfy_norme(stack_a, stack_b, to_print, arr[i]);
	}
}

void	ft_sort_base_case_a_helper(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second < third && third > first)
		ft_run_instructions(stack_a, stack_b, "sa", 1);
	else if (first > second && second > third && third < first)
		ft_run_instructions(stack_a, stack_b, "sa rra", 1);
	else if (first > second && second < third && third < first)
		ft_run_instructions(stack_a, stack_b, "ra", 1);
	else if (first < second && second > third && third > first)
		ft_run_instructions(stack_a, stack_b, "sa ra", 1);
	else if (first < second && second > third && third < first)
		ft_run_instructions(stack_a, stack_b, "rra", 1);
}

void	ft_sort_base_case_a_partition_helper(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second < third && third > first)
		ft_run_instructions(stack_a, stack_b, "sa", 1);
	else if (first > second && second > third && third < first)
		ft_run_instructions(stack_a, stack_b, "sa pb sa pa sa", 1);
	else if (first > second && second < third && third < first)
		ft_run_instructions(stack_a, stack_b, "sa pb sa pa", 1);
	else if (first < second && second > third && third > first)
		ft_run_instructions(stack_a, stack_b, "pb sa pa", 1);
	else if (first < second && second > third && third < first)
		ft_run_instructions(stack_a, stack_b, "pb sa pa sa", 1);
}

void	ft_sort_base_case_b_helper(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_b)->content;
	second = (*stack_b)->next->content;
	third = (*stack_b)->next->next->content;
	if (first > second && second < third && third > first)
		ft_run_instructions(stack_a, stack_b, "rrb", 1);
	else if (first < second && second < third && third > first)
		ft_run_instructions(stack_a, stack_b, "sb rrb", 1);
	else if (first > second && second < third && third < first)
		ft_run_instructions(stack_a, stack_b, "rb sb rrb", 1);
	else if (first < second && second > third && third > first)
		ft_run_instructions(stack_a, stack_b, "rb", 1);
	else if (first < second && second > third && third < first)
		ft_run_instructions(stack_a, stack_b, "sb", 1);
}

void	ft_sort_base_case_b_partition_helper(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_b)->content;
	second = (*stack_b)->next->content;
	third = (*stack_b)->next->next->content;
	if (first > second && second < third && third > first)
		ft_run_instructions(stack_a, stack_b, "pa sb pb sb", 1);
	else if (first < second && second < third && third > first)
		ft_run_instructions(stack_a, stack_b, "sb pa sb pb sb", 1);
	else if (first > second && second < third && third < first)
		ft_run_instructions(stack_a, stack_b, "pa sb pb", 1);
	else if (first < second && second > third && third > first)
		ft_run_instructions(stack_a, stack_b, "sb pa sb pb", 1);
	else if (first < second && second > third && third < first)
		ft_run_instructions(stack_a, stack_b, "sb", 1);
}
