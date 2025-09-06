/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:49:15 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/16 20:57:52 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that checks if there are 3 or more numbers */
t_node	*start_algorithm(t_node **a, int size)
{
	if (size <= 3)
	{
		case_diff(a, size);
		return ((*a));
	}
	else
	{
		algorithm1(a, size);
		return ((*a));
	}
}

/* Function that handles cases with 1, 2, or 3 numbers */
void	case_diff(t_node **a, int size)
{
	t_node	*b;

	b = NULL;
	if (size == 1)
		return ;
	else if (size == 2)
		order_2(a);
	else if (size == 3)
		order_3(a);
}

/* Function that handles the case of 500 numbers in the list */
static void	max_case(t_node **a, t_node **b, int size)
{
	int	chunk_size;
	int	pushed;
	int	target_in_b;

	chunk_size = size / 5;
	pushed = 0;
	target_in_b = size - 3;
	while (count_nodes(a) > 3 && pushed < target_in_b)
	{
		if ((*a)->index <= pushed + chunk_size)
		{
			push(b, a, 1);
			pushed++;
			if ((*b) && (*b)->index < pushed - chunk_size / 2)
				rb(b);
		}
		else
			ra(a);
	}
}

/* Function that pushes all elements to stack B, 
	leaving only 3 elements in stack A */
void	algorithm1(t_node **a, int size)
{
	t_node	*b;

	b = NULL;
	if (size >= 500)
		max_case(a, &b, size);
	else
	{
		while (count_nodes(a) > 3)
		{
			if ((*a)->index == 0 || (*a)->index == 1 || (*a)->index == 2)
				ra(a);
			else
				push(&b, a, 1);
		}
	}
	order_3(a);
	make_sort(a, &b);
}

/* Function that sorts the stack using cost-based logic 
		and optimized moves */
void	make_sort(t_node **a, t_node **b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	while (count_nodes(b) > 0)
	{
		put_cost(a);
		put_cost(b);
		put_total_cost(a, b);
		tmp_b = find_cheaper(b);
		tmp_a = find_node_in_a(a, tmp_b);
		find_path(&tmp_a, &tmp_b);
		if (tmp_b->cheaper == 1)
			path1(a, b, tmp_a, tmp_b);
		else if (tmp_b->cheaper == 2)
			path2(a, b, tmp_a, tmp_b);
		else if (tmp_b->cheaper == 3)
			path3(a, b, tmp_a, tmp_b);
		else if (tmp_b->cheaper == 4)
			path4(a, b, tmp_a, tmp_b);
	}
	put_small_first(a);
}
