/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:34:55 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/29 16:57:17 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*list_to_array(t_list *list)
{
	int	*array;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(list);
	array = malloc(sizeof(int) * size);
	while (list)
	{
		array[i] = ft_atoi(list->content);
		list = list->next;
		i++;
	}
	return (array);
}

int	*alloc_array(t_list *list, int a)
{
	int	size;
	int	*array;

	size = ft_lstsize(list);
	array = malloc(sizeof(int) * size);
	while (--size >= 0)
		array[size] = a;
	return (array);
}

int	*index_to_array(int	*array, int	*indexes)
{
	
}
int	*lis(t_list *list)
{
	int	*array;
	int	*length_arr;
	int	*sub_seq_arr;
	int	i;
	int	j;
	int	*rtr;

	// need to free after finish
	array = list_to_array(list);
	length_arr = alloc_array(list, 1);
	sub_seq_arr = alloc_array(list, 0);
	i = 1;
	j = 0;
	while (i < ft_lstsize(list))
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
	//rtr = index_to_array(array, sub_seq_arr);
	return (sub_seq_arr);
}

int	main(int argc, char const *argv[])
{
	int		i;
	t_list	*list;
	int		*a;

	d_lstadd_back(&list, d_lstnew("0"));
	d_lstadd_back(&list, d_lstnew("1"));
	d_lstadd_back(&list, d_lstnew("6"));
	d_lstadd_back(&list, d_lstnew("2"));
	d_lstadd_back(&list, d_lstnew("3"));
	d_lstadd_back(&list, d_lstnew("4"));
	d_lstadd_back(&list, d_lstnew("1"));
	d_lstadd_back(&list, d_lstnew("5"));
	d_lstadd_back(&list, d_lstnew("6"));
	d_lstadd_back(&list, d_lstnew("1"));
	d_lstadd_back(&list, d_lstnew("0"));
	d_lstadd_back(&list, d_lstnew("1"));
	a = lis(list);
	i = 0;
	while (i < 12)
	{
		printf("%d ", a[i++]);
	}
	return (0);
}
