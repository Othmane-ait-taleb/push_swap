/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:40:02 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 10:33:39 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_sb(t_list **stack_b)
{
	t_list	*second;

	if (ft_lstsize(*stack_b) <= 1)
		return (*stack_b);
	if (ft_lstsize(*stack_b) == 2)
	{
		second = (*stack_b)->next;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = second;
		second->next = (*stack_b);
		second->prev = NULL;
		return (second);
	}
	second = (*stack_b)->next;
	(*stack_b)->next = second->next;
	(second->next)->prev = *stack_b;
	(*stack_b)->prev = second;
	second->next = *stack_b;
	second->prev = NULL;
	return (second);
}
