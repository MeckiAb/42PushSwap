/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:01:23 by labderra          #+#    #+#             */
/*   Updated: 2024/07/24 09:34:11 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a_stack)
{
	t_list	*aux;

	if (a_stack && *a_stack)
	{
		aux = *a_stack;
		while (aux->next != ft_lstlast(aux))
			aux = aux->next;
		ft_lstadd_front(a_stack, aux->next);
		aux->next = NULL;
	}
	ft_printf("rra\n");
}

void	rrb(t_list **b_stack)
{
	t_list	*aux;

	if (b_stack && *b_stack)
	{
		aux = *b_stack;
		while (aux->next != ft_lstlast(aux))
			aux = aux->next;
		ft_lstadd_front(b_stack, aux->next);
		aux->next = NULL;
	}
	ft_printf("rrb\n");
}

void	rrr(t_list **a_stack, t_list **b_stack)
{
	t_list	*aux;

	if (a_stack && b_stack && *a_stack && *b_stack)
	{
		aux = *a_stack;
		while (aux->next != ft_lstlast(aux))
			aux = aux->next;
		ft_lstadd_front(a_stack, aux->next);
		aux->next = NULL;
		aux = *b_stack;
		while (aux->next != ft_lstlast(aux))
			aux = aux->next;
		ft_lstadd_front(b_stack, aux->next);
		aux->next = NULL;
	}
	ft_printf("rrr\n");
}
