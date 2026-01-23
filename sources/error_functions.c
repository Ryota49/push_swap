/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:49:04 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/17 21:59:19 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_digit(char **all_digits, char **tmp, int x, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free (all_digits[j]);
		j++;
	}
	free (all_digits);
	while (tmp[x] != NULL)
	{
		free (tmp[x]);
		x++;
	}
	free (tmp);
	write (2, "Error\n", 6);
	exit (1);
}

void	error_int(char **digits)
{
	int	j;

	j = 0;
	while (digits[j] != NULL)
	{
		free (digits[j]);
		j++;
	}
	free (digits);
	write (2, "Error\n", 6);
	exit (1);
}
