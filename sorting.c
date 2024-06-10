/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:43:25 by labderra          #+#    #+#             */
/*   Updated: 2024/06/09 18:30:41 by labderra         ###   ########.fr       */
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
/* 


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
 */
int		target_depth(t_list *a_stack, int target)
{
	int depth;
	int	prev;
	int next;

	depth = 1;
	while (a_stack && a_stack->next)
	{
		prev = ((t_item *)(a_stack->content))->target;
		next = ((t_item *)(a_stack->next->content))->target;
		if ((target > prev && target < next)
			|| (target > prev && prev > next)
			|| (prev > next && target < next))
			return (depth);
		depth++;
		a_stack = a_stack->next;
	}
	return (0);
}

int	get_item_cost(t_list *a_stack, t_list *b_stack, int a_pos, int b_pos)
{
	int	route_up;
	int	route_down;
	int	route_left;
	int	route_right;

	route_up = a_pos;
	if (b_pos > a_pos)
		route_up = b_pos;
	route_down = ft_lstsize(a_stack) - a_pos;
	if ((ft_lstsize(b_stack) - b_pos) > route_down)
		route_down = ft_lstsize(b_stack) - b_pos;
	route_left = a_pos + ft_lstsize(b_stack) - b_pos;
	route_right = ft_lstsize(a_stack) - a_pos + b_pos;
	if (route_up < route_down && route_up < route_left && route_up < route_right)
		return (route_up);
	if (route_down < route_left && route_down < route_right)
		return (route_down);
	if (route_left < route_right)
		return (route_left);
	return (route_right);
}

void	get_stack_cost(t_list *a_stack, t_list *b_stack)
{
	int		a_pos;
	int		b_pos;
	t_list	*aux;

	b_pos = 0;
	aux = b_stack;
	while (aux)
	{
		a_pos = target_depth(a_stack, ((t_item *)(aux->content))->target);
		((t_item *)(aux->content))->cost = get_item_cost(a_stack, b_stack, a_pos, b_pos);
		b_pos++;
		aux = aux->next;
	}
}

int	get_cheapest_item(t_list *a_stack, t_list *b_stack)
{
	int		target;
	int		cost;
	t_list	*aux;

	get_stack_cost(a_stack, b_stack);
	aux = b_stack;
	target = ((t_item *)(aux->content))->target;
	cost = ((t_item *)(aux->content))->cost;
	while (aux)
	{
		if (((t_item *)(aux->content))->cost < cost)
		{
			cost = ((t_item *)(aux->content))->cost;
			target = ((t_item *)(aux->content))->target;
		}
		aux = aux->next;
	}
	return (target);
}

void	push_item(t_list **a_stack, t_list **b_stack, int target)
{
	int	cost;

	cost = get_item_cost(*a_stack, *b_stack, target_depth(*a_stack, target),
		item_depth(*b_stack, target));			
	if (cost == target_depth(*a_stack, target) || cost == item_depth(*b_stack, target))
		while (target_depth(*a_stack, target) && item_depth(*b_stack, target))
			rr(a_stack, b_stack);
	else if (cost == ft_lstsize(*a_stack) - target_depth(*a_stack, target)
		|| cost == ft_lstsize(*b_stack) - item_depth(*b_stack, target))
		while (target_depth(*a_stack, target) && item_depth(*b_stack, target))
			rrr(a_stack, b_stack);
	while (target_depth(*a_stack, target))
	{
		if(target_depth(*a_stack, target) <= ft_lstsize(*a_stack) / 2)
			ra(a_stack);
		else
			rra(a_stack);
	}
	while (item_depth(*b_stack, target))
		if(item_depth(*b_stack, target) <= ft_lstsize(*b_stack) / 2)
			rb(b_stack);
		else
			rrb(b_stack);
	pa(a_stack, b_stack);
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

void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%i(%i) - ", ((t_item *)(stack->content))->target, ((t_item *)(stack->content))->cost);
		stack = stack->next;
	}
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
		while (phase++ < 2)
		{
			median = phase * stack_len / 2;
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