/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:43:25 by labderra          #+#    #+#             */
/*   Updated: 2024/06/03 08:48:26 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chk_rotate_sorted(t_list *stack)
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

static void	final_rotation(t_list **stack)
{
	int	min;
	int	depth;
	int	stack_size;
	t_list	*aux;

	min = get_minimum(*stack);
	depth = 0;
	aux = *stack;
	while (aux && ((t_item *)(aux->content))->value != min)
	{
		aux = aux->next;
		depth++;
	}
	stack_size = ft_lstsize(*stack);
	if (depth <= stack_size / 2)
		while(depth-- > 0)
			ra(stack);
	else
		while (depth++ < stack_size)
			rra(stack);
}

void	sort(t_list **a_stack, t_list **b_stack)
{
	*b_stack = NULL;
	if (ft_lstsize(*a_stack) == 2)
		sa(*a_stack);
	else if (ft_lstsize(*a_stack) == 3)
		sort_3_elem(a_stack);
	else
	{	
		get_prev_target(*a_stack, *a_stack);
		if (chk_rotate_sorted(*a_stack))
			final_rotation(a_stack);
		//else	
	}	
}
