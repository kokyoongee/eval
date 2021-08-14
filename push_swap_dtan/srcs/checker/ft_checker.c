#include "checker.h"
#include "push_swap.h"
#include "get_next_line.h"
#include <stdio.h>

int	ft_is_valid_instruction(char *instruction)
{
	int	len;

	len = ft_strlen(instruction);
	if (ft_strncmp(instruction, "sa\n", len) == 0)
		return (1);
	else if (ft_strncmp(instruction, "sb\n", len) == 0)
		return (1);
	else if (ft_strncmp(instruction, "pa\n", len) == 0)
		return (1);
	else if (ft_strncmp(instruction, "pb\n", len) == 0)
		return (1);
	else if (ft_strncmp(instruction, "ra\n", len) == 0)
		return (1);
	else if (ft_strncmp(instruction, "rb\n", len) == 0)
		return (1);
	else if (ft_strncmp(instruction, "rra\n", len) == 0)
		return (1);
	else if (ft_strncmp(instruction, "rrb\n", len) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instruction;

	if (argc > 1)
	{
		init_stacks(&stack_a, &stack_b);
		ft_populate_stack(&stack_a, argc, argv);
		instruction = get_next_line(0);
		while (instruction != NULL)
		{
			if (ft_strncmp(instruction, "\n", ft_strlen(instruction)) == 0)
				break ;
			else if (ft_is_valid_instruction(instruction))
				ft_run_instructions(&stack_a, &stack_b, instruction, 0);
			else
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			instruction = get_next_line(0);
		}
		ft_check_sorted(&stack_a);
	}
}
