/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:33:30 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/15 11:06:44 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	if (lst)
	{
		p = lst;
		while (p->next)
		{
			f(p->content);
			p = p->next;
		}
		if (p->next == NULL)
			f(p->content);
	}
}
