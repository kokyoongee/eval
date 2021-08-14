#include "push_swap.h"

void	init_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_populate_stack(t_list **stack_a, int argc, char **argv)
{
	char	**arr;
	t_list	*el;
	int		num;
	int		i;

	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = ft_copy_args(argc, argv);
	i = 0;
	while (arr[i])
	{
		if (!ft_is_valid_arg(*stack_a, arr[i]))
		{
			ft_putstr_fd("Error\n", 2);
			ft_lstclear(stack_a);
			ft_free_arr(arr);
			exit(0);
		}
		num = ft_atoi(arr[i]);
		el = ft_lstnew(num);
		ft_lstadd_back(stack_a, el);
		i++;
	}
	ft_free_arr(arr);
}
