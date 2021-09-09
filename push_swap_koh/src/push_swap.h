/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:44:49 by skoh              #+#    #+#             */
/*   Updated: 2021/09/08 22:12:57 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

enum	e_push_swap
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	INVALID_CMD,
};

enum	e_sort
{
	DESC = -1,
	UNSORTED,
	ASC,
};

typedef struct s_bt_item
{
	int		value;
	t_list	*list;
}			t_bt_item;

typedef struct s_app
{
	t_list	*a;
	t_list	*b;
	t_list	*steps;
}			t_app;

typedef struct s_partition
{
	int	min;
	int	max;
	int	size;
	int	send;
	int	sendr;
	int	rotate;
	int	push;
	int	pushr;
}		t_partition;

int				vtoi(void *v);
void			*itov(int i);
const char		*ps_get_command(enum e_push_swap i);
int				ps_exec(t_app *app, enum e_push_swap act);
t_list			*ps_parse(int count, char **argv);
enum e_sort		ps_check_sort(t_list *list, int size);

void			ps_normalize(t_list *list);
t_partition		ps_range(int min, int max);
void			ps_solve_stack_a(t_app *app, t_partition p);
int				ps_sort_stack_a(t_app *app, int size);
int				ps_sort_push(t_app *app, int size);

#endif