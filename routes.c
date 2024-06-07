/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:08:53 by labderra          #+#    #+#             */
/*   Updated: 2024/06/07 11:38:57 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
static int	north(int value, t_list *v_stack, int target, t_list *t_stack)
{
	int	depth_v;
	int	depth_t;

	depth_v = 0;
	while (v_stack && ((t_item *)(v_stack->content))->value != value)
	{
		v_stack = v_stack->next;
		depth_v++;
	}
	depth_t = 0;
	while (t_stack && ((t_item *)(t_stack->content))->value != target)
	{
		t_stack = t_stack->next;
		depth_t++;
	}
	if (depth_v >= depth_t)
		return (depth_v + 1);
	else
		return (depth_t + 1);
}

static int	south(int value, t_list *v_stack, int target, t_list *t_stack)
{
	int	depth_v;
	int	depth_t;

	depth_v = ft_lstsize(v_stack);
	while (v_stack && ((t_item *)(v_stack->content))->value != value)
	{
		v_stack = v_stack->next;
		depth_v--;
	}
	depth_t = ft_lstsize(t_stack);
	while (t_stack && ((t_item *)(t_stack->content))->value != target)
	{
		t_stack = t_stack->next;
		depth_t--;
	}
	if (depth_v >= depth_t)
		return (depth_v + 1);
	else
		return (depth_t + 1);
}

static int	east(int value, t_list *v_stack, int target, t_list *t_stack)
{
	int	depth_v;
	int	depth_t;

	depth_v = 0;
	while (v_stack && ((t_item *)(v_stack->content))->value != value)
	{
		v_stack = v_stack->next;
		depth_v++;
	}
	depth_t = ft_lstsize(t_stack);
	while (t_stack && ((t_item *)(t_stack->content))->value != target)
	{
		t_stack = t_stack->next;
		depth_t--;
	}
	return (depth_t + depth_v + 1);
}

static int	west(int value, t_list *v_stack, int target, t_list *t_stack)
{
	int	depth_v;
	int	depth_t;

	depth_v = ft_lstsize(v_stack);
	while (v_stack && ((t_item *)(v_stack->content))->value != value)
	{
		v_stack = v_stack->next;
		depth_v--;
	}
	depth_t = 0;
	while (t_stack && ((t_item *)(t_stack->content))->value != target)
	{
		t_stack = t_stack->next;
		depth_t++;
	}
	return (depth_t + depth_v + 1);
}

void	route(int value, t_list *v_stack, int target, t_list *t_stack)
{
	int		steps;
	char	route;

	steps = north(value, v_stack, target, t_stack);
	route = 'n';
	if (south(value, v_stack, target, t_stack) < steps)
	{
		steps = south(value, v_stack, target, t_stack);
		route = 's';
	}
	if (east(value, v_stack, target, t_stack) < steps)
	{
		steps = east(value, v_stack, target, t_stack);
		route = 'e';
	}
	if (west(value, v_stack, target, t_stack) < steps)
	{
		steps = west(value, v_stack, target, t_stack);
		route = 'w';
	}
	while (v_stack && ((t_item *)(v_stack->content))->value != value)
		v_stack = v_stack->next;
	((t_item *)(v_stack->content))->steps = steps;
	((t_item *)(v_stack->content))->route = route;
}
 */