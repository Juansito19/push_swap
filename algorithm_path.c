/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:25:12 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/11 22:46:40 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Stack A and B make reverse rotate */
void	path1(t_node **stack_a, t_node **stack_b,
	t_node *node_a, t_node *node_b)
{
	while ((*stack_a) != node_a && (*stack_b) != node_b)
		rrr(stack_a, stack_b);
	while ((*stack_a) != node_a)
		rra(stack_a);
	while ((*stack_b) != node_b)
		rrb(stack_b);
	push(stack_a, stack_b, 0);
}

/* Stack A and B make rotate */
void	path2(t_node **stack_a, t_node **stack_b,
	t_node *node_a, t_node *node_b)
{
	while ((*stack_a) != node_a && (*stack_b) != node_b)
		rr(stack_a, stack_b);
	while ((*stack_a) != node_a)
		ra(stack_a);
	while ((*stack_b) != node_b)
		rb(stack_b);
	push(stack_a, stack_b, 0);
}

/* Stack A make rotate and stack B make reverse rotate */
void	path3(t_node **stack_a, t_node **stack_b,
	t_node *node_a, t_node *node_b)
{
	while ((*stack_a) != node_a)
		ra(stack_a);
	while ((*stack_b) != node_b)
		rrb(stack_b);
	push(stack_a, stack_b, 0);
}

/* Stack A make rotate reverse and stack B make rotate */
void	path4(t_node **stack_a, t_node **stack_b,
	t_node *node_a, t_node *node_b)
{
	while ((*stack_a) != node_a)
		rra(stack_a);
	while ((*stack_b) != node_b)
		rb(stack_b);
	push(stack_a, stack_b, 0);
}

/* Function that moves the smallest node to the top of stack A */
void	put_small_first(t_node **stack)
{
	t_node	*tmp;

	tmp = find_small_node(stack);
	if (move_down(stack, tmp) < move_up(stack, tmp))
	{
		while ((*stack)->index != 0)
			rra(stack);
	}
	else
	{
		while ((*stack)->index != 0)
			ra(stack);
	}
}
