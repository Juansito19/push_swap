/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:15:12 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/06 20:20:56 by jbrosio          ###   ########.fr       */
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
// /* swap A with 3 nodes */
// void	sa1(t_node **a)
// {
// 	(*a)->next = (*a)->next->next;
// 	(*a)->prev = (*a)->next->prev;
// 	(*a)->prev->prev = (*a)->prev->prev->next;
// 	(*a)->prev->next = (*a);
// 	(*a)->next->prev = (*a);
// 	(*a)->next->next = (*a)->prev;
// 	(*a) = (*a)->prev;
// 	ft_printf("sa\n");
// }

// /* swap A with more than 3 nodes */
// void	sa2(t_node **a)
// {
// 	(*a)->prev->next = (*a)->next;
// 	(*a)->next->next->prev = (*a);
// 	(*a)->next->prev = (*a)->prev;
// 	(*a)->next = (*a)->next->next;
// 	(*a)->prev->next->next = (*a);
// 	(*a)->prev = (*a)->prev->next;
// 	(*a) = (*a)->prev;
// 	ft_printf("sa\n");
// }

// /* swap B with 3 nodes */
// void	sb1(t_node **b)
// {
// 	(*b)->next = (*b)->next->next;
// 	(*b)->prev = (*b)->next->prev;
// 	(*b)->prev->prev = (*b)->prev->prev->next;
// 	(*b)->prev->next = (*b)->prev;
// 	(*b)->next->prev = (*b);
// 	(*b) = (*b)->prev;
// 	ft_printf("sb\n");
// }

// /* swap B with more than 3 nodes */
// void	sb2(t_node **b)
// {
// 	(*b)->prev->next = (*b)->next;
// 	(*b)->next->next->prev = (*b);
// 	(*b)->next->prev = (*b)->prev;
// 	(*b)->next = (*b)->next->next;
// 	(*b)->prev->next->next = (*b);
// 	(*b) = (*b)->prev;
// 	ft_printf("sb\n");
// }
