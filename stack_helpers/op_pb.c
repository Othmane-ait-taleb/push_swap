/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:47:18 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 10:53:30 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*new_head;

	if (ft_lstsize(*stack_a) == 0)
		return (*stack_a);
	first = *stack_a;
	new_head = (*stack_a)->next;
	if (first->next)
	{
		(first->next)->prev = NULL;
		first->next = NULL;
		first->prev = NULL;
	}
	d_lstadd_front(stack_b, first);
	return (new_head);
}
