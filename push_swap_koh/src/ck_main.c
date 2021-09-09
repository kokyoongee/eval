/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:42:14 by skoh              #+#    #+#             */
/*   Updated: 2021/09/08 22:11:42 by skoh             ###   ########.fr       */
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

static int	ps_run_steps(t_app *app)
{
	char	*step;
	int		cmd;

	while (get_next_line(0, &step))
	{
		cmd = PA;
		while (cmd < INVALID_CMD && ft_strcmp(step, ps_get_command(cmd)) != 0)
			cmd++;
		free(step);
		if (cmd == INVALID_CMD)
			break ;
		ps_exec(app, cmd);
	}
	return (step == NULL);
}

static int	ps_check(t_list *stack)
{
	t_app	app;
	int		status;

	if (!stack)
		return (EXIT_FAILURE);
	app = (t_app){.a = stack, .b = NULL, .steps = NULL};
	if (!ps_run_steps(&app))
		status = (ft_putendl_fd("Error", 2), EXIT_FAILURE);
	else if (!app.b && ps_check_sort(app.a, ft_lstsize(app.a)) == ASC)
		status = (ft_putendl_fd("OK", 1), EXIT_SUCCESS);
	else
		status = (ft_putendl_fd("KO", 1), EXIT_SUCCESS);
	ps_cleanup(&app);
	return (status);
}

int	main(int argc, char **argv)
{
	int	status;

	status = EXIT_SUCCESS;
	if (argc > 1)
		status = ps_check(ps_parse(argc - 1, argv + 1));
	if (0)
		system(">&2 leaks checker");
	return (status);
}
