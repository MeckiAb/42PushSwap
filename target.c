/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:50:31 by labderra          #+#    #+#             */
/*   Updated: 2024/06/02 13:32:15 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_minimum(t_list *i_stack)
{
	int	temp;

	temp = 2147483647;
	while (i_stack)
	{
		if (((t_item *)(i_stack->content))->value < temp)
			temp = ((t_item *)(i_stack->content))->value;
		i_stack = i_stack->next;
	}
	return (temp);
}

static int	get_maximum(t_list *i_stack)
{
	int	temp;

	temp = -2147483648;
	while (i_stack)
	{
		if (((t_item *)(i_stack->content))->value > temp)
			temp = ((t_item *)(i_stack->content))->value;
		i_stack = i_stack->next;
	}
	return (temp);
}

void	get_prev_target(t_list *i_stack, t_list *v_stack)
{
	t_list	*aux;
	int		index;
	int		temp;

	while (v_stack)
	{
		aux = i_stack;
		temp = 2147483647;
		while (aux)
		{
			index = ((t_item *)(aux->content))->value;
			if (index > ((t_item *)(v_stack->content))->value && index < temp)
				temp = index;
			aux = aux->next;
		}
		if (temp == 2147483647)
			temp = get_minimum(i_stack);
		((t_item *)(v_stack->content))->target = temp;
		v_stack = v_stack->next;
	}
}

void	get_next_target(t_list *i_stack, t_list *v_stack)
{
	t_list	*aux;
	int		index;
	int		temp;

	while (v_stack)
	{
		aux = i_stack;
		temp = -2147483648;
		while (aux)
		{
			index = ((t_item *)(aux->content))->value;
			if (index < ((t_item *)(v_stack->content))->value && index > temp)
				temp = index;
			aux = aux->next;
		}
		if (temp == -2147483648)
			temp = get_maximum(i_stack);
		((t_item *)(v_stack->content))->target = temp;
		v_stack = v_stack->next;
	}
}
