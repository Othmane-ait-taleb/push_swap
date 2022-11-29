/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_lstnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:33:58 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/27 09:34:54 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*d_lstnew(void *content)
{
	t_list	*rtr;

	rtr = malloc(sizeof(t_list));
	if (!rtr)
		return (NULL);
	rtr->content = content;
	rtr->next = NULL;
	rtr->prev = NULL;
	return (rtr);
}
