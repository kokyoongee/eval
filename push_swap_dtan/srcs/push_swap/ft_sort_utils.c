#include "push_swap.h"

void	ft_satisfy_norme(t_list **stack_a, t_list **stack_b, int to_print,
			char *instruction)
{
	if (ft_strncmp(instruction, "rra", 3) == 0)
		rra(stack_a, to_print);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		rrb(stack_b, to_print);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		rrr(stack_a, stack_b, to_print);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
		rr(stack_a, stack_b, to_print);
	return ;
}

int	ft_placeholder(int content)
{
	return (content);
}

t_list	*ft_get_partition(t_list *stack, int partition_size)
{
	t_list	*partition;
	t_list	*ptr;

	if (partition_size < 1)
		return (NULL);
	partition = ft_lstmap(stack, ft_placeholder);
	ptr = partition;
	while (ptr->next && partition_size > 1)
	{
		ptr = ptr->next;
		partition_size--;
	}
	ft_lstclear(&(ptr->next));
	ptr->next = NULL;
	return (partition);
}

void	ft_sort_partition(t_list **partition)
{
	t_list	*cur;
	int		cur_content;
	int		unsorted;

	if (!partition || !(*partition))
		return ;
	unsorted = 1;
	while (unsorted)
	{
		unsorted = 0;
		cur = *partition;
		while (cur->next)
		{
			if (cur->content > cur->next->content)
			{
				unsorted = 1;
				cur_content = cur->content;
				cur->content = cur->next->content;
				cur->next->content = cur_content;
			}
			cur = cur->next;
		}
	}
}

int	ft_get_median(t_list *stack, int partition_size)
{
	t_list	*partition;
	int		index;

	partition = ft_get_partition(stack, partition_size);
	ft_sort_partition(&partition);
	index = partition_size / 2;
	while (partition && index > 0)
	{
		partition = partition->next;
		index--;
	}
	return (partition->content);
}
