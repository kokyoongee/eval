/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:12:35 by skoh              #+#    #+#             */
/*   Updated: 2021/09/08 22:12:48 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*ps_get_command(enum e_push_swap i)
{
	const char	*cmds[] = {
		[PA] = "pa",
		[PB] = "pb",
		[SA] = "sa",
		[SB] = "sb",
		[SS] = "ss",
		[RA] = "ra",
		[RB] = "rb",
		[RR] = "rr",
		[RRA] = "rra",
		[RRB] = "rrb",
		[RRR] = "rrr",
	};

	return (cmds[i]);
}
