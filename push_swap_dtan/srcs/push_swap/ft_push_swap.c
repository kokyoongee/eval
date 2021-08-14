#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		init_stacks(&stack_a, &stack_b);
		ft_populate_stack(&stack_a, argc, argv);
		ft_sort_a(&stack_a, &stack_b, ft_lstsize(stack_a));
	}
}
