/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:57:58 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/01 20:17:30 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_smallest_to_top(t_list **stack, int size, int index,
		t_list *smallest)
{
	t_list	*new_head;

	if (index <= size / 2)
	{
		while (*stack != smallest)
		{
			new_head = op_rra(stack);
			*stack = new_head;
		}
	}
	else
	{
		while (*stack != smallest)
		{
			new_head = op_ra(stack);
			*stack = new_head;
		}
	}
}

void	put_smallest_number_top(t_list **stack)
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
	rotate_smallest_to_top(stack, size, index, smallest);
}
void f(){system("leaks a.out");}
void pr(void *a){printf("this is %s",a);}

int	main(int argc, char const *argv[])
{
	//atexit(f);
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_tmp;
	int		**lis_and_size;
	int		lis_size;

	int i = 0;
	stack_a = 0;
	if (argc < 2 || input_checker(argc, argv) == 0)
		return (ft_putstr_fd("Error", 1), 0);
	initialize_stack(&stack_a, argc, argv);
	initialize_stack(&stack_tmp, argc, argv);
	put_smallest_number_top(&stack_tmp);
	lis_and_size = lis(stack_tmp);
	filter_lis(lis_and_size[1], lis_and_size[0],stack_a, stack_b);
	ft_lstiter(stack_b,pr);
	// ft_lstclear(&stack_a, free);
	// ft_lstclear(&stack_tmp, free);
	// free(lis_and_size);
	// //system("leaks a.out");
	return (0);
}
