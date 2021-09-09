/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:43:09 by skoh              #+#    #+#             */
/*   Updated: 2021/09/08 21:56:10 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return does not matter, primarily for chaining calls
static int	ps_exec_internal(t_app *app, enum e_push_swap cmd)
{
	if (cmd == PA && app->b)
		return (ft_list_push(&app->a, ft_list_pop(&app->b)));
	if (cmd == PB && app->a)
		return (ft_list_push(&app->b, ft_list_pop(&app->a)));
	if (cmd == RA && app->a)
		return (ft_list_enqueue(&app->a, ft_list_pop(&app->a)));
	if (cmd == RB && app->b)
		return (ft_list_enqueue(&app->b, ft_list_pop(&app->b)));
	if (cmd == RRA && app->a)
		return (ft_list_push(&app->a, ft_list_pop_last(&app->a)));
	if (cmd == RRB && app->b)
		return (ft_list_push(&app->b, ft_list_pop_last(&app->b)));
	if (cmd == SS)
		return (ps_exec_internal(app, SA) + ps_exec_internal(app, SB));
	if (cmd == RR)
		return (ps_exec_internal(app, RA) + ps_exec_internal(app, RB));
	if (cmd == RRR)
		return (ps_exec_internal(app, RRA) + ps_exec_internal(app, RRB));
	if (cmd == SA && app->a)
		return (ps_exec_internal(app, PB) + ps_exec_internal(app, RA)
			+ ps_exec_internal(app, PA) + ps_exec_internal(app, RRA));
	if (cmd == SB && app->b)
		return (ps_exec_internal(app, PA) + ps_exec_internal(app, RB)
			+ ps_exec_internal(app, PB) + ps_exec_internal(app, RRB));
	return (1);
}

int	ps_exec(t_app *app, enum e_push_swap cmd)
{
	ps_exec_internal(app, cmd);
	ft_list_enqueue(&app->steps, itov(cmd));
	return (1);
}

// duplicate number not supported and return unsorted
// failsafe if ps_check_sort(size = 2) but empty list
enum e_sort	ps_check_sort(t_list *list, int size)
{
	int	dir;

	if (size <= 1 || !list || !list->next)
		return (ASC);
	dir = vtoi(list->content) < vtoi(list->next->content);
	size -= 2;
	while (list->next && size--)
	{
		list = list->next;
		if ((vtoi(list->content) < vtoi(list->next->content)) != dir)
			return (UNSORTED);
	}
	if (dir)
		return (ASC);
	return (DESC);
}
