#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		ft_is_valid_instruction(char *instruction);

void	ft_parse_instructions(t_list **stack_a, t_list **stack_b);

void	ft_check_sorted(t_list **stack_a);

#endif
