/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_correct_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:06:47 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/07 10:36:01 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_of_array(int *array_a, int size_a)
{
	int	max;
	int	i;

	max = 0;
	i = 1;
	while (i < size_a)
	{
		if (array_a[i] > array_a[max])
			max = i;
		i++;
	}
	return (max);
}

int	pos_in_a(int *array_a, int size_a, int number)
{
	int	moves;
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (number > array_a[size_a - 1] && number < array_a[0])
	{
		moves = 0;
		flag = 1;
	}
	while (i < size_a)
	{
		if (number > array_a[i] && number < array_a[i + 1])
		{
			moves = i + 1;
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		moves = max_of_array(array_a, size_a);
	if (moves < size_a / 2)
		return (moves);
	return ((size_a - moves - 1) * -1);
}

int	**put_in_correct_position(t_list **stack_a, t_list **stack_b)
{
	int size_a;
	int size_b;
	int *array_a;
	int *array_b;
	int **pos_tab;
	int *tmp;
	int i;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	array_a = list_to_array(*stack_a, size_a);
	array_b = list_to_array(*stack_b, size_b);
	pos_tab = malloc(sizeof(int *) * size_a);
	//cas 1
	i = 0;
	while (i < size_b)
	{
		tmp = malloc(sizeof(int) * 2);
		if (i <= size_b / 2)
		{
			//b moves
			tmp[0] = i;
			// a moves
			tmp[1] = pos_in_a(array_a, size_a, array_b[i]);
		}
		else
		{
			tmp[0] = -(size_b - i);
			tmp[1] = pos_in_a(array_a, size_a, array_b[i]);
		}
		pos_tab[i] = tmp;
		i++;
	}
	return (pos_tab);
}