/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:34:55 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/02 12:24:31 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*list_to_array(t_list *list, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * size);
	while (list)
	{
		array[i] = ft_atoi(list->content);
		list = list->next;
		i++;
	}
	return (array);
}

int	*alloc_array(int a, int size)
{
	int	*array;

	array = malloc(sizeof(int) * size);
	while (--size >= 0)
		array[size] = a;
	return (array);
}

int	**index_to_array(int	*array, int *length_arr, int *sub_arr, int size)
{
	int	max_index;
	int	i;
	int	*lis;
	int	*lis_size;
	int	**rtr;

	lis_size = malloc(sizeof(int));
	rtr = malloc(sizeof(int *) * 2);
	max_index = 0;
	i = 1;
	while (i < size)
	{
		if (length_arr[i] > length_arr[max_index])
		max_index = i;
		i++;
	}
	*lis_size = length_arr[max_index];
	*rtr = lis_size;
	lis = malloc(sizeof(int) * *lis_size);
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

// int	main()
// {
// 	int		i;
// 	t_list	*list;
// 	int		**a;

// 	list = 0;
// 	d_lstadd_back(&list, d_lstnew("0"));
// 	d_lstadd_back(&list, d_lstnew("4"));
// 	d_lstadd_back(&list, d_lstnew("12"));
// 	d_lstadd_back(&list, d_lstnew("2"));
// 	d_lstadd_back(&list, d_lstnew("10"));
// 	d_lstadd_back(&list, d_lstnew("6"));
// 	d_lstadd_back(&list, d_lstnew("9"));
// 	d_lstadd_back(&list, d_lstnew("13"));
// 	d_lstadd_back(&list, d_lstnew("3"));
// 	d_lstadd_back(&list, d_lstnew("11"));
// 	d_lstadd_back(&list, d_lstnew("7"));
// 	d_lstadd_back(&list, d_lstnew("15"));

// 	a = lis(list);
// 	i = 0;
// 	while (i <= 6)
// 	{
// 		printf("%d ", a[1][i++]);
// 	}
// 	return (0);
// }
