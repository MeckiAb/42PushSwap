/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:43:25 by labderra          #+#    #+#             */
/*   Updated: 2024/06/06 14:41:02 by labderra         ###   ########.fr       */
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


void	sort(t_list **a_stack, t_list **b_stack)
{
	int	stack_len;
	int median;
	int	phase;
	
//	int	aux_int;
//	t_list	*aux;

	stack_len = ft_lstsize(*a_stack);
	if (stack_len == 2)
		sa(*a_stack);
	else if (stack_len == 3)
	{
		sort_3_elem(a_stack);
		final_rotation(a_stack);
	}
	else if (chk_rotate_sorted(*a_stack))
		final_rotation(a_stack);
	else
	{
		phase = 0;
		while (phase++ < 10)
		{
			median = phase * stack_len / 10;
			while (ft_lstsize(*b_stack) < median)
				if (((t_item *)((*a_stack)->content))->target < median)
				{
					pb(a_stack,b_stack);
					if (phase % 2)
						rb(b_stack);
				}
				else
					ra(a_stack);
/* ft_printf("tamaños: %i - %i\n", ft_lstsize(*a_stack), ft_lstsize(*b_stack));
			scanf("%i", &aux_int);

aux_int = ft_lstsize(*b_stack);
aux = *b_stack;
while (aux_int--)
{
	ft_printf("%i - %i\n", ((t_item *)(aux->content))->value,
		((t_item *)(aux->content))->target);
	aux = aux->next;
} */
		} 

//			scanf("%i", &aux_int);
		//}
		/* while (*b_stack && *a_stack && !chk_rotate_sorted_asc(*a_stack) && !chk_rotate_sorted_desc(*b_stack))
		{
			get_target_desc(*b_stack, *a_stack);
			get_target_asc(*a_stack, *b_stack);
			if (next_item(*a_stack)->steps <= next_item(*b_stack)->steps)
				move_item_ab(next_item(*a_stack), a_stack, b_stack);
			else
				move_item_ba(next_item(*b_stack), a_stack, b_stack);
		} */
		while (stack_len--)
		{
			if (item_depth(*b_stack, stack_len) <= stack_len / 2)
				while (((t_item *)((*b_stack)->content))->target != stack_len)
					rb(b_stack);
			else
				while (((t_item *)((*b_stack)->content))->target != stack_len)
					rrb(b_stack);
			pa(a_stack, b_stack);
		}
		final_rotation(a_stack);
	}
}