/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:41:47 by labderra          #+#    #+#             */
/*   Updated: 2024/04/17 19:25:28 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		p = (t_list *)malloc(sizeof(*p));
		if (!p)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		p->content = f(lst->content);
		p->next = NULL;
		ft_lstadd_back(&new, p);
		lst = lst->next;
	}
	return (new);
}
