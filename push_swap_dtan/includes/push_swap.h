#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

// STACK

void	init_stacks(t_list **stack_a, t_list **stack_b);

void	ft_populate_stack(t_list **stack_a, int argc, char **argv);

// PARSER

char	**ft_copy_args(int argc, char **argv);

int		ft_is_valid_arg(t_list *stack, char *arg);

// INSTRUCTION UTILS

void	ft_free_arr(char **arr);

void	ft_push_stack(t_list **stack, t_list *el);

t_list	*ft_pop_stack(t_list **stack);

void	ft_rotate_stack(t_list **stack);

void	ft_reverse_rotate_stack(t_list **stack);

void	ft_swap_stack(t_list **stack);

// INSTRUCTIONS

void	sa(t_list **stack_a, int to_print);

void	sb(t_list **stack_b, int to_print);

void	ss(t_list **stack_a, t_list **stack_b, int to_print);

void	pa(t_list **stack_a, t_list **stack_b, int to_print);

void	pb(t_list **stack_a, t_list **stack_b, int to_print);

void	ra(t_list **stack_a, int to_print);

void	rb(t_list **stack_b, int to_print);

void	rr(t_list **stack_a, t_list **stack_b, int to_print);

void	rra(t_list **stack_a, int to_print);

void	rrb(t_list **stack_b, int to_print);

void	rrr(t_list **stack_a, t_list **stack_b, int to_print);

// SORT UTILS

int		ft_get_median(t_list *stack, int partition_size);

// SORT

int		ft_sort_a(t_list **stack_a, t_list **stack_b, int partition_size);

int		ft_sort_b(t_list **stack_a, t_list **stack_b, int partition_size);

// BASE CASE

void	ft_sort_base_case_a(t_list **stack_a, t_list **stack_b,
			int partition_size);

void	ft_sort_base_case_b(t_list **stack_a, t_list **stack_b,
			int partition_size);

// BASE CASE UTILS

void	ft_sort_base_case_a_helper(t_list **stack_a, t_list **stack_b);

void	ft_sort_base_case_a_partition_helper(t_list **stack_a,
			t_list **stack_b);

void	ft_sort_base_case_b_helper(t_list **stack_a, t_list **stack_b);

void	ft_sort_base_case_b_partition_helper(t_list **stack_a,
			t_list **stack_b);

void	ft_push_partition(t_list **stack_a, t_list **stack_b,
			int partition_size);

void	ft_run_instructions(t_list **stack_a, t_list **stack_b,
			char *instructions, int to_print);

// NORME >:(

void	ft_satisfy_norme(t_list **stack_a, t_list **stack_b, int to_print,
			char *instruction);

#endif
