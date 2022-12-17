/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:33:49 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 12:11:14 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*tmp_stack;
	int		length;

	length = 0;
	tmp_stack = stack;
	while (tmp_stack)
	{
		if (tmp_stack->next
			&& ft_atoi(tmp_stack->content) > ft_atoi(tmp_stack->next->content))
		{
			return (1);
		}
		length++;
		tmp_stack = tmp_stack->next;
	}
	if (length == 0)
	{
		return (1);
	}
	return (0);
}
