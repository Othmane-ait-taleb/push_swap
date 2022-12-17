/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:57:58 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 12:32:36 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_smallest_boot(t_list **stack, int index, t_list *smallest,
		t_list **op_list)
{
	t_list	*boot;
	int		size;

	size = ft_lstsize(*stack);
	boot = *stack;
	if (index <= size / 2)
	{
		while (boot != smallest)
		{
			*stack = op_ra(stack);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("ra")));
			boot = *stack;
		}
	}
	else
	{
		while (boot != smallest)
		{
			*stack = op_rra(stack);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rra")));
			boot = *stack;
		}
	}
}

void	put_smallest_number_boot(t_list **stack, t_list **op_list)
{
	t_list	*tmp;
	t_list	*smallest;
	int		index;
	int		size;

	smallest = *stack;
	tmp = (*stack)->next;
	size = 0;
	index = 0;
	while (tmp)
	{
		size++;
		if (ft_atoi(smallest->content) > ft_atoi((tmp)->content))
		{
			index = size;
			smallest = (tmp);
		}
		tmp = (tmp)->next;
	}
	rotate_smallest_boot(stack, index, smallest, op_list);
}

void	new_positions(t_list **stack_a, t_list **stack_b, t_list **op_list)
{
	int	i;
	int	j;
	int	**pos;

	i = ft_lstsize(*stack_b);
	while (i > 0)
	{
		j = ft_lstsize(*stack_b);
		pos = put_in_correct_position(stack_a, ft_lstsize(*stack_a), stack_b,
				ft_lstsize(*stack_b));
		apply_moves(pos, stack_a, stack_b, op_list);
		free(pos);
		i--;
	}
}

void	clear_leaks(t_list **stack_a, t_list **stack_b, t_list **op_list)
{
	return (ft_lstclear(stack_a, free), ft_lstclear(stack_b, free),
		ft_lstclear(op_list, free), free(op_list));
}

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_tmp;
	int		**lis_and_size;
	t_list	**op_list;

	if (argc == 1)
		return (1);
	if (input_checker(argc, argv, &stack_a, &stack_tmp) == 0
		|| check_duplicates(stack_a))
		return (ft_putstr_fd("Error", 2), 0);
	op_list = malloc(sizeof(t_list *));
	if (!op_list)
		return (ft_putstr_fd("Error", 2), 0);
	*op_list = 0;
	if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a, op_list);
	put_smallest_number_boot(&stack_tmp, op_list);
	ft_lstclear(op_list, free);
	lis_and_size = lis(stack_tmp);
	ft_lstclear(&stack_tmp, free);
	filter_lis(lis_and_size, &stack_a, &stack_b, op_list);
	new_positions(&stack_a, &stack_b, op_list);
	return (put_smallest_number_boot(&stack_a, op_list), ft_lstiter(*op_list,
			pr), clear_leaks(&stack_a, &stack_b, op_list), 0);
}
