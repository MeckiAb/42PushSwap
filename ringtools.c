/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringtools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:49:07 by labderra          #+#    #+#             */
/*   Updated: 2024/05/15 11:10:33 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ring	*push(t_ring *rng, int item)
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

int		pop(t_ring *rng)
{
	int	item;

	if (!rng)
		return (0);
	item = rng->item;
	rng->next->prev = rng->prev;
	rng->prev->next = rng->next;
	free(rng);
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

void	clear_ring(t_ring *rng)
{
	while (rng->next != rng)
		pop(rng);
	free(rng);
}
