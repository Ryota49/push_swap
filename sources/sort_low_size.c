/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:39:08 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/19 22:44:28 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_n(t_digits **stack_a, t_digits **stack_b, int size)
{
	if (size == 2)
	{
		sa(stack_a);
	}
	if (size == 3)
	{
		pb(stack_a, stack_b);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		pa (stack_a, stack_b);
		if ((*stack_a)->index > (*stack_a)->next->index
			&& (*stack_a)->index > (*stack_a)->next->next->index)
			ra(stack_a);
		else if ((*stack_a)->index > (*stack_a)->next->index
			&& (*stack_a)->index < (*stack_a)->next->next->index)
			sa(stack_a);
	}
}

void	four_n(t_digits **stack_a, t_digits **stack_b)
{
	int	position;

	position = find_position(*stack_a, 0);
	move_to_top(stack_a, position, 4);
	pb(stack_a, stack_b);
	three_n(stack_a, stack_b, 3);
	pa(stack_a, stack_b);
}

int	find_position(t_digits *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

void	move_to_top(t_digits **stack_a, int position, int size)
{
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(stack_a);
			position--;
		}
	}
	else
	{
		while (size - position > 0)
		{
			rra(stack_a);
			position++;
		}
	}
}

void	five_n(t_digits **stack_a, t_digits **stack_b)
{
	int	position;

	if ((*stack_a)->index == 1)
	{
		pb(stack_a, stack_b);
		position = find_position((*stack_a), 0);
		move_to_top(stack_a, position, 4);
		pb(stack_a, stack_b);
		three_n(stack_a, stack_b, 3);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else
	{
		position = find_position(*stack_a, 0);
		move_to_top(stack_a, position, 5);
		pb(stack_a, stack_b);
		position = find_position(*stack_a, 1);
		move_to_top(stack_a, position, 4);
		pb(stack_a, stack_b);
		three_n(stack_a, stack_b, 3);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
