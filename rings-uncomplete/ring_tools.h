/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:42:55 by labderra          #+#    #+#             */
/*   Updated: 2024/05/21 23:37:09 by meck             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RING_TOOLS_H
# define RING_TOOLS_H

typedef struct s_ring
{
	void			*item;
	struct s_ring	*next;
	struct s_ring	*prev;
}	t_ring;

typedef struct s_item
{
	int				item;
	int				target;
	int				steps;
}	t_item;

t_ring	*push(t_ring *rng, void *item);
void	*pop(t_ring *rng);
t_ring	*rotate(t_ring *rng);
t_ring	*r_rotate(t_ring *rng);
void	clear_ring(t_ring *rng);

#endif
