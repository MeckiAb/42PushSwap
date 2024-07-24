/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:01:08 by labderra          #+#    #+#             */
/*   Updated: 2024/07/24 09:22:59 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	t_list	*aux;

	if (stack && *stack)
	{
		aux = *stack;
		*stack = (*stack)->next;
		aux->next = NULL;
		ft_lstadd_back(stack, aux);
	}
	ft_printf("ra\n");
}

void	rb(t_list **stack)
{
	t_list	*aux;

	if (stack && *stack)
	{
		aux = *stack;
		*stack = (*stack)->next;
		aux->next = NULL;
		ft_lstadd_back(stack, aux);
	}
	ft_printf("rb\n");
}

void	rr(t_list **a_stack, t_list **b_stack)
{
	t_list	*aux;

	if (a_stack && b_stack && *a_stack && *b_stack)
	{
		aux = *a_stack;
		*a_stack = (*a_stack)->next;
		aux->next = NULL;
		ft_lstadd_back(a_stack, aux);
		aux = *b_stack;
		*b_stack = (*b_stack)->next;
		aux->next = NULL;
		ft_lstadd_back(b_stack, aux);
	}
	ft_printf("rr\n");
}
