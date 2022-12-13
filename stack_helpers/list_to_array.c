/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:38:19 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/07 12:52:18 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*list_to_array(t_list *list, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (array)
	{
		while (list)
		{
			array[i] = ft_atoi(list->content);
			list = list->next;
			i++;
		}
	}
	return (array);
}
