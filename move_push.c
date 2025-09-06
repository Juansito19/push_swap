/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:16:48 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/10 22:03:40 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push movements */
static void	p(t_node **dest, t_node **start)
{
	t_node	*node;

	node = (*start);
	if ((*start)->next == node)
		(*start) = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		(*start) = node->next;
	}
	if (!(*dest))
	{
		node->next = node;
		node->prev = node;
		(*dest) = node;
	}
	else
	{
		node->next = (*dest);
		node->prev = (*dest)->prev;
		(*dest)->prev->next = node;
		(*dest)->prev = node;
		(*dest) = node;
	}
}

void	push(t_node **dest, t_node **start, int flag)
{
	if (!start)
		return ;
	p(dest, start);
	if (flag)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}
