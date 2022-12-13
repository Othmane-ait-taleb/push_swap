/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_of_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:42:01 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/13 12:11:58 by otait-ta         ###   ########.fr       */
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
		if (array_a[i] >= array_a[max])
			max = i;
		i++;
	}
	return (max);
}
