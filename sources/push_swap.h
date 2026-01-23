/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:12:02 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/08 22:37:21 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* my struct list of digits with their index */

typedef struct s_digits
{
	int					digit;
	int					index;
	struct s_digits		*next;
}	t_digits;

/* My functions prototypes */

int					check_argv(char **argv, int y, int x);
int					count_digits(char **argv);
char				**all_digits(char **argv, int i, int y, int x);
int					check_valid_number(char *tmp);

/* utility functions */

void				change_to_space(char *argv);
long				ft_atol(char *digits);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(char *str);
char				*ft_strdup(char *s);

/* error functions */

void				error_digit(char **all_digits, char **tmp, int x, int i);
void				error_int(char **digits);

/* verification with tab of int functions */

void				fill_tab_int(char **digits, int size);
int					check_int_max_min(char **digits);
void				check_double(char **digits, int size, int *tab_int);
void				check_order(char **digits, int size, int *tab_int);

/* creation of the stack_a list and add index order on the list */

void				free_tab_digits(char **digits);
void				get_into_list(char **digits, int size, int i);
void				find_index(t_digits *stack_a, int size, int i, long min);
void				initialise_index(t_digits *stack_a, int size);

/* operations */

void				sa(t_digits **stack_a);
void				sb(t_digits **stack_b);
void				ss(t_digits **stack_a, t_digits **stack_b);
void				pa(t_digits **stack_a, t_digits **stack_b);
void				pb(t_digits **stack_a, t_digits **stack_b);
void				ra(t_digits **stack_a);
void				rb(t_digits **stack_b);
void				rr(t_digits **stack_a, t_digits **stack_b);
void				rra(t_digits **stack_a);
void				rrb(t_digits **stack_b);
void				rrr(t_digits **stack_a, t_digits **stack_b);

/* swap stack a and b */

void				swap_stack_b(t_digits **stack_b);
void				swap_stack_a(t_digits **stack_a);

/* shift stack a and b */

void				shift_up_stack_a(t_digits **stack_a);
void				shift_up_stack_b(t_digits **stack_b);
void				shift_down_stack_a(t_digits **stack_a);
void				shift_down_stack_b(t_digits **stack_b);

/* sort three and five numbers functions */

void				three_n(t_digits **stack_a, t_digits **stack_b, int size);
void				four_n(t_digits **stack_a, t_digits **stack_b);
void				five_n(t_digits **stack_a, t_digits **stack_b);
int					find_position(t_digits *stack, int index);
void				move_to_top(t_digits **stack_a, int position, int size);

/* radix sort */

void				sort_radix(t_digits **stack_a, t_digits **stack_b, int n);
void				sort_stack(t_digits *stack_a, int size);
int					count_bits(int size);
int					len_stack_a(t_digits *stack_a);

/* free stack after it is sorted */

void				free_stack_a(t_digits *stack_a);

#endif
