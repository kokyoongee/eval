/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:41:29 by skoh              #+#    #+#             */
/*   Updated: 2021/09/05 23:51:43 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/btree.h"
#include <stdlib.h>

static t_bt_item	*ps_new_btree(t_list *list)
{
	t_bt_item	*node;

	node = malloc(sizeof(t_bt_item));
	if (node)
	{
		node->list = list;
		node->value = vtoi(list->content);
	}
	return (node);
}

static int	ps_compare_btree(t_bt_item *a, t_bt_item *b)
{
	if (a->value < b->value)
		return (-1);
	return (a->value > b->value);
}

static void	ps_update_list(void *node, void *order)
{
	((t_bt_item *)node)->list->content = itov(++*(int *)order);
}

static void	ps_free_btree(void *node)
{
	free(node);
}

void	ps_normalize(t_list *list)
{
	t_btree	*head;
	int		order;

	head = NULL;
	while (list)
	{
		head = btree_add(head, ps_new_btree(list), &ps_compare_btree);
		list = list->next;
	}
	order = 0;
	btree_apply_infix(head, &ps_update_list, &order);
	btree_free(head, &ps_free_btree);
}
