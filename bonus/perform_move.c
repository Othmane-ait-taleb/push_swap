/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:15:35 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 10:09:22 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_move(t_list **stack_a, t_list **stack_b, int move)
{
	if (move == 0)
		*stack_a = op_ra(stack_a);
	else if (move == 1)
		*stack_b = op_rb(stack_b);
	else if (move == 2)
		*stack_a = op_pb(stack_a, stack_b);
	else if (move == 3)
		*stack_b = op_rrb(stack_b);
	else if (move == 4)
		op_rr(stack_a, stack_b);
	else if (move == 5)
		*stack_b = op_pa(stack_a, stack_b);
	else if (move == 6)
		*stack_a = op_rra(stack_a);
	else if (move == 7)
		op_rrr(stack_a, stack_b);
	else if (move == 8)
		*stack_b = op_sb(stack_b);
	else if (move == 9)
		*stack_a = op_sa(stack_a);
	else if (move == 10)
		op_ss(stack_a, stack_b);
}
