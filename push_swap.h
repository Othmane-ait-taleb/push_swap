/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:24:35 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/13 12:36:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			input_checker(int argc, char const *argv[]);
long long	ft_atol(const char *str);
t_list		*d_lstnew(void *content);
void		initialize_stack(t_list **head, int argc, char const *argv[]);
void		initialize_stack_reverse(t_list **head, int argc,
				char const *argv[]);
void		d_lstadd_back(t_list **lst, t_list *new);
t_list		*op_ra(t_list **stack);
t_list		*op_rb(t_list **stack);
void		op_rr(t_list **stack_a, t_list **stack_b);
t_list		*op_rra(t_list **stack);
t_list		*op_rrb(t_list **stack);
void		op_rrr(t_list **stack_a, t_list **stack_b);
t_list		*op_pb(t_list **stack_a, t_list **stack_b);
t_list		*op_pa(t_list **stack_a, t_list **stack_b);

int			**lis(t_list *list);
void		filter_lis(int **array_and_size, t_list **stack_a, t_list **stack_b,
				t_list **op_list);
int			**put_in_correct_position(t_list **stack_a, int size_a,
				t_list **stack_b, int size_b);
int			*list_to_array(t_list *list, int size);
int			max_of_array(int *array_a, int size_a);
int			min(int a, int b);
int			max(int a, int b);
void		apply_moves(int **pos_tab, t_list **stack_a, t_list **stack_b,
				t_list **op_list);
int			*min_moves(int **tab, int size_b);
int			absolute_value(int a);
void		put_smallest_number_top(t_list **stack, t_list **op_list);
void		reverse_stack(t_list **stack);
void		d_lstadd_front(t_list **lst, t_list *new);
int			is_sorted(t_list *stack);


#endif