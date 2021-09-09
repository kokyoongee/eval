/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:44:21 by skoh              #+#    #+#             */
/*   Updated: 2021/09/07 23:26:25 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_compare_list(void *a, void *b)
{
	if (vtoi(a) < vtoi(b))
		return (-1);
	return (vtoi(a) > vtoi(b));
}

// support 1 or multi parameters (either num or multi-num-string)
// invalid num, non-num or empty param will be error
t_list	*ps_parse(int count, char **argv)
{
	int		ok;
	int		num;
	t_list	*list;
	char	**split;
	char	**strs;

	split = NULL;
	list = NULL;
	ok = count;
	while (ok && count--)
	{
		strs = (split = ft_split(*argv++, ' '));
		ok = !!strs;
		while (ok && *strs)
			ok = ft_atoi_success(*strs++, &num)
				&& ft_list_enqueue_unique(&list, itov(num), &ps_compare_list);
		ft_splitfree(&split);
	}
	if (ok)
		return (list);
	ft_putendl_fd("Error", 2);
	ft_lstclear(&list, NULL);
	return (NULL);
}
