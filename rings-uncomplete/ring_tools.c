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

#include "push_swap.h"

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

t_ring	*pop(t_ring *rng, void **item)
{
	t_ring	*aux;

	if (!rng)
		return (NULL);
	aux = rng;	
	if (rng->next != rng)
	{
		aux->next->prev = aux->prev;
		aux->prev->next = aux->next;
		rng = aux->next;
	}
	*item = aux->item;
	free(aux);
	return (rng);
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

t_ring	*clear_ring(t_ring *rng)
{
	t_item *item;

	while (rng->next != rng)
	{
		rng = pop(rng, &item);
		free(item);
	}
}
