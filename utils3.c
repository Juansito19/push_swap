/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:31:40 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/16 20:52:14 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that returns the number of moves to
bring a specific node to the top of the stack (up)*/
int	move_up(t_node **list, t_node *node)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = (*list);
	while (aux != node)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

/* Function that returns the number of moves to
bring a specific node to the top of the stack (down)*/
int	move_down(t_node **list, t_node *node)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = (*list);
	while (node != aux)
	{
		aux = aux->prev;
		i++;
	}
	return (i);
}

/* Function that assigns the type of movement we are going to use */
/* 1 =  A[up]   | B[up]   */
/* 2 =  A[down] | B[down] */
/* 3 =  A[down] | B[up]   */
/* 4 =  A[up]   | B[dwon] */
void	find_path(t_node **node_a, t_node **node_b)
{
	if ((*node_a)->cost_down <= (*node_a)->cost_up
		&& (*node_b)->cost_down <= (*node_b)->cost_up)
		(*node_b)->cheaper = 1;
	else if ((*node_a)->cost_down > (*node_a)->cost_up
		&& (*node_b)->cost_down > (*node_b)->cost_up)
		(*node_b)->cheaper = 2;
	else if ((*node_a)->cost_down > (*node_a)->cost_up
		&& (*node_b)->cost_down <= (*node_b)->cost_up)
		(*node_b)->cheaper = 3;
	else if ((*node_a)->cost_down <= (*node_a)->cost_up
		&& (*node_b)->cost_down > (*node_b)->cost_up)
		(*node_b)->cheaper = 4;
}

/* Function that counts nodes */
int	count_nodes(t_node **stack)
{
	t_node	*tmp;
	int		i;

	if (!stack || !(*stack))
		return (0);
	i = 1;
	tmp = (*stack)->next;
	while (tmp != (*stack))
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
