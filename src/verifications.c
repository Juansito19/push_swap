/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:48 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/06 20:20:56 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Function that checks if a specific character exists in the arguments */
int	check_num1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Function that checks if a number exceeds the limits of INT */
/* 		range of a signed int: [-2147483648, 2147483647] 	  */
int	check_num2(long int n)
{
	if (n > 2147483647)
		return (0);
	else if (n < -2147483648)
		return (0);
	return (1);
}

/* Function that checks for duplicate numbers in the arguments */
int	check_num3(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atol(str[i]) == ft_atol(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Function that checks if the numbers are already sorted in ascending order */
int	check_sorted(long int *list, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (list[i] > list[j])
				return (0);
			j++;
		}
		j = i + 1;
		i++;
	}
	return (1);
}

/* Function that checks if any argument is empty or contains only spaces */
int	check_empty_str(char **str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] > 32)
				flag++;
			j++;
		}
		if (!flag)
			return (0);
		flag = 0;
		j = 0;
		i++;
	}
	return (1);
}
