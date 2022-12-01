/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:24:35 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/01 11:55:35 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int				input_checker(int argc, char const *argv[]);
long long		ft_atol(const char *str);
t_list			*d_lstnew(void *content);
void			initialize_stack(t_list **head, int argc, char const *argv[]);
void			d_lstadd_back(t_list **lst, t_list *new);
t_list			*op_ra(t_list **stack);
t_list			*op_rra(t_list **stack);
void			op_pb(t_list **stack_a, t_list **stack_b);

int				**lis(t_list *list);
void			filter_lis(int	*array, int *size, t_list *stack_a, t_list *stack_b);

#endif