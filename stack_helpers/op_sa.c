/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:29:33 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 10:33:47 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_sa(t_list **stack_a)
{
	t_list	*second;

	if (ft_lstsize(*stack_a) <= 1)
		return (*stack_a);
	if (ft_lstsize(*stack_a) == 2)
	{
		second = (*stack_a)->next;
		(*stack_a)->next = NULL;
		(*stack_a)->prev = second;
		second->next = (*stack_a);
		second->prev = NULL;
		return (second);
	}
	second = (*stack_a)->next;
	(*stack_a)->next = second->next;
	(second->next)->prev = *stack_a;
	(*stack_a)->prev = second;
	second->next = *stack_a;
	second->prev = NULL;
	return (second);
}
