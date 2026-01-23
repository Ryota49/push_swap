/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:11:12 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/07 12:17:40 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_digits **stack_a, t_digits **stack_b)
{
	t_digits	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write (1, "pb\n", 3);
}

void	pa(t_digits **stack_a, t_digits **stack_b)
{
	t_digits	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write (1, "pa\n", 3);
}

void	sa(t_digits **stack_a)
{
	swap_stack_a(stack_a);
	write (1, "sa\n", 3);
}

void	sb(t_digits **stack_b)
{
	swap_stack_b(stack_b);
	write (1, "sb\n", 3);
}

void	ss(t_digits **stack_a, t_digits **stack_b)
{
	swap_stack_a(stack_a);
	swap_stack_b(stack_b);
	write (1, "ss\n", 3);
}
