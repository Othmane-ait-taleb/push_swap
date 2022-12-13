/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:39:14 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/12 09:40:36 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_stack_reverse(t_list **head, int argc, char const *argv[])

{
	char	*content;
	t_list	*new;
	int i;

	i = argc;
	*head = NULL;
	new = 0;
	content = 0;
	while (--argc > 0)
	{
		content = ft_strdup(argv[argc]);
		new = d_lstnew(content);
		d_lstadd_back(head, new);
	}
}