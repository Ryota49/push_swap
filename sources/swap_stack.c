/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:09:02 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/08 16:43:16 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(t_digits **stack_a)
{
	t_digits	*tmp1;
	t_digits	*tmp2;

	if (!*stack_a)
		return ;
	tmp1 = *stack_a;
	if (!tmp1->next)
		return ;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	*stack_a = tmp2;
	tmp2->next = tmp1;
}

void	swap_stack_b(t_digits **stack_b)
{
	t_digits	*tmp1;
	t_digits	*tmp2;

	if (!*stack_b)
		return ;
	tmp1 = *stack_b;
	if (!tmp1->next)
		return ;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	*stack_b = tmp2;
	tmp2->next = tmp1;
}

void	shift_up_stack_a(t_digits **stack_a)
{
	t_digits	*tmp;
	t_digits	*tmp2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	tmp2 = *stack_a;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
}

void	shift_up_stack_b(t_digits **stack_b)
{
	t_digits	*tmp;
	t_digits	*tmp2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	tmp2 = *stack_b;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
}
