/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:50:03 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/12 16:31:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_rra(t_list **stack)
{
	t_list	*new_head;
	t_list	*last;

	last = ft_lstlast(*stack);
	new_head = last;
	(last->prev)->next = NULL;
	new_head->next = *stack;
	(*stack)->prev = new_head;
	new_head->prev = NULL;
	return (new_head);
}

