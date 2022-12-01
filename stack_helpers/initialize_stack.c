/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:03:31 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/01 18:28:36 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_stack(t_list **head, int argc, char const *argv[])
{
	char	*content;
	t_list	*new;
	int		i;

	i = 1;
	*head = NULL;
	new = 0;
	content = 0;
	while (i < argc)
	{
		content = ft_strdup(argv[i++]);
		new = d_lstnew(content);
		d_lstadd_back(head, new);
	}
}
