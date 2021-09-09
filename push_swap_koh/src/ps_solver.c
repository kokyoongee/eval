/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:44:42 by skoh              #+#    #+#             */
/*   Updated: 2021/09/08 16:41:27 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_partition	ps_range(int min, int max)
{
	t_partition	p;

	p = (t_partition){.min = min, .max = max, .size = max - min + 1};
	p.sendr = (p.rotate = (p.push = (p.pushr = 0)));
	if (p.size == 3)
	{
		p.send = 0;
		return (p);
	}
	if (p.size == 4)
	{
		p.send = 2;
		return (p);
	}
	if (p.size <= 8)
	{
		p.send = p.size /2;
		return (p);
	}
	p.send = p.size * 2 / 3;
	if (p.send <= 3)
		p.sendr = 0;
	else
		p.sendr = p.send / 2;
	return (p);
}

static void	ps_solve_stack_b(t_app *app, t_partition p);
static void	ps_solve_stack_br(t_app *app, t_partition p);

// from ra: a keeps big, b keeps med, rb keeps small
static void	ps_solve_stack_ar(t_app *app, t_partition p)
{
	while (p.size--)
	{
		p.rotate += ps_exec(app, RRA);
		if (p.send && vtoi(app->a->content) < p.min + p.send)
		{
			p.push += ps_exec(app, PB);
			if (p.sendr && vtoi(app->b->content) < p.min + p.sendr)
				p.pushr += ps_exec(app, RB);
		}
	}
	ps_solve_stack_a(app, ps_range(p.min + p.send, p.max));
	if (p.send)
		ps_solve_stack_b(app, ps_range(p.min + p.sendr, p.min + p.send - 1));
	if (p.sendr)
		ps_solve_stack_br(app, ps_range(p.min, p.min + p.sendr - 1));
}

// handle small nums, sort desc, ends by sending sorted nums over
// from b: a keeps big, ra keeps med, b keeps small
static void	ps_solve_stack_b(t_app *app, t_partition p)
{
	if (ps_sort_push(app, p.size))
		return ;
	while (p.push < p.send)
	{
		if (vtoi(app->b->content) > p.max - p.send)
		{
			p.push += ps_exec(app, PA);
			if (p.sendr && vtoi(app->a->content) <= p.max - p.send + p.sendr)
				p.pushr += ps_exec(app, RA);
			if (p.send - p.sendr <= 5 && ps_check_sort(app->a, 2) == DESC)
				if (ps_exec(app, SA))
					if (ps_check_sort(app->b, 2) == ASC)
						ps_exec(app, SB);
		}
		else
			p.rotate += ps_exec(app, RB);
	}
	if (p.rotate < ft_lstsize(app->b))
		while (p.rotate--)
			ps_exec(app, RRB);
	ps_solve_stack_a(app, ps_range(p.max - p.send + p.sendr + 1, p.max));
	if (p.sendr)
		ps_solve_stack_ar(app,
			ps_range(p.max - p.send + 1, p.max - p.send + p.sendr));
	ps_solve_stack_b(app, ps_range(p.min, p.max - p.send));
}

// b:min-(max-send),a2:0/(max-send+1)-(max-send+1),a:(max-send+1)-max
// from rb: a keeps big, ra keeps med, b keeps small
static void	ps_solve_stack_br(t_app *app, t_partition p)
{
	if (p.size == ft_lstsize(app->b))
		return (ps_solve_stack_b(app, ps_range(p.min, p.max)));
	while (p.size--)
	{
		p.rotate += ps_exec(app, RRB);
		if (p.send && vtoi(app->b->content) > p.max - p.send)
		{
			p.push += ps_exec(app, PA);
			if (p.sendr && vtoi(app->a->content) <= p.max - p.send + p.sendr)
				p.pushr += ps_exec(app, RA);
		}
		else if (!p.send && vtoi(app->b->content) == p.max - p.push)
		{
			p.push += ps_exec(app, PA);
		}
	}
	if (!p.send && p.push)
		p.send = p.push;
	if (p.send)
		ps_solve_stack_a(app,
			ps_range(p.max - p.send + p.sendr + 1, p.max));
	if (p.sendr)
		ps_solve_stack_ar(app,
			ps_range(p.max - p.send + 1, p.max - p.send + p.sendr));
	ps_solve_stack_b(app, ps_range(p.min, p.max - p.send));
}

// handle big nums, sort asc, ends by doing nothing => keep sorted nums
// from a: a keeps big, b keeps med, rb keeps small
void	ps_solve_stack_a(t_app *app, t_partition p)
{
	if (ps_sort_stack_a(app, p.size))
		return ;
	while (p.push < p.send)
	{
		if (vtoi(app->a->content) < p.min + p.send)
		{
			p.push += ps_exec(app, PB);
			if (p.sendr && vtoi(app->b->content) < p.min + p.sendr)
				p.pushr += ps_exec(app, RB);
			if (p.send - p.sendr >= 3 && p.send - p.sendr <= 5
				&& app->b->next && ps_check_sort(app->b, 2) == ASC)
				if (ps_exec(app, SB))
					if (ps_check_sort(app->a, 2) == DESC)
						ps_exec(app, SA);
		}
		else
			p.rotate += ps_exec(app, RA);
	}
	if (p.min != 1 && p.rotate < ft_lstsize(app->a))
		while (p.rotate--)
			ps_exec(app, RRA);
	ps_solve_stack_a(app, ps_range(p.min + p.send, p.max));
	ps_solve_stack_b(app, ps_range(p.min + p.sendr, p.min + p.send - 1));
	if (p.sendr)
		ps_solve_stack_br(app, ps_range(p.min, p.min + p.sendr - 1));
}
