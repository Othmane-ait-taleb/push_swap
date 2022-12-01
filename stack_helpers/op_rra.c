/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:50:03 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/01 10:16:59 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_rra(t_list **stack)
{
	t_list	*new_head;
	t_list	*last;

	new_head = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	new_head->prev = NULL;
	(*stack)->next = NULL;

	return (new_head);
}
