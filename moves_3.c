/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:01:23 by labderra          #+#    #+#             */
/*   Updated: 2024/05/30 16:36:14 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a_stack)
{
	t_list	*aux;

	aux = *a_stack;
	while (aux->next != ft_lstlast(aux))
		aux = aux->next;
	ft_lstadd_front(a_stack, aux->next);
	aux->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_list **b_stack)
{
	t_list	*aux;

	aux = *b_stack;
	while (aux->next != ft_lstlast(aux))
		aux = aux->next;
	ft_lstadd_front(b_stack, aux->next);
	aux->next = NULL;
	ft_printf("rrb\n");
}

void	rrr(t_list **a_stack, t_list **b_stack)
{
	t_list	*aux;

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
	ft_printf("rrr\n");
}
