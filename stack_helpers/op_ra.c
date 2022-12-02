/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:49:46 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/02 09:42:10 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_ra(t_list **stack)
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
