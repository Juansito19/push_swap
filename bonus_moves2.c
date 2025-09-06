/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:48:14 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/26 16:39:57 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bonus_p(t_node **dest, t_node **start)
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

void	bonus_push(t_node **dest, t_node **start)
{
	if (!(*start))
		return ;
	bonus_p(dest, start);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	long int	aux;

	if ((*stack_a))
	{
		aux = (*stack_a)->next->content;
		(*stack_a)->next->content = (*stack_a)->content;
		(*stack_a)->content = aux;
	}
	if ((*stack_b))
	{
		aux = (*stack_b)->next->content;
		(*stack_b)->next->content = (*stack_b)->content;
		(*stack_b)->content = aux;
	}
}
