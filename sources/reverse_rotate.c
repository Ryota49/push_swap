/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:11:12 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/08 16:57:23 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_down_stack_a(t_digits **stack_a)
{
	t_digits	*tmp;
	t_digits	*tmp2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = NULL;
	tmp2 = *stack_a;
	while (tmp2->next != NULL)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	tmp->next = NULL;
	tmp2->next = *stack_a;
	*stack_a = tmp2;
}

void	shift_down_stack_b(t_digits **stack_b)
{
	t_digits	*tmp;
	t_digits	*tmp2;

	if (!*(stack_b) || !(*stack_b)->next)
		return ;
	tmp = NULL;
	tmp2 = *stack_b;
	while (tmp2->next != NULL)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	tmp->next = NULL;
	tmp2->next = *stack_b;
	*stack_b = tmp2;
}

void	rra(t_digits **stack_a)
{
	shift_down_stack_a(stack_a);
	write (1, "rra\n", 4);
}

void	rrb(t_digits **stack_b)
{
	shift_down_stack_b(stack_b);
	write (1, "rrb\n", 4);
}

void	rrr(t_digits **stack_a, t_digits **stack_b)
{
	shift_down_stack_a(stack_a);
	shift_down_stack_b(stack_b);
	write (1, "rrr\n", 4);
}
