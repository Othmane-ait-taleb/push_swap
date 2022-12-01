/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_lis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:33:02 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/01 12:36:22 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	filter_lis(int	*array, int *size, t_list *stack_a, t_list *stack_b)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	while (stack_a)
	{
		while (i < *size)
		{			
			if (ft_atoi((stack_a)->content) == array[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 1)
		{
			op_ra(&stack_a);
			flag = 0;
		}
		else
			op_pb(&stack_a, &stack_b);
		stack_a = ((stack_a)->next);
	}
}
