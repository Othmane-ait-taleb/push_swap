/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_smallest_number_top.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:36:42 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/12 10:37:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	rotate_smallest_top(t_list **stack, int index, t_list *smallest,
		t_list **op_list)
{
	t_list	*top;
	int		size;

	size = ft_lstsize(*stack);
	top = ft_lstlast(*stack);
	if (index >= size / 2)
	{
		while (top != smallest)
		{
			*stack = op_ra(stack);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("ra")));
			top = ft_lstlast(*stack);
		}
	}
	else
	{
		while (top != smallest)
		{
			*stack = op_rra(stack);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rra")));
			top = ft_lstlast(*stack);
		}
	}
}

void	put_smallest_number_top(t_list **stack, t_list **op_list)
{
	t_list *tmp;
	t_list *smallest;
	int index;
	int size;

	smallest = *stack;
	tmp = (*stack)->next;
	size = 0;
	index = 0;
	while (tmp)
	{
		size++;
		if (ft_atoi(smallest->content) > ft_atoi((tmp)->content))
		{
			index = size;
			smallest = (tmp);
		}
		tmp = (tmp)->next;
	}
	rotate_smallest_top(stack, index, smallest, op_list);
}