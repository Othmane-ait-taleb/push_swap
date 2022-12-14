/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:47:18 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 10:48:03 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*new_head;

	if (ft_lstsize(*stack_b) == 0)
		return (*stack_b);
	first = *stack_b;
	new_head = (*stack_b)->next;
	if (first->next)
	{
		(first->next)->prev = NULL;
		first->next = NULL;
		first->prev = NULL;
	}
	d_lstadd_front(stack_a, first);
	return (new_head);
}
