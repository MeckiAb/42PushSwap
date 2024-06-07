/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:43:25 by labderra          #+#    #+#             */
/*   Updated: 2024/06/07 12:39:55 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_3_elem(t_list **a_stack)
{
	int	a;
	int	b;
	int	c;

	a = ((t_item *)((*a_stack)->content))->value;
	b = ((t_item *)((*a_stack)->next->content))->value;
	c = ((t_item *)((*a_stack)->next->next->content))->value;
	if (b > c && c > a)
		sa(*a_stack);
	else if (c > a && a > b)
		sa(*a_stack);
	else if (a > b && b > c)
		sa(*a_stack);
}

static void	final_rotation(t_list **stack)
{
	int		depth;
	t_list	*aux;

	depth = 0;
	aux = *stack;
	while (aux && ((t_item *)(aux->content))->target != 0)
	{
		aux = aux->next;
		depth++;
	}
	if (depth <= ft_lstsize(*stack) / 2)
		while (((t_item *)((*stack)->content))->target != 0)
			ra(stack);
	else
		while (((t_item *)((*stack)->content))->target != 0)
			rra(stack);
}

int	item_depth(t_list *stack, int target)
{
	int depth;

	depth = 0;
	while (((t_item *)(stack->content))->target != target)
	{
		depth++;
		stack = stack->next;
	}
	return (depth);
}

void	push_max_item(t_list **a_stack, t_list **b_stack, int target)
{
	int 	depth;
	t_list	*aux;

	depth = 0;
	aux = *b_stack;
	while (((t_item *)(aux->content))->target != target)
	{
		depth++;
		aux = aux->next;
	}
	if (depth <= target / 2)
		while (((t_item *)((*b_stack)->content))->target != target)
			rb(b_stack);
	else
		while (((t_item *)((*b_stack)->content))->target != target)
			rrb(b_stack);
	pa(a_stack, b_stack);
}

int		target_depth(t_list *a_stack, int target)
{
	int		depth;

	depth = 1;
	while (a_stack && a_stack->next)
	{
		if (((t_item *)(a_stack->content))->target < target 
			&& ((t_item *)(a_stack->next->content))->target > target)
			return (depth);
		depth++;
		a_stack = a_stack->next;
	}
	return (0);
}

void	push_in_place(t_list **a_stack, t_list **b_stack, int target)
{
	t_list	*aux;
	int		cost;
	int		depth;

	aux = *b_stack;
	depth = 0;
	while (aux)
	{
		cost = target_depth(*a_stack, ((t_item *)(aux->content))->target) + depth;
		if (depth <= ft_lstsize(*b_stack) && cost <= ft_lstsize(*b_stack))
			((t_item *)(aux->content))->target = 0;
		else if (depth > ft_lstsize(*b_stack) && cost > ft_lstsize(*b_stack))
			((t_item *)(aux->content))->target = 0;
		else if (depth > ft_lstsize(*b_stack) && cost > ft_lstsize(*b_stack))
			((t_item *)(aux->content))->target = 0;
		else (depth <= ft_lstsize(*b_stack) && cost <= ft_lstsize(*b_stack))
			((t_item *)(aux->content))->target = 0;


		depth++;
		aux = aux->next;
}

void	push_median_item(t_list **a_stack, t_list **b_stack, int median)
{
	t_list	*aux;
	int		depth;
	int		first;
	int		last;

	aux = *a_stack;
	depth = 0;
	first = -1;
	while (aux)
	{
		if (((t_item *)(aux->content))->target < median)
			last = depth;
		if (((t_item *)(aux->content))->target < median && first == -1)
			first = depth;
		aux = aux->next;
		depth++;
	}
	if (first <= depth - last)
		while (((t_item *)((*a_stack)->content))->target >= median)
			ra(a_stack);
	else
		while (((t_item *)((*a_stack)->content))->target >= median)
			rra(a_stack);
	pb(a_stack, b_stack);
}

void	sort(t_list **a_stack, t_list **b_stack)
{
	int	stack_len;
	int median;
	int	phase;

	stack_len = ft_lstsize(*a_stack);
	if (stack_len == 3)
		sort_3_elem(a_stack);
	else if (stack_len > 3)
	{
		phase = 0;
		while (phase++ < 6)
		{
			median = phase * stack_len / 6;
			while (ft_lstsize(*b_stack) < median)// && ft_lstsize(*a_stack) > 3)
			{
				push_median_item(a_stack, b_stack, median);
				if (ft_lstsize(*b_stack) % 2)
					rb(b_stack);
			}
		}
		while (stack_len--)
			push_max_item(a_stack, b_stack, stack_len);
	}
	final_rotation(a_stack);
}