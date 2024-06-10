/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:02:19 by labderra          #+#    #+#             */
/*   Updated: 2024/06/10 13:28:55 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	item_depth(t_list *stack, int target)
{
	int	depth;

	depth = 0;
	while (((t_item *)(stack->content))->target != target)
	{
		depth++;
		stack = stack->next;
	}
	return (depth);
}

int	target_depth(t_list *a_stack, int target)
{
	int	depth;
	int	prev;
	int	next;

	depth = 1;
	while (a_stack && a_stack->next)
	{
		prev = ((t_item *)(a_stack->content))->target;
		next = ((t_item *)(a_stack->next->content))->target;
		if ((target > prev && target < next)
			|| (target > prev && prev > next)
			|| (prev > next && target < next))
			return (depth);
		depth++;
		a_stack = a_stack->next;
	}
	return (0);
}

int	item_cost(t_list *a_stack, t_list *b_stack, int a_pos, int b_pos)
{
	int	route_up;
	int	route_down;
	int	route_left;
	int	route_right;

	route_up = a_pos;
	if (b_pos > a_pos)
		route_up = b_pos;
	route_down = ft_lstsize(a_stack) - a_pos;
	if ((ft_lstsize(b_stack) - b_pos) > route_down)
		route_down = ft_lstsize(b_stack) - b_pos;
	route_left = a_pos + ft_lstsize(b_stack) - b_pos;
	route_right = ft_lstsize(a_stack) - a_pos + b_pos;
	if (route_up < route_down && route_up < route_left
		&& route_up < route_right)
		return (route_up);
	if (route_down < route_left && route_down < route_right)
		return (route_down);
	if (route_left < route_right)
		return (route_left);
	return (route_right);
}

static void	get_stack_cost(t_list *a_stack, t_list *b_stack)
{
	int		a_pos;
	int		b_pos;
	t_list	*aux;

	b_pos = 0;
	aux = b_stack;
	while (aux)
	{
		a_pos = target_depth(a_stack, ((t_item *)(aux->content))->target);
		((t_item *)(aux->content))->cost
			= item_cost(a_stack, b_stack, a_pos, b_pos);
		b_pos++;
		aux = aux->next;
	}
}

int	get_cheapest_item(t_list *a_stack, t_list *b_stack)
{
	int		target;
	int		cost;
	t_list	*aux;

	get_stack_cost(a_stack, b_stack);
	aux = b_stack;
	target = ((t_item *)(aux->content))->target;
	cost = ((t_item *)(aux->content))->cost;
	while (aux)
	{
		if (((t_item *)(aux->content))->cost < cost)
		{
			cost = ((t_item *)(aux->content))->cost;
			target = ((t_item *)(aux->content))->target;
		}
		aux = aux->next;
	}
	return (target);
}
