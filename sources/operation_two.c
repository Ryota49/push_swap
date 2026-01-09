/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:12:31 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/08 16:14:33 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_digits **stack_a)
{
	shift_up_stack_a(stack_a);
	write (1, "ra\n", 3);
}

void	rb(t_digits **stack_b)
{
	shift_up_stack_b(stack_b);
	write (1, "rb\n", 3);
}

void	rr(t_digits **stack_a, t_digits **stack_b)
{
	shift_up_stack_a(stack_a);
	shift_up_stack_b(stack_b);
	write (1, "rr\n", 3);
}
