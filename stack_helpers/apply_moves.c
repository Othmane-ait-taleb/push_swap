/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:04:26 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/13 10:20:39 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	positive_moves(int *moves, t_list **stack_a, t_list **stack_b,
		t_list **op_list)
{
	int	i;

	i = 0;
	if (moves[0] == moves[1])
	{
		while (i++ < moves[1])
		{
			op_rr(stack_a, stack_b);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rr")));
		}
		return ;
	}
	i = 0;
	while (i++ < min(moves[0], moves[1]))
	{
		op_rr(stack_a, stack_b);
		d_lstadd_back(op_list, d_lstnew(ft_strdup("rr")));
	}
	i = 0;
	if (max(moves[0], moves[1]) == moves[0])
	{
		while (i++ < moves[0] - moves[1])
		{
			*stack_b = op_rb(stack_b);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rb")));
		}
	}
	else
	{
		while (i++ < absolute_value(moves[1]) - absolute_value(moves[0]))
		{
			*stack_a = op_ra(stack_a);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("ra")));
		}
	}
}

void	negative_moves(int *moves, t_list **stack_a, t_list **stack_b,
		t_list **op_list)
{
	int	i;

	i = 0;
	if (moves[0] == moves[1])
	{
		while (i-- > moves[0])
		{
			op_rrr(stack_a, stack_b);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rrr")));
		}
		return ;
	}
	while (i-- > max(moves[0], moves[1]))
	{
		op_rrr(stack_a, stack_b);
		d_lstadd_back(op_list, d_lstnew(ft_strdup("rrr")));
	}
	i = 0;
	if (min(moves[0], moves[1]) == moves[0])
	{
		while (i-- > (moves[0] - moves[1]))
		{
			*stack_b = op_rrb(stack_b);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rrb")));
		}
	}
	else
	{
		while (i-- > (moves[1] - moves[0]))
		{
			*stack_a = op_rra(stack_a);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rra")));
		}
	}
}

void	handle_b_moves(int moves, t_list **stack_b, t_list **op_list)
{
	int	i;

	i = 0;
	if (moves > 0)
	{
		while (i < moves)
		{
			*stack_b = op_rb(stack_b);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rb")));
			i++;
		}
	}
	else if (moves < 0)
	{
		while (i-- > moves)
		{
			*stack_b = op_rrb(stack_b);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rrb")));
		}
	}
}

void	handle_a_moves(int moves, t_list **stack_a, t_list **op_list)
{
	int	i;

	i = 0;
	if (moves > 0)
	{
		while (i < moves)
		{
			//t = malloc(1);
			*stack_a = op_ra(stack_a);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("ra")));
			i++;
		}
	}
	else if (moves < 0)
	{
		while (i-- > moves)
		{
			*stack_a = op_rra(stack_a);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rra")));
		}
	}
}

void	apply_moves(int **pos_tab, t_list **stack_a, t_list **stack_b,
		t_list **op_list)
{
	int	*moves;

	moves = min_moves(pos_tab, ft_lstsize(*stack_b));
	//printf("\n MIN VALUES : b moves : %d a moves : %d\n", moves[0], moves[1]);
	if (moves[0] < 0 && (moves[0] * moves[1]) > 0)
		negative_moves(moves, stack_a, stack_b, op_list);
	else if (moves[0] > 0 && (moves[0] * moves[1]) > 0)
		positive_moves(moves, stack_a, stack_b, op_list);
	else
	{
		handle_b_moves(moves[0], stack_b, op_list);
		handle_a_moves(moves[1], stack_a, op_list);
	}
	*stack_b = op_pa(stack_a, stack_b);
	d_lstadd_back(op_list, d_lstnew(ft_strdup("pa")));
	free(moves);
}
