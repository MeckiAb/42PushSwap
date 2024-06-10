/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:50:31 by labderra          #+#    #+#             */
/*   Updated: 2024/06/10 12:48:49 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	get_minimum(t_list *i_stack)
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

int	get_maximum(t_list *i_stack)
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
} */
/* 
void	get_target_asc(t_list *i_stack, t_list *v_stack)
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
		route(((t_item *)(v_stack->content))->value, v_stack, temp, i_stack);
		v_stack = v_stack->next;
	}
}

void	get_target_desc(t_list *i_stack, t_list *v_stack)
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
		route(((t_item *)(v_stack->content))->value, v_stack, temp, i_stack);
		v_stack = v_stack->next;
	}
}
 */
/*t_item	*next_item(t_list *stack)
{
	t_item	*aux;

	aux = (t_item *)(stack->content);
	while (stack)
	{
		if (((t_item *)(stack->content))->steps < aux->steps)
			aux = (t_item *)(stack->content);
		stack = stack->next;
	}
	return (aux);	
}
 t_item	*next_item(t_list *stack)
{
	t_item	*aux;

	aux = (t_item *)(stack->content);
	while (stack)
	{
		if (((t_item *)(stack->content))->steps < aux->steps)
			return ((t_item *)(stack->content));
		else 
			stack = stack->next;
	}
	return (aux);	
} */