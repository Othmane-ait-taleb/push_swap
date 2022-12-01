/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:47:18 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/01 11:31:04 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	if (!*stack_b || !*stack_a)
		return ;
	last = ft_lstlast(*stack_a);
	d_lstadd_back(stack_b, last);
	(last->prev)->next = NULL;

}
