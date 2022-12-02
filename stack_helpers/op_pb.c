/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:47:18 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/02 12:31:28 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*op_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*new_head;

	last = ft_lstlast(*stack_a);
	new_head = *stack_b;
	if (!*stack_b)
		new_head = last;
	(last->prev)->next = NULL;
	last->next = NULL;
	last->prev = NULL;
	d_lstadd_back(stack_b, last);
	return (new_head);
}
