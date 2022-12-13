/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:34:55 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/13 12:12:54 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*alloc_array(int a, int size)
{
	int	*array;

	array = malloc(sizeof(int) * size);
	if (array)
	{
		while (--size >= 0)
			array[size] = a;
	}
	return (array);
}

int	**index_to_array(int *array, int *length_arr, int *sub_arr, int size)
{
	int	max_index;
	int	i;
	int	*lis;
	int	*lis_size;
	int	**rtr;

	lis_size = malloc(sizeof(int));
	rtr = malloc(sizeof(int *) * 2);
	if (!lis_size || !rtr)
		return (NULL);
	max_index = max_of_array(length_arr, size);
	*lis_size = length_arr[max_index];
	*rtr = lis_size;
	lis = malloc(sizeof(int) * *lis_size);
	if (!lis)
		return (NULL);
	i = *lis_size;
	while (--i >= 0)
	{
		lis[i] = array[max_index];
		max_index = sub_arr[max_index];
	}
	*(rtr + 1) = lis;
	return (rtr);
}

void	find_lis(int *array, int *length_arr, int *sub_seq_arr, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i])
			{
				if (length_arr[i] <= length_arr[j] + 1)
				{
					length_arr[i] = length_arr[j] + 1;
					sub_seq_arr[i] = j;
				}
			}
			j++;
		}
		i++;
	}
}

int	**lis(t_list *list)
{
	int	*array;
	int	*length_arr;
	int	*sub_seq_arr;
	int	*size;
	int	**rtr;

	size = malloc(sizeof(int));
	*size = ft_lstsize(list);
	array = list_to_array(list, *size);
	length_arr = alloc_array(1, *size);
	sub_seq_arr = alloc_array(0, *size);
	find_lis(array, length_arr, sub_seq_arr, *size);
	rtr = index_to_array(array, length_arr, sub_seq_arr, *size);
	return (free(size), free(array), free(length_arr), free(sub_seq_arr), rtr);
}
