/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:23:09 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/06 20:26:16 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* function for print all nodes */
// void	print_nodes(t_node **a)
// {
// 	t_node *temp;
// 	int i;

// 	i = 0;
// 	temp = (*a);
// 	while (1)
// 	{
// 		printf("───────────────────────────────────\n");
// 		printf(">> Esto es el content = %ld\n", temp->content);
// 		printf("-------------------------> NODO [%d]\n", i);
// 		printf(">> Esto es su  index  = %d\n", temp->index);
// 		printf(">> Esto es su  dest   = %d\n", temp->dest);
// 		printf(">> Esto es su  cost_up   = %d\n", temp->cost_up);
// 		printf(">> Esto es su  cost_down   = %d\n", temp->cost_down);
// 		printf(">> Esto es su  total_cost   = %d\n", temp->total_cost);
// 		printf(">> Esto es su  cheaper   = %d\n", temp->cheaper);
// 		printf(">> Esto es su  prev   = %ld\n", temp->prev->content);
// 		printf(">> Esto es su  next   = %ld\n", temp->next->content);
// 		printf("───────────────────────────────────\n");
// 		i++;
// 		temp = temp->next;
// 		if (temp == (*a))
// 			break ;
// 	}
// }

/* put index and dest in all nodes */
t_node	*make_order(long int *list, int size, t_node *a)
{
	long int	*list_ordered;

	list_ordered = order_list(list, size);
	get_index(a, list_ordered, size);
	return (a);
}

/* principal function */
t_node	*push_swap(char **str)
{
	t_node		*node_a;
	long int	*list;
	int			size;

	if (!str || !check_empty_str(str))
		return (NULL);
	list = number_list(str);
	size = count_words_ps(str, ' ');
	if (!list)
		return (NULL);
	if (check_sorted(list, size))
	{
		free(list);
		exit(0);
	}
	node_a = fill_a(list, size);
	if (!node_a)
	{
		free_all_array((void **)list);
		return (NULL);
	}
	node_a = make_order(list, size, node_a);
	node_a = start_algorithm(&node_a, size);
	free(list);
	return (node_a);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	int		i;

	i = 1;
	if (ac < 2)
		return (0);
	stack_a = push_swap(&av[i]);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	free_nodes(&stack_a);
	return (0);
}
