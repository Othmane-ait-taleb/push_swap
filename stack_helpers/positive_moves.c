/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:44:36 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/15 10:34:22 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lop_do_rr(int moves, t_list **stack_a, t_list **stack_b,
		t_list **op_list)
{
	int	i;

	i = 0;
	while (i++ < moves)
	{
		op_rr(stack_a, stack_b);
		d_lstadd_back(op_list, d_lstnew(ft_strdup("rr")));
	}
}

void	do_rr(t_list **stack_a, t_list **stack_b, t_list **op_list)
{
	d_lstadd_back(op_list, d_lstnew(ft_strdup("rr")));
	op_rr(stack_a, stack_b);
}

void	positive_moves(int *moves, t_list **stack_a, t_list **stack_b,
		t_list **op_list)
{
	int	i;

	if (moves[0] == moves[1])
		return (lop_do_rr(moves[1], stack_a, stack_b, op_list));
	i = 0;
	while (i++ < min(moves[0], moves[1]))
		do_rr(stack_a, stack_b, op_list);
	i = 0;
	if (max(moves[0], moves[1]) == moves[0])
	{
		while (i++ < moves[0] - moves[1])
		{
			*stack_b = op_rb(stack_b);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rb")));
		}
	}
	else
	{
		while (i++ < absolute_value(moves[1]) - absolute_value(moves[0]))
		{
			*stack_a = op_ra(stack_a);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("ra")));
		}
	}
}
