/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:03:31 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/28 08:27:08 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_stack(t_list **head, int argc, char const *argv[])
{
	char	*content;
	int		i;

	i = 1;
	*head = NULL;
	while (i < argc)
	{
		content = ft_strdup(argv[i]);
		d_lstadd_back(head, d_lstnew(content));
		i++;
	}
}
