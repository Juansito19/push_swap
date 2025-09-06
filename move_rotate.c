/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:20:20 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/11 21:26:41 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate a
void	ra(t_node **a)
{
	(*a) = (*a)->next;
	ft_printf("ra\n");
}

// rotate b
void	rb(t_node **b)
{
	(*b) = (*b)->next;
	ft_printf("rb\n");
}

// rotate rotate
void	rr(t_node **a, t_node **b)
{
	(*a) = (*a)->next;
	(*b) = (*b)->next;
	ft_printf("rr\n");
}
