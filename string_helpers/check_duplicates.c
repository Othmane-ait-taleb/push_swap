/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:27:32 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 11:36:20 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_duplicates(t_list *stack)
{
	int	*array;
	int	size;
	int	i;
	int	j;

	size = ft_lstsize(stack);
	array = list_to_array(stack, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] == array[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (free(array), 0);
}
