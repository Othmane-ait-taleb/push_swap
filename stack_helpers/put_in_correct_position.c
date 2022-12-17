/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_correct_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:06:47 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/15 10:39:49 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_number_between(int *array_a, int size_a, int number, int *flag)
{
	int	i;
	int	moves;

	i = 0;
	moves = 0;
	while (i < size_a - 1)
	{
		if (number > array_a[i] && number < array_a[i + 1])
		{
			moves = i + 1;
			*flag = 1;
			break ;
		}
		i++;
	}
	return (moves);
}

int	pos_in_a(int *array_a, int size_a, int number)
{
	int	moves;
	int	flag;

	flag = 0;
	if (number > array_a[size_a - 1] && number < array_a[0])
	{
		moves = 0;
		flag = 1;
	}
	moves = check_number_between(array_a, size_a, number, &flag);
	if (flag == 0)
		moves = max_of_array(array_a, size_a) + 1;
	if (moves == 0)
		return (0);
	else if (moves > size_a / 2)
		return (-(size_a - moves));
	return ((moves));
}

int	**put_in_correct_position(t_list **stack_a, int size_a, t_list **stack_b,
		int size_b)
{
	int	*array_a;
	int	*array_b;
	int	**pos_tab;
	int	*tmp;
	int	i;

	array_a = list_to_array(*stack_a, size_a);
	array_b = list_to_array(*stack_b, size_b);
	pos_tab = malloc(sizeof(int *) * size_b);
	if (!pos_tab)
		return (NULL);
	i = 0;
	while (i < size_b)
	{
		tmp = malloc(sizeof(int) * 2);
		if (!tmp)
			return (NULL);
		if (i <= size_b / 2)
			tmp[0] = i;
		else
			tmp[0] = -(size_b - i);
		tmp[1] = pos_in_a(array_a, size_a, array_b[i]);
		pos_tab[i++] = tmp;
	}
	return (free(array_a), free(array_b), pos_tab);
}
