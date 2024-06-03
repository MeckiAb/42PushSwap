/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:12:09 by labderra          #+#    #+#             */
/*   Updated: 2024/06/03 18:14:39 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_rotate_sorted_asc(t_list *stack)
{
	t_list	*aux;

	aux = stack;
	get_target_asc(stack, stack);
	while (stack && stack->next)
	{
		if (((t_item *)(stack->content))->target !=
			((t_item *)(stack->next->content))->value)
			return (0);
		stack = stack->next;
	}
	if (((t_item *)(stack->content))->target !=
	((t_item *)(aux->content))->value)
		return (0);
	return (1);
}

int	chk_rotate_sorted_desc(t_list *stack)
{
	t_list	*aux;

	aux = stack;
	get_target_desc(stack, stack);
	while (stack && stack->next)
	{
		if (((t_item *)(stack->content))->value !=
			((t_item *)(stack->next->content))->target)
			return (0);
		stack = stack->next;
	}
	if (((t_item *)(stack->content))->value !=
	((t_item *)(aux->content))->target)
		return (0);
	return (1);
}

int	chk_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (((t_item *)(stack->content))->value >
			((t_item *)(stack->next->content))->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}