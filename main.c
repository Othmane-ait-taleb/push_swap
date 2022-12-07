/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:57:58 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/07 10:32:39 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_smallest_to_top(t_list **stack, int size, int index,
		t_list *smallest)
{
	t_list	*new_head;
	t_list	*top;

	top = *stack;
	if (index <= size / 2)
	{
		while (top != smallest)
		{
			new_head = op_ra(stack);
			*stack = new_head;
			top = *stack;
		}
	}
	else
	{
		while (top != smallest)
		{
			new_head = op_rra(stack);
			*stack = new_head;
			top = *stack;
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
void	f(void)
{
	system("leaks a.out");
}
void	pr(void *a)
{
	printf("this is %s \n", a);
}

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_tmp;
	int		**lis_and_size;
	int		lis_size;
	t_list	**op_list;
	int		i;
	int		**pos;
	
	//atexit(f);
	i = 0;
	stack_a = 0;
	if (argc < 2 || input_checker(argc, argv) == 0)
		return (ft_putstr_fd("Error", 1), 0);
	initialize_stack(&stack_a, argc, argv);
	initialize_stack(&stack_tmp, argc, argv);
	put_smallest_number_top(&stack_tmp);
	lis_and_size = lis(stack_tmp);
	ft_lstclear(&stack_tmp, free);
	op_list = malloc(sizeof(t_list *));
	*op_list = 0;
	filter_lis(lis_and_size, &stack_a, &stack_b, op_list);
	free(lis_and_size[0]);
	free(lis_and_size[1]);
	free(lis_and_size);
	pos = put_in_correct_position(&stack_a, &stack_b);
	printf("a stack ///////// \n");
	ft_lstiter(stack_a, pr);
	printf("b stack ///////// \n");
	ft_lstiter(stack_b, pr);
	printf("possitions : \n");
	printf("moves a %d \n",pos[0][1]);
	//printf("moves b %d",pos[0][0]);
	//ft_lstiter(*op_list, pr);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	ft_lstclear(op_list, free);
	free(op_list);
	//system("leaks a.out");
	return (0);
}
