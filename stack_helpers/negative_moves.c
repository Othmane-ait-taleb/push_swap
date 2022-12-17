/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:34:29 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/15 10:34:43 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lop_do_rrr(int moves, t_list **stack_a, t_list **stack_b,
		t_list **op_list)
{
	int	i;

	i = 0;
	while (i-- > moves)
	{
		op_rrr(stack_a, stack_b);
		d_lstadd_back(op_list, d_lstnew(ft_strdup("rrr")));
	}
}

void	do_rrr(t_list **stack_a, t_list **stack_b, t_list **op_list)
{
	d_lstadd_back(op_list, d_lstnew(ft_strdup("rrr")));
	op_rrr(stack_a, stack_b);
}

void	negative_moves(int *moves, t_list **stack_a, t_list **stack_b,
		t_list **op_list)
{
	int	i;

	i = 0;
	if (moves[0] == moves[1])
		return (lop_do_rrr(moves[0], stack_a, stack_b, op_list));
	while (i-- > max(moves[0], moves[1]))
		do_rrr(stack_a, stack_b, op_list);
	i = 0;
	if (min(moves[0], moves[1]) == moves[0])
	{
		while (i-- > (moves[0] - moves[1]))
		{
			*stack_b = op_rrb(stack_b);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rrb")));
		}
	}
	else
	{
		while (i-- > (moves[1] - moves[0]))
		{
			*stack_a = op_rra(stack_a);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rra")));
		}
	}
}
