/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:14:41 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/26 14:44:21 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bonus_error(t_node **stack_a, t_node **stack_b, char *line)
{
	if (line)
		free(line);
	free_nodes(stack_a);
	free_nodes(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	check_sorted_bonus(t_node **stack)
{
	t_node	*tmp_1;

	if (!(*stack))
		return (0);
	if ((*stack)->next == (*stack))
		return (1);
	tmp_1 = (*stack);
	while (1)
	{
		if (tmp_1->content > tmp_1->next->content)
			return (0);
		tmp_1 = tmp_1->next;
		if (tmp_1->next == (*stack))
			break ;
	}
	return (1);
}

void	ft_make_instruction(t_node **stack_a, t_node **stack_b, char *movement)
{
	if (ft_strncmp(movement, "sa\n", 3) == 0)
		bonus_swap(stack_a);
	else if (ft_strncmp(movement, "sb\n", 3) == 0)
		bonus_swap(stack_b);
	else if (ft_strncmp(movement, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(movement, "pa\n", 3) == 0)
		bonus_push(stack_a, stack_b);
	else if (ft_strncmp(movement, "pb\n", 3) == 0)
		bonus_push(stack_b, stack_a);
	else if (ft_strncmp(movement, "ra\n", 3) == 0)
		bonus_rotate(stack_a);
	else if (ft_strncmp(movement, "rb\n", 3) == 0)
		bonus_rotate(stack_b);
	else if (ft_strncmp(movement, "rr\n", 3) == 0)
		bonus_rr(stack_a, stack_b);
	else if (ft_strncmp(movement, "rra\n", 4) == 0)
		bonus_reverse_rotate(stack_a);
	else if (ft_strncmp(movement, "rrb\n", 4) == 0)
		bonus_reverse_rotate(stack_b);
	else if (ft_strncmp(movement, "rrr\n", 4) == 0)
		bonus_rrr(stack_a, stack_b);
	else
		ft_bonus_error(stack_a, stack_b, movement);
}

t_node	*init_nodes(char **str)
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
		node_a = fill_a(list, size);
		free(list);
		return (node_a);
	}
	node_a = fill_a(list, size);
	if (!node_a)
	{
		free_all_array((void **)list);
		return (NULL);
	}
	free(list);
	return (node_a);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*line;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_a = init_nodes(&av[1]);
	if (!stack_a)
		ft_bonus_error(&stack_a, &stack_b, NULL);
	line = get_next_line(0);
	while (line != NULL)
	{
		ft_make_instruction(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sorted_bonus(&stack_a) && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	free_nodes(&stack_a);
	free_nodes(&stack_b);
	return (0);
}
