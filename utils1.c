/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:00:13 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/16 20:53:06 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* this function make free of all the double string 
				and return NULL */
void	*free_all_array(void **big)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)big;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

/* this function take every string of de arguments 
			and make de one big straing */
char	*fix_str(char **str)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (i > 0)
			res = ft_strjoin(res, " ");
		res = ft_strjoin(res, str[i]);
		if (!res)
			return (NULL);
		i++;
	}
	return (res);
}

/* this function create de long int list */
long int	*create_number_list(char **str, long int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!check_num3(str) || size == 0)
	{
		free(num);
		return (NULL);
	}
	while (i < size && j < size)
	{
		if (check_num1(str[j]) == 0 || check_num2(ft_atol(str[j])) == 0
			|| !ft_double_sign_error(str[j]))
		{
			free(num);
			return (NULL);
		}
		num[i] = ft_atol(str[j]);
		i++;
		j++;
	}
	return (num);
}

/* this functions order the list */
long int	*order_list(long int *list, int size)
{
	long int	i;
	long int	j;
	long int	aux;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] > list[j])
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
			j++;
		}
		i++;
	}
	return (list);
}

/* This function makes use of all of them 
		to create the int array */
long int	*number_list(char **str)
{
	char		**number_list;
	char		*temp;
	long int	*res;
	int			size;

	temp = fix_str(str);
	if (!temp)
		return (NULL);
	size = count_words_ps(str, ' ');
	res = (long int *)malloc(size * sizeof(long int));
	if (!res)
		return (free(temp), NULL);
	number_list = ft_split(temp, ' ');
	if (!number_list)
		return (free(res), free(temp), NULL);
	res = create_number_list(number_list, res, size);
	if (!res)
	{
		free(temp);
		free_all_array((void **)number_list);
		return (NULL);
	}
	free_all_array((void **)number_list);
	free(temp);
	return (res);
}
