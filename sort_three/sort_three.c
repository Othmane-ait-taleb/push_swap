/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:41:40 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/15 13:50:36 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sa_ra(t_list **op_list)
{
	d_lstadd_back(op_list, d_lstnew(ft_strdup("sa")));
	d_lstadd_back(op_list, d_lstnew(ft_strdup("ra")));
}

void	sort_three(t_list **stack_a, t_list **op_list)
{
	int	*array;
	int	max_index;
	int	min_index;

	if (is_sorted(*stack_a) == 0)
		exit(1);
	array = list_to_array(*stack_a, ft_lstsize(*stack_a));
	max_index = max_of_array(array, ft_lstsize(*stack_a));
	min_index = min_of_array(array, ft_lstsize(*stack_a));
	if (min_index == 1 && max_index == 2)
		d_lstadd_back(op_list, d_lstnew(ft_strdup("sa")));
	else if (min_index == 1 && max_index == 0)
		d_lstadd_back(op_list, d_lstnew(ft_strdup("ra")));
	else if (min_index == 2 && max_index == 1)
		d_lstadd_back(op_list, d_lstnew(ft_strdup("rra")));
	else if (min_index == 2 && max_index == 0)
	{
		d_lstadd_back(op_list, d_lstnew(ft_strdup("sa")));
		d_lstadd_back(op_list, d_lstnew(ft_strdup("rra")));
	}
	else if (min_index == 0 && max_index == 1)
		do_sa_ra(op_list);
	return (free(array), ft_lstiter(*op_list, pr), exit(1));
}
