/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_into_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:11:12 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/07 12:17:40 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_index(t_digits *stack_a, int size)
{
	t_digits	*tmp;
	int			i;
	long		min;

	i = 0;
	min = 0;
	tmp = stack_a;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	find_index(stack_a, size, i, min);
	sort_stack(stack_a, size);
}

void	find_index(t_digits *stack_a, int size, int i, long min)
{
	t_digits	*tmp;
	t_digits	*min_node;

	tmp = stack_a;
	while (i < size)
	{
		tmp = stack_a;
		min = LONG_MAX;
		min_node = NULL;
		while (tmp)
		{
			if (tmp->index == -1 && tmp->digit < min)
			{
				min = tmp->digit;
				min_node = tmp;
			}
			tmp = tmp->next;
		}
		if (min_node)
			min_node->index = i;
		i++;
	}
}

void	get_into_list(char **digits, int size, int i)
{
	t_digits	*stack_a;
	t_digits	*new;
	t_digits	*tmp;

	stack_a = NULL;
	while (i < size)
	{
		new = malloc(sizeof(t_digits));
		if (!new)
			error_int(digits);
		new->digit = ft_atol(digits[i]);
		new->next = NULL;
		if (!stack_a)
			stack_a = new;
		else
		{
			tmp = stack_a;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		i++;
	}
	free_tab_digits(digits);
	initialise_index(stack_a, size);
}

void	free_tab_digits(char **digits)
{
	int	i;

	i = 0;
	while (digits[i] != NULL)
	{
		free (digits[i]);
		i++;
	}
	free (digits);
}
