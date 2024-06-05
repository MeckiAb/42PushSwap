/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:43:25 by labderra          #+#    #+#             */
/*   Updated: 2024/06/05 20:45:46 by labderra         ###   ########.fr       */
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

/* static void	final_rotation(t_list **stack)
{
	int		min;
	int		depth;
	int		stack_size;
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
		while (depth-- > 0)
			ra(stack);
	else
		while (depth++ < stack_size)
			rra(stack);
} */

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

void	move_item_ab(t_item *item, t_list **a_stack, t_list **b_stack)
{
	if (item->route == 'n')
		while (((t_item *)((*a_stack)->content))->value != item->value
			&& ((t_item *)((*b_stack)->content))->value != item->target)
			rr(a_stack, b_stack);
	else if (item->route == 's')
		while (((t_item *)((*a_stack)->content))->value != item->value
			&& ((t_item *)((*b_stack)->content))->value != item->target)
			rrr(a_stack, b_stack);
	if (item->route == 'n' || item->route == 'e')		
		while (((t_item *)((*a_stack)->content))->value != item->value)
			ra(a_stack);
	else
		while (((t_item *)((*a_stack)->content))->value != item->value)
			rra(a_stack);
	if (item->route == 'n' || item->route == 'w')	
		while (((t_item *)((*b_stack)->content))->value != item->target)
			rb(b_stack);
	else
		while (((t_item *)((*b_stack)->content))->value != item->target)
			rrb(b_stack);
	pb(a_stack, b_stack);		
}

void	move_item_ba(t_item *item, t_list **a_stack, t_list **b_stack)
{
	if (item->route == 'n')
		while (((t_item *)((*b_stack)->content))->value != item->value
			&& ((t_item *)((*a_stack)->content))->value != item->target)
			rr(a_stack, b_stack);
	else if (item->route == 's')
		while (((t_item *)((*b_stack)->content))->value != item->value
			&& ((t_item *)((*a_stack)->content))->value != item->target)
			rrr(a_stack, b_stack);
	if (item->route == 'n' || item->route == 'e')		
		while (((t_item *)((*b_stack)->content))->value != item->value)
			rb(b_stack);
	else
		while (((t_item *)((*b_stack)->content))->value != item->value)
			rrb(b_stack);
	if (item->route == 'n' || item->route == 'w')	
		while (((t_item *)((*a_stack)->content))->value != item->target)
			ra(a_stack);
	else
		while (((t_item *)((*a_stack)->content))->value != item->target)
			rra(a_stack);
	pa(a_stack, b_stack);		
}
/* 
void	sort(t_list **a_stack, t_list **b_stack)
{
	int	stack_len;

	stack_len = ft_lstsize(*a_stack);
	if (stack_len == 2)
		sa(*a_stack);
	else if (stack_len == 3)
	{
		sort_3_elem(a_stack);
		final_rotation(a_stack);
	}
	else if (chk_rotate_sorted_asc(*a_stack))
		final_rotation(a_stack);
	else
	{
		pb(a_stack, b_stack);
		while (ft_lstsize(*a_stack) > 3 && !chk_rotate_sorted_asc(*a_stack))
		{
			//pb(a_stack,b_stack);
			get_target_desc(*b_stack, *a_stack);
			move_item_ab(get_next_item(*a_stack), a_stack, b_stack);
		}
		sort_3_elem(a_stack);
		while (*b_stack)
		{
			get_target_asc(*a_stack, *b_stack);
			move_item_ba(get_next_item(*b_stack), a_stack, b_stack);
		}
		final_rotation(a_stack);
	}
}
 */

void	sort(t_list **a_stack, t_list **b_stack)
{
	int	stack_len;
	int median;

	stack_len = ft_lstsize(*a_stack);
	if (stack_len == 2)
		sa(*a_stack);
	else if (stack_len == 3)
	{
		sort_3_elem(a_stack);
		final_rotation(a_stack);
	}
	else if (chk_rotate_sorted_asc(*a_stack))
		final_rotation(a_stack);
	else
	{
		while (ft_lstsize(*a_stack) > 3 && !chk_rotate_sorted_asc(*a_stack))
		{
			median = (get_maximum(*a_stack) - get_minimum(*a_stack)) / 5;
			while (ft_lstsize(*b_stack) < stack_len / 5)
				if (((t_item *)((*a_stack)->content))->value < median)
					pb(a_stack,b_stack);
				else
					ra(a_stack);
			median = 2 * (get_maximum(*a_stack) - get_minimum(*a_stack)) / 5;
			while (ft_lstsize(*b_stack) < 2 * stack_len / 5)
				if (((t_item *)((*a_stack)->content))->value < median)
				{
					pb(a_stack,b_stack);
					rb(b_stack);
				}
				else
					ra(a_stack);
			median = 3 * (get_maximum(*a_stack) - get_minimum(*a_stack)) / 5;
			while (ft_lstsize(*b_stack) < 3 * stack_len / 5)
				if (((t_item *)((*a_stack)->content))->value < median)
					pb(a_stack,b_stack);
				else
					ra(a_stack);
			median = 4 * (get_maximum(*a_stack) - get_minimum(*a_stack)) / 5;
			while (ft_lstsize(*b_stack) < 4 * stack_len / 5)
				if (((t_item *)((*a_stack)->content))->value < median)
				{
					pb(a_stack,b_stack);
					rb(b_stack);
				}
				else
					ra(a_stack);
			median = 5 * (get_maximum(*a_stack) - get_minimum(*a_stack)) / 5;
			while (ft_lstsize(*a_stack) > 2)
				if (((t_item *)((*a_stack)->content))->value < median)
				{
					pb(a_stack,b_stack);
					rb(b_stack);
				}
				else
					ra(a_stack);
		}
		/* while (*b_stack && *a_stack && !chk_rotate_sorted_asc(*a_stack) && !chk_rotate_sorted_desc(*b_stack))
		{
			get_target_desc(*b_stack, *a_stack);
			get_target_asc(*a_stack, *b_stack);
			if (next_item(*a_stack)->steps <= next_item(*b_stack)->steps)
				move_item_ab(next_item(*a_stack), a_stack, b_stack);
			else
				move_item_ba(next_item(*b_stack), a_stack, b_stack);
		} */
		while (*b_stack)
		{
			get_target_asc(*a_stack, *b_stack);
			move_item_ba(next_item(*b_stack), a_stack, b_stack);
		}
		final_rotation(a_stack);
	}
}