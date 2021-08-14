#include "checker.h"

void	ft_check_sorted(t_list **stack_a)
{
	t_list	*ptr;

	ptr = *stack_a;
	while (ptr->next)
	{
		if (ptr->content > ptr->next->content)
		{
			ft_putstr_fd("KO\n", 1);
			exit(0);
		}
		ptr = ptr->next;
	}
	ft_putstr_fd("OK\n", 1);
}
