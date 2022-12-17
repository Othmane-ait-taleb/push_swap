/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:49:46 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 12:49:49 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_rb(t_list **stack)
{
	t_list	*new_head;
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack) <= 1)
		return (*stack);
	first = *stack;
	last = ft_lstlast(*stack);
	new_head = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	new_head->prev = NULL;
	return (new_head);
}
