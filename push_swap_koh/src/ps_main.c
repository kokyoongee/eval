/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 04:39:29 by skoh              #+#    #+#             */
/*   Updated: 2021/09/08 22:11:19 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	ps_cleanup(t_app *app)
{
	ft_lstclear(&app->a, NULL);
	ft_lstclear(&app->b, NULL);
	ft_lstclear(&app->steps, NULL);
}

static void	ps_print_steps(t_app *app)
{
	int			cmd;
	int			combo;
	const int	combo_ss = (1 << SA) + (1 << SB);
	const int	combo_rr = (1 << RA) + (1 << RB);
	const int	combo_rrr = (1 << RRA) + (1 << RRB);

	while (app->steps)
	{
		cmd = vtoi(ft_list_pop(&app->steps));
		if (app->steps)
		{
			combo = (1 << cmd) + (1 << vtoi(app->steps->content));
			if (combo == combo_rrr)
				cmd = (ft_list_pop(&app->steps), RRR);
			else if (combo == combo_rr)
				cmd = (ft_list_pop(&app->steps), RR);
			else if (combo == combo_ss)
				cmd = (ft_list_pop(&app->steps), SS);
		}
		ft_putendl_fd(ps_get_command(cmd), 1);
	}
}

static int	ps_solve(t_list *stack)
{
	t_app	app;

	if (!stack)
		return (EXIT_FAILURE);
	app = (t_app){.a = stack, .b = NULL, .steps = NULL};
	ps_normalize(app.a);
	ps_solve_stack_a(&app, ps_range(1, ft_lstsize(app.a)));
	ps_print_steps(&app);
	ps_cleanup(&app);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int	status;

	status = EXIT_SUCCESS;
	if (argc > 1)
		status = ps_solve(ps_parse(argc - 1, argv + 1));
	if (0)
		system(">&2 leaks push_swap");
	return (status);
}
