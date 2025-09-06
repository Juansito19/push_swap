/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:20:06 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/06 20:20:56 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// reverse rotate a
void	rra(t_node **a)
{
	(*a) = (*a)->prev;
	ft_printf("rra\n");
}

// reverse rotate b
void	rrb(t_node **b)
{
	(*b) = (*b)->prev;
	ft_printf("rrb\n");
}

// reverse rotate rotate
void	rrr(t_node **a, t_node **b)
{
	(*a) = (*a)->prev;
	(*b) = (*b)->prev;
	ft_printf("rrr\n");
}
