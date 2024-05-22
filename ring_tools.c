/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:49:07 by labderra          #+#    #+#             */
/*   Updated: 2024/05/21 12:15:00 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ring_tools.h"

t_ring	*push(t_ring *rng, void *item)
{
	t_ring	*new;

	new = (t_ring *)malloc(sizeof(t_ring));
	if (!new)
		return (clear_ring(rng), NULL);
	if (!rng)
	{
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->next = rng;
		new->prev = rng->prev;
		new->next->prev = new;
		new->prev->next = new;
	}
	new->item = item;
	return (new);
}

void	*pop(t_ring **rng, void (*del_item)(void *))
{
	void	*item;
	t_ring	*p;

	if (!rng)
		return (NULL);
	p = *rng;
	item = p->item;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	(*del_item)(p->item);
	*rng = p->next;
	free(p);
	return (item);
}

t_ring	*rotate(t_ring *rng)
{
	if (!rng)
		return (NULL);
	return (rng->next);
}

t_ring	*r_rotate(t_ring *rng)
{
	if (!rng)
		return (NULL);
	return (rng->prev);
}

void	clear_ring(t_ring **rng)
{
	while (rng)
		free(pop(rng));
}
