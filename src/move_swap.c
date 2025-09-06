/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:15:12 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/06 20:25:50 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* swap A with 3 nodes */
void	s1(t_node **stack, int flag)
{
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev = (*stack)->next->prev;
	(*stack)->prev->prev = (*stack)->prev->prev->next;
	(*stack)->prev->next = (*stack);
	(*stack)->next->prev = (*stack);
	(*stack)->next->next = (*stack)->prev;
	(*stack) = (*stack)->prev;
	if (flag)
		ft_printf("sb\n");
	else if (!flag)
		ft_printf("sa\n");
}

/* swap A with more than 3 nodes */
void	s2(t_node **stack, int flag)
{
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->next->prev = (*stack);
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev->next->next = (*stack);
	(*stack)->prev = (*stack)->prev->next;
	(*stack) = (*stack)->prev;
	if (flag)
		ft_printf("sb\n");
	else if (!flag)
		ft_printf("sa\n");
}
