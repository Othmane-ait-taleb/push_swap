/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:49:46 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/28 11:48:37 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_ra(t_list **stack)
{
	t_list	*new_head;
	t_list	*last;

	last = ft_lstlast(*stack);
	new_head = (*stack)->next;
	(*stack)->prev = last;
	last->next = (*stack);
	(*stack)->next = NULL;
	return (new_head);
}
