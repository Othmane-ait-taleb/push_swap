/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_lis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:33:02 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/02 12:32:24 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	filter_lis(int *array, int *size, t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		flag;
	t_list	*last;
	t_list	*tmp;
	int		sizea;

	sizea = ft_lstsize(*stack_a);
	last = ft_lstlast(*stack_a);
	flag = 0;
	tmp = *stack_a;
	while (sizea > 0)
	{
		i = 0;
		while (i < *size)
		{
			if (ft_atoi((last)->content) == array[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 1)
		{
			*stack_a = op_ra(stack_a);
			flag = 0;
		}
		else
		{
			*stack_b = op_pb(stack_a, stack_b);
		}
		last = ft_lstlast(*stack_a);
		sizea--;
	}
}
