/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:42:55 by labderra          #+#    #+#             */
/*   Updated: 2024/05/15 11:10:39 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_ring
{
	int				item;
	struct s_ring	*next;
	struct s_ring	*prev;
}	t_ring;

t_ring  *push(t_ring *rng, int item);
int     pop(t_ring *rng);
t_ring  *rotate(t_ring *rng);
t_ring  *r_rotate(t_ring *rng);
void    clear_ring(t_ring *rng);

#endif
