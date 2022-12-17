/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:49:56 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/16 11:57:19 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_move(char *move)
{
	if (ft_strcmp(move, "ra\n") == 0)
		return (0);
	if (ft_strcmp(move, "rb\n") == 0)
		return (1);
	if (ft_strcmp(move, "pb\n") == 0)
		return (2);
	if (ft_strcmp(move, "rrb\n") == 0)
		return (3);
	if (ft_strcmp(move, "rr\n") == 0)
		return (4);
	if (ft_strcmp(move, "pa\n") == 0)
		return (5);
	if (ft_strcmp(move, "rra\n") == 0)
		return (6);
	if (ft_strcmp(move, "rrr\n") == 0)
		return (7);
	if (ft_strcmp(move, "sb\n") == 0)
		return (8);
	if (ft_strcmp(move, "sa\n") == 0)
		return (9);
	if (ft_strcmp(move, "ss\n") == 0)
		return (10);
	return (-1);
}

int	check_valid_move(char *move)
{
	int	result;

	result = is_valid_move(move);
	if (result != -1)
		return (result);
	else
		return (-1);
}

void	validate_moves(t_list **stack_a, t_list **stack_b, int fd)
{
	char	*move;
	int		type_move;

	move = get_next_line(fd);
	while (move != NULL)
	{
		if (*move == '\n')
		{
			free(move);
			return ;
		}
		type_move = check_valid_move(move);
		if (type_move == -1)
		{
			free(move);
			ft_putstr_fd("Error", 2);
			ft_lstclear(stack_a, free);
			ft_lstclear(stack_b, free);
			exit(1);
		}
		else
			perform_move(stack_a, stack_b, type_move);
		free(move);
		move = get_next_line(0);
	}
}

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_tmp;

	stack_a = 0;
	stack_b = 0;
	if (argc < 2 || input_checker(argc, argv, &stack_a, &stack_tmp) == 0
		|| check_duplicates(stack_a))
	{
		ft_lstclear(&stack_tmp, free);
		ft_lstclear(&stack_a, free);
		return (ft_putstr_fd("Error", 2), 0);
	}
	ft_lstclear(&stack_tmp, free);
	validate_moves(&stack_a, &stack_b, 0);
	if (stack_b || is_sorted(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
