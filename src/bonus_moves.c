/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:27:08 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/06 20:20:56 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bonus_swap(t_node **stack)
{
	long int	aux;

	if (!(*stack))
		return ;
	aux = (*stack)->next->content;
	(*stack)->next->content = (*stack)->content;
	(*stack)->content = aux;
}

void	bonus_reverse_rotate(t_node **stack)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->prev;
}

void	bonus_rrr(t_node **a, t_node **b)
{
	if (!(*a) || !(*b))
		return ;
	(*a) = (*a)->prev;
	(*b) = (*b)->prev;
}

void	bonus_rotate(t_node **stack)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->next;
}

void	bonus_rr(t_node **a, t_node **b)
{
	if (!(*a) || !(*b))
		return ;
	(*a) = (*a)->next;
	(*b) = (*b)->next;
}
