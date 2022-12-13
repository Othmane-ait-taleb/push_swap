/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:57:48 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/12 15:14:37 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void reverse_stack(t_list **stack)
{
	char *tmp;
	t_list *last;
	t_list *first;
	int		size;
	int		i;
	
	i = 0;
	size = ft_lstsize(*stack);
	last = ft_lstlast(*stack);
	first = *stack;
	while (i < size / 2)
	{
		tmp = first->content;
		first->content = last->content;
		last->content = tmp;
		first = first->next;
		last = last->prev;
		i++;
	}
}