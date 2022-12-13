/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:47:25 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/10 08:45:59 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*min_moves(int **tab, int size_b)
{
	int	i;
	int	a_moves;
	int	b_moves;
	int	*min;
	int	min_value;

	i = 1;
	min = tab[0];
	min_value = absolute_value(tab[0][0]) + absolute_value(tab[0][1]);
	while (i < size_b)
	{
		b_moves = absolute_value(tab[i][0]);
		a_moves = absolute_value(tab[i][1]);
		if (a_moves + b_moves < min_value)
		{
			free(min);
			min_value = a_moves + b_moves;
			min = tab[i];
		}
		else
			free(tab[i]);
		i++;
	}
	return (min);
}
