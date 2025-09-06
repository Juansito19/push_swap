/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:53:31 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/06 20:20:56 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Function that finds the cheapest node */
t_node	*find_cheaper(t_node **stack)
{
	t_node	*tmp;
	t_node	*aux;

	tmp = (*stack);
	aux = (*stack);
	while (1)
	{
		if (tmp->total_cost > aux->total_cost)
			tmp = aux;
		aux = aux->next;
		if (aux == (*stack))
			break ;
	}
	tmp->cheaper = 1;
	return (tmp);
}

/* Function that finds the smallest node */
t_node	*find_small_node(t_node **stack)
{
	t_node	*aux;
	t_node	*res;

	aux = (*stack);
	res = (*stack);
	while (1)
	{
		if (res->content > aux->content)
			res = aux;
		aux = aux->next;
		if (aux == (*stack))
			break ;
	}
	return (res);
}

/* function that finds the bigest node */
t_node	*find_big_node(t_node **stack)
{
	t_node	*aux;
	t_node	*res;

	aux = (*stack);
	res = (*stack);
	while (1)
	{
		if (res->content < aux->content)
			res = aux;
		aux = aux->next;
		if (aux == (*stack))
			break ;
	}
	return (res);
}

/* This functions count every word in all arguments */
int	count_words_ps(char **str, char c)
{
	int	i;
	int	sep_flag;
	int	count;

	i = 0;
	sep_flag = 1;
	count = 0;
	while (*str)
	{
		while ((*str)[i])
		{
			if ((*str)[i] == c)
				sep_flag = 1;
			if ((*str)[i] != c && sep_flag != 0)
			{
				sep_flag = 0;
				count++;
			}
			i++;
		}
		sep_flag = 1;
		i = 0;
		str++;
	}
	return (count);
}

/* This function free every node of the list */
void	free_nodes(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = (*head);
	if (!(*head))
		return ;
	while (1)
	{
		next = current->next;
		free(current);
		current = next;
		if (current == (*head))
			break ;
	}
}
