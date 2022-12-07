/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_lis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:33:02 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/04 11:19:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_content(t_list *node, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_atoi(node->content) == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	not_lis(t_list *stack_a, int *array, int size_a, int size_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size_a)
	{
		j = 0;
		while (j < size_array)
		{
			if (ft_atoi(stack_a->content) == array[j])
				break ;
			j++;
		}
		if (j == size_array)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

void	filter_lis(int **array_and_size, t_list **stack_a, t_list **stack_b,
		t_list **op_list)
{
	int		flag;
	t_list	*last;
	t_list	*tmp;
	int		size_a;

	op_list = (t_list **)op_list;
	size_a = ft_lstsize(*stack_a);
	last = ft_lstlast(*stack_a);
	flag = 0;
	tmp = *stack_a;
	while (size_a > 0 && not_lis(*stack_a, array_and_size[1],
			ft_lstsize(*stack_a), *array_and_size[0]) == 0)
	{
		flag = check_content(last, array_and_size[1], *array_and_size[0]);
		if (flag == 1)
		{
			*stack_a = op_ra(stack_a);
			ft_lstadd_back(op_list, ft_lstnew(ft_strdup("ra")));
		}
		else
		{
			*stack_b = op_pb(stack_a, stack_b);
			ft_lstadd_back(op_list, ft_lstnew(ft_strdup("pb")));
		}
		last = ft_lstlast(*stack_a);
		size_a--;
	}
}
