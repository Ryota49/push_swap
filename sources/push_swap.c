/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:51:34 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/05 21:59:19 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_number(char *tmp)
{
	int	i;

	i = 0;
	if (tmp[i] == '+' || tmp[i] == '-')
		i++;
	if (tmp[i] == '\0')
		return (0);
	while (tmp[i])
	{
		if (!(tmp[i] >= '0' && tmp[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char	**all_digits(char **argv, int i, int y, int x)
{
	char	**all_digits;
	char	**tmp;

	all_digits = malloc(sizeof(char *) * (count_digits(argv) + 1));
	if (!all_digits)
		return (NULL);
	all_digits[i] = NULL;
	while (argv[y] != NULL)
	{
		x = 0;
		tmp = ft_split(argv[y], ' ');
		while (tmp[x] != NULL)
		{
			if (check_valid_number(tmp[x]) == 0)
				error_digit(all_digits, tmp, x, i);
			all_digits[i] = ft_strdup(tmp[x]);
			free (tmp[x]);
			x++;
			i++;
		}
		free (tmp);
		y++;
	}
	all_digits[i] = NULL;
	return (all_digits);
}

int	count_digits(char **argv)
{
	int		y;
	int		x;
	int		count;
	char	**tmp;

	y = 1;
	count = 0;
	while (argv[y] != NULL)
	{
		x = 0;
		tmp = ft_split(argv[y], ' ');
		while (tmp[x] != NULL)
		{
			count++;
			free (tmp[x]);
			x++;
		}
		free (tmp);
		y++;
	}
	return (count);
}

int	check_argv(char **argv, int y, int x)
{
	while (argv[y] != NULL)
	{
		x = 0;
		change_to_space(argv[y]);
		while (argv[y][x] != '\0')
		{
			if ((argv[y][x] >= '0' && argv[y][x] <= '9')
			|| argv[y][x] == ' ' || argv[y][x] == '+' || argv[y][x] == '-')
			{
				if (argv[y][x] == '+' || argv[y][x] == '-')
				{
					if (argv[y][x + 1] == '+' || argv[y][x + 1] == '-'
						|| argv[y][x + 1] == ' ')
						return (0);
					else if (x >= 1 && argv[y][x - 1] != ' ')
						return (0);
				}
				x++;
			}
			else
				return (0);
		}
		y++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**digits;
	int		size;

	if (argc == 1)
		return (0);
	if (check_argv(argv, 1, 0) == 1)
	{
		digits = all_digits(argv, 0, 1, 0);
		size = check_int_max_min(digits);
		fill_tab_int(digits, size);
		get_into_list(digits, size, 0);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
