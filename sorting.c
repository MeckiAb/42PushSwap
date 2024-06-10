/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:43:25 by labderra          #+#    #+#             */
/*   Updated: 2024/06/10 13:39:37 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_item(t_list **a_stack, t_list **b_stack, int target)
{
	int	cost;

	cost = item_cost(*a_stack, *b_stack, target_depth(*a_stack, target),
			item_depth(*b_stack, target));
	if (cost == target_depth(*a_stack, target)
		|| cost == item_depth(*b_stack, target))
		while (target_depth(*a_stack, target) && item_depth(*b_stack, target))
			rr(a_stack, b_stack);
	else if (cost == ft_lstsize(*a_stack) - target_depth(*a_stack, target)
		|| cost == ft_lstsize(*b_stack) - item_depth(*b_stack, target))
		while (target_depth(*a_stack, target) && item_depth(*b_stack, target))
			rrr(a_stack, b_stack);
	if (target_depth(*a_stack, target) <= ft_lstsize(*a_stack) / 2)
		while (target_depth(*a_stack, target))
			ra(a_stack);
	else
		while (target_depth(*a_stack, target))
			rra(a_stack);
	if (item_depth(*b_stack, target) <= ft_lstsize(*b_stack) / 2)
		while (item_depth(*b_stack, target))
			rb(b_stack);
	else
		while (item_depth(*b_stack, target))
			rrb(b_stack);
	pa(a_stack, b_stack);
}

static void	push_median_item(t_list **a_stack, t_list **b_stack, int median)
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
	int	median;
	int	phase;

	stack_len = ft_lstsize(*a_stack);
	if (stack_len == 3)
		sort_3_elem(a_stack);
	else if (stack_len > 3)
	{
		phase = 0;
		while (phase++ < ((stack_len > 200) + 1))
		{
			median = phase * stack_len / ((stack_len > 200) + 1);
			while (ft_lstsize(*b_stack) < median && ft_lstsize(*a_stack) > 3)
			{
				push_median_item(a_stack, b_stack, median);
				if (ft_lstsize(*b_stack) % 2 && phase != 1)
					rb(b_stack);
			}
		}
		sort_3_elem(a_stack);
		while (stack_len-- > 3)
			push_item(a_stack, b_stack, get_cheapest_item(*a_stack, *b_stack));
	}
	final_rotation(a_stack);
}
