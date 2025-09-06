/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:02:34 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/06 20:15:23 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function order two nodes */
void	order_2(t_node **stack)
{
	long int	a;
	long int	b;

	a = (*stack)->content;
	b = (*stack)->next->content;
	if (a > b)
		rra(stack);
}

/* This function order three */
void	order_3(t_node **stack)
{
	long int	a;
	long int	b;
	long int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (a > b && b < c && a < c)
		s1(stack, 0);
	else if (a < b && b > c && a < c)
	{
		s1(stack, 0);
		ra(stack);
	}
	else if (a > b && b > c && a > c)
	{
		s1(stack, 0);
		rra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
}

/* Function that sets cost_up, cost_down, and total_cost */
void	put_cost(t_node **stack)
{
	t_node	*aux;

	aux = (*stack);
	while (1)
	{
		aux->cost_up = move_up(stack, aux);
		aux->cost_down = move_down(stack, aux);
		if (aux->cost_down <= aux->cost_up)
			aux->total_cost = aux->cost_down;
		else
			aux->total_cost = aux->cost_up;
		aux->cheaper = 0;
		aux = aux->next;
		if (aux == (*stack))
			break ;
	}
}

/* function that sets the total_cost based on the cheapest option 
		and determines where to move it */
void	put_total_cost(t_node **a, t_node **b)
{
	t_node	*target_a;
	t_node	*aux_b;
	int		cost_a;

	if (!a || !b || !(*a) || !(*b))
		return ;
	aux_b = (*b);
	while (1)
	{
		target_a = find_node_in_a(a, aux_b);
		cost_a = move_up(a, target_a);
		if (cost_a > move_down(a, target_a))
			cost_a = move_down(a, target_a);
		if (aux_b->cost_up < aux_b->cost_down)
			aux_b->total_cost = aux_b->cost_up + cost_a;
		else
			aux_b->total_cost = aux_b->cost_down + cost_a;
		aux_b = aux_b->next;
		if (aux_b == (*b))
			break ;
	}
}

/* function that finds the target position to place 
		the node from stack B into stack A */
t_node	*find_node_in_a(t_node **stack_a, t_node *node_b)
{
	t_node	*aux_a;
	t_node	*res;

	aux_a = (*stack_a);
	res = NULL;
	while (1)
	{
		if (aux_a->prev->index < node_b->index && aux_a->index > node_b->index)
			return (aux_a);
		aux_a = aux_a->next;
		if (aux_a == (*stack_a))
			break ;
	}
	return (find_small_node(stack_a));
}
