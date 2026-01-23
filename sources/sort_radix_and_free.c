/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:31:12 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/08 22:44:28 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack_a(t_digits *stack_a)
{
	int	len;

	len = 0;
	while (stack_a != NULL)
	{
		len++;
		stack_a = stack_a->next;
	}
	return (len);
}

void	sort_radix(t_digits **stack_a, t_digits **stack_b, int n)
{
	int	i;
	int	j;
	int	bits;

	bits = count_bits(n);
	i = 0;
	while (i < bits)
	{
		j = len_stack_a(*stack_a);
		while (j > 0)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j--;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

int	count_bits(int size)
{
	int	max_index;
	int	bits;

	bits = 0;
	max_index = size - 1;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	sort_stack(t_digits *stack_a, int size)
{
	t_digits	*stack_b;

	stack_b = NULL;
	if (size > 1 && size <= 3)
		three_n(&stack_a, &stack_b, size);
	else if (size == 4)
		four_n(&stack_a, &stack_b);
	else if (size == 5)
		five_n(&stack_a, &stack_b);
	else if (size > 5)
		sort_radix(&stack_a, &stack_b, size);
	free_stack_a(stack_a);
}

void	free_stack_a(t_digits *stack_a)
{
	t_digits	*tmp;

	while (stack_a != NULL)
	{
		tmp = stack_a->next;
		free (stack_a);
		stack_a = tmp;
	}
}
