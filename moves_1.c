/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:56:51 by labderra          #+#    #+#             */
/*   Updated: 2024/05/30 16:02:35 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a_stack, t_list **b_stack)
{
	t_list	*aux;

	aux = (*b_stack)->next;
	ft_lstadd_front(a_stack, *b_stack);
	*b_stack = aux;
	ft_printf("pa\n");
}

void	pb(t_list **a_stack, t_list **b_stack)
{
	t_list	*aux;

	aux = (*a_stack)->next;
	ft_lstadd_front(b_stack, *a_stack);
	*a_stack = aux;
	ft_printf("pb\n");
}

void	sa(t_list *a_stack)
{
	t_item	*aux;

	aux = a_stack->content;
	a_stack->content = a_stack->next->content;
	a_stack->next->content = aux;
	ft_printf("sa\n");
}

void	sb(t_list *b_stack)
{
	t_item	*aux;

	aux = b_stack->content;
	b_stack->content = b_stack->next->content;
	b_stack->next->content = aux;
	ft_printf("sb\n");
}

void	ss(t_list *a_stack, t_list *b_stack)
{
	t_item	*aux;

	aux = a_stack->content;
	a_stack->content = a_stack->next->content;
	a_stack->next->content = aux;
	aux = b_stack->content;
	b_stack->content = b_stack->next->content;
	b_stack->next->content = aux;
	ft_printf("ss\n");
}
