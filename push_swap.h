/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:49:30 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/26 14:33:57 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_node
{
	long int		content;
	int				index;
	int				dest;
	int				cost_up;
	int				cost_down;
	int				total_cost;
	int				cheaper;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int			main(int argc, char **argv);

/*────── FUNCTIONS FOR NODES ──────*/
/*---------- adding nodes ----------*/
t_node		*newnode(long int content);
void		add_node1(t_node *a, t_node *b);
void		add_node2(t_node **a, t_node **b);
t_node		*fill_a(long int *number_list, int size);
void		get_index(t_node *a, long int *list, int size);

// void	print_nodes(t_node **a);
/*─────── ALGORITHM FUNCTIONS ───────*/
/*------- principal functions -------*/
void		case_diff(t_node **a, int size);
t_node		*start_algorithm(t_node **a, int size);
void		algorithm1(t_node **a, int size);
void		make_sort(t_node **a, t_node **b);
/*--------- algorithm tools ---------*/
t_node		*find_small_node(t_node **stack);
t_node		*find_big_node(t_node **stack);
void		find_path(t_node **node_a, t_node **node_b);
t_node		*find_node_in_a(t_node **stack_a, t_node *node_b);
int			count_nodes(t_node **stack);
void		free_nodes(t_node **a);
void		put_cost(t_node **stack);
void		put_total_cost(t_node **a, t_node **b);
t_node		*find_cheaper(t_node **stack);
/*---------- sort functions ----------*/
void		order_2(t_node **stack);
void		order_3(t_node **stack);
void		path1(t_node **stack_a,
				t_node **stack_b, t_node *node_a, t_node *node_b);
void		path2(t_node **stack_a,
				t_node **stack_b, t_node *node_a, t_node *node_b);
void		path3(t_node **stack_a,
				t_node **stack_b, t_node *node_a, t_node *node_b);
void		path4(t_node **stack_a,
				t_node **stack_b, t_node *node_a, t_node *node_b);
void		put_small_first(t_node **stack);

/*─────── MOVEMENTS FUNCTIONS ───────*/
/*-------------- swap ---------------*/
void		s1(t_node **stack, int flag);
void		s2(t_node **stack, int flag);
/*-------------- push ---------------*/
void		push(t_node **dest, t_node **start, int flag);
/*------------- rotate --------------*/
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);
/*--------- reverse rotate ----------*/
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);

/*───────── UTILS FUNCTIONS ─────────*/
long int	*number_list(char **str);
long int	*create_number_list(char **str, long int *num, int size);
long int	*order_list(long int *list, int size);
int			count_words_ps(char **str, char c);
void		*free_all_array(void **big);
char		*fix_str(char **str);
int			move_up(t_node **list, t_node *node);
int			move_down(t_node **list, t_node *node);

/*───────── ERROS FUNCTIONS ─────────*/
int			check_num1(char *str);
int			check_num2(long int n);
int			check_num3(char **str);
int			check_sorted(long int *list, int size);
int			check_empty_str(char **str);

/*───────────── BONUS ────────────────*/
/*--------- checker functions --------*/
t_node		*init_nodes(char **str);
void		ft_make_instruction(t_node **stack_a,
				t_node **stack_b, char *movement);
int			check_sorted_bonus(t_node **stack);
void		ft_bonus_error(t_node **stack_a, t_node **stack_b, char *line);
/*------------- moves ----------------*/
void		bonus_swap(t_node **stack);
void		bonus_reverse_rotate(t_node **stack);
void		bonus_rrr(t_node **a, t_node **b);
void		bonus_rotate(t_node **stack);
void		bonus_rr(t_node **a, t_node **b);
void		bonus_push(t_node **dest, t_node **start);
void		ss(t_node **stack_a, t_node **stack_b);

#endif