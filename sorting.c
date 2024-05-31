/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:43:25 by labderra          #+#    #+#             */
/*   Updated: 2024/05/31 17:37:20 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_rotate_sorted(t_list *stack)
{
	t_list	*aux;

	aux = stack;
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

static void	sort_3_elem(t_list **a_stack)
{
	int	a;
	int	b;
	int	c;

	a = ((t_item *)((*a_stack)->content))->value;
	b = ((t_item *)((*a_stack)->next->content))->value;
	c = ((t_item *)((*a_stack)->next->next->content))->value;
	if (b > c && c > a)
	{
		sa(*a_stack);
		ra(a_stack);
	}
	else if (c > a && a > b)
		sa(*a_stack);
	else if (b > a && a > c)
		rra(a_stack);
	else if (a > c && c > b)
		ra(a_stack);
	else
	{
		ra(a_stack);
		sa(*a_stack);
	}
}

void	sort(t_list **a_stack, t_list **b_stack)
{
	if (ft_lstsize(*a_stack) == 2)
		sa(*a_stack);
	else if (ft_lstsize(*a_stack) == 3)
		sort_3_elem(a_stack);
	else
		pb(a_stack, b_stack);
}