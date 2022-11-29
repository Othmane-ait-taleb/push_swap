/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:57:58 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/29 10:57:20 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_smallest_to_top(t_list **stack, int size, int index,
		t_list *smallest)
{
	t_list	*head;

	head = *stack;
	if (index <= size / 2)
	{
		while (head != smallest)
		{
			head = op_ra(stack);
			*stack = head;
		}
	}
	else
	{
		while (head != smallest)
		{
			head = op_rra(stack);
			*stack = head;
		}
	}
}

void	put_smallest_number_top(t_list **stack)
{
	t_list	*tmp;
	t_list	*smallest;
	int		index;
	int		size;
	t_list	*last;

	smallest = *stack;
	tmp = *stack;
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
	last = ft_lstlast(*stack);
	printf("the first is %s \n the  last is %s \n", (*stack)->content,
			(last)->content);
	rotate_smallest_to_top(stack, size, index, smallest);
	last = ft_lstlast(*stack);
	printf("the first is %s \n the  last is %s", (*stack)->content,
			(last)->content);
}

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_tmp;

	if (argc < 2 || input_checker(argc, argv) == 0)
		return (ft_putstr_fd("Error", 1), 0);
	initialize_stack(&stack_a, argc, argv);
	initialize_stack(&stack_tmp, argc, argv);
	//need to free *stack_tmp when i know the longest sub
	put_smallest_number_top(&stack_tmp);
	while(1)
		system("leaks a.out");
	return (0);
}
