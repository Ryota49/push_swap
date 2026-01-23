/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:27:12 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/04 14:22:54 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_to_space(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] >= 9 && argv[i] <= 13)
			argv[i] = ' ';
		i++;
	}
}

int	check_int_max_min(char **digits)
{
	int		i;
	long	digit;

	i = 0;
	while (digits[i] != NULL)
	{
		digit = ft_atol(digits[i]);
		if (digit > INT_MAX || digit < INT_MIN)
			error_int(digits);
		i++;
	}
	return (i);
}

void	fill_tab_int(char **digits, int size)
{
	int		i;
	int		*tab_int;

	tab_int = malloc(sizeof(int) * size);
	if (!tab_int)
		error_int(digits);
	i = 0;
	while (i < size)
	{
		tab_int[i] = ft_atol(digits[i]);
		i++;
	}
	check_double(digits, size, tab_int);
	check_order(digits, size, tab_int);
	free (tab_int);
}

void	check_order(char **digits, int size, int *tab_int)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size - 1)
	{
		if (tab_int[i] < tab_int[i + 1])
			count++;
		i++;
	}
	if (count == size - 1)
	{
		free (tab_int);
		i = 0;
		while (digits[i])
		{
			free (digits[i]);
			i++;
		}
		free (digits);
		exit (0);
	}
}

void	check_double(char **digits, int size, int *tab_int)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab_int[i] == tab_int[j])
			{
				free (tab_int);
				error_int(digits);
			}
			j++;
		}
		i++;
	}
}
