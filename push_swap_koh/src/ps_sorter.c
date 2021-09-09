/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 00:03:58 by skoh              #+#    #+#             */
/*   Updated: 2021/09/08 16:59:04 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_stack_a(t_app *app, int size)
{
	if (ps_check_sort(app->a, size) == ASC)
		return (1);
	if (size == 2)
		return (ps_exec(app, SA));
	if (size == 3)
	{
		if (!app->a->next->next->next)
		{
			if (ps_check_sort(app->a, 2) == ASC
				&& ps_check_sort(app->a->next, 2) == DESC)
				ps_exec(app, RRA);
			while (vtoi(app->a->content) > vtoi(app->a->next->next->content))
				ps_exec(app, RA);
		}
		if (ps_check_sort(app->a, 2) != ASC)
			ps_exec(app, SA);
		if (ps_check_sort(app->a->next, 2) != ASC)
			(void)(ps_exec(app, RA) && ps_exec(app, SA) && ps_exec(app, RRA));
		if (ps_check_sort(app->a, 2) != ASC)
			ps_exec(app, SA);
		return (1);
	}
	return (0);
}

int	ps_sort_push(t_app *app, int size)
{
	if (size > 3)
		return (0);
	while (size)
	{
		if (size-- > 1 && ps_check_sort(app->b, 2) != DESC)
			ps_exec(app, SB);
		ps_exec(app, PA);
		if (ps_check_sort(app->a, 2) != ASC)
			ps_exec(app, SA);
	}
	return (1);
}
