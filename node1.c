/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:25:43 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/06 18:09:27 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function create a new node */
t_node	*newnode(long int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->index = 0;
	new_node->dest = 0;
	new_node->cheaper = 0;
	new_node->cost_up = 0;
	new_node->cost_down = 0;
	new_node->total_cost = 0;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

/* This function connect two nodes */
void	add_node1(t_node *a, t_node *b)
{
	a->prev = b;
	a->next = b;
	b->prev = a;
	b->next = a;
}

/* This function connect a node with more than 3 nodes */
void	add_node2(t_node **a, t_node **b)
{
	(*b)->next = (*a);
	(*b)->prev = (*a)->prev;
	(*a)->prev->next = (*b);
	(*a)->prev = (*b);
}

/* This functions create all nodes in A */
t_node	*fill_a(long int *number_list, int size)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = newnode(number_list[0]);
	i = 1;
	while (i < size)
	{
		if (i < 2)
		{
			b = newnode(number_list[i]);
			add_node1(a, b);
		}
		else
		{
			b = newnode(number_list[i]);
			add_node2(&a, &b);
		}
		if (!b)
			return (NULL);
		i++;
	}
	return (a);
}

/* This functions put the sorted index of the list number */
void	get_index(t_node *a, long int *list, int size)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (i < size)
	{
		if (list[i] == tmp->content)
		{
			if (i != size - 1)
				tmp->dest = list[i + 1];
			tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
	find_big_node(&a)->dest = list[0];
}
