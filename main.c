/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:57:58 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/13 12:48:19 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_smallest_boot(t_list **stack, int index, t_list *smallest,
		t_list **op_list)
{
	t_list	*new_head;
	t_list	*boot;
	int		size;

	size = ft_lstsize(*stack);
	boot = *stack;
	if (index <= size / 2)
	{
		while (boot != smallest)
		{
			new_head = op_ra(stack);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("ra")));
			*stack = new_head;
			boot = *stack;
		}
	}
	else
	{
		while (boot != smallest)
		{
			new_head = op_rra(stack);
			d_lstadd_back(op_list, d_lstnew(ft_strdup("rra")));
			*stack = new_head;
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
void	f(void)
{
	system("leaks a.out");
}
void	pr(void *a)
{
	printf("%s\n", a);
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
	int		j;

	//atexit(f);
	i = 0;
	stack_a = 0;
	if (argc < 2 || input_checker(argc, argv) == 0)
		return (ft_putstr_fd("Error", 1), 0);
	initialize_stack(&stack_a, argc, argv);
	
	initialize_stack(&stack_tmp, argc, argv);
	op_list = malloc(sizeof(t_list *));
	if (!op_list)
		return (ft_putstr_fd("Error", 1), 0);
	*op_list = 0;
	put_smallest_number_boot(&stack_tmp, op_list);
	ft_lstclear(op_list, free);
	lis_and_size = lis(stack_tmp);
	// printf("lis is : \n");
	// while (i < lis_and_size[0][0])
	// 	printf("%d \n", lis_and_size[1][i++]);
	ft_lstclear(&stack_tmp, free);
	//reverse_stack(&stack_a);
	filter_lis(lis_and_size, &stack_a, &stack_b, op_list);
	free(lis_and_size[0]);
	free(lis_and_size[1]);
	free(lis_and_size);
	// printf("\na stack   ///////// \n");
	// ft_lstiter(stack_a, pr);
	// printf("\nb stack ///////// \n");
	// ft_lstiter(stack_b, pr);
	i = ft_lstsize(stack_b);
	while (i > 0)
	{
		j = ft_lstsize(stack_b);
		pos = put_in_correct_position(&stack_a, ft_lstsize(stack_a), &stack_b,
				ft_lstsize(stack_b));
				
		apply_moves(pos, &stack_a, &stack_b, op_list);
		free(pos);
	// printf("\nB stack ///////// \n");
	// ft_lstiter(stack_b, pr);
		i--;
	}

	put_smallest_number_boot(&stack_a, op_list);
	// printf("\na stack ///////// \n");
	// ft_lstiter(stack_a, pr);
	// printf("*************************** \n");
	ft_lstiter(*op_list, pr);
	//printf("\n %d move ///////// \n", ft_lstsize(*op_list));
	// // ft_lstiter(stack_b, pr);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	ft_lstclear(op_list, free);
	free(op_list);
	// //system("leaks a.out");
	return (0);
}
