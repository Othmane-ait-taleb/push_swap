/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_of_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:02:50 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/15 09:03:32 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_of_array(int *array_a, int size_a)
{
	int	min;
	int	i;

	min = 0;
	i = 1;
	while (i < size_a)
	{
		if (array_a[i] <= array_a[min])
			min = i;
		i++;
	}
	return (min);
}
