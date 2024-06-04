/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:01:15 by labderra          #+#    #+#             */
/*   Updated: 2024/06/04 11:35:39 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	a_stack = NULL;
	b_stack = NULL;
	if (argc == 1)
		return (0);
	a_stack = chk_input(argc, argv, a_stack);
	if (!a_stack)
		return (ft_printf("Error.\n"), 0);
	if (chk_sorted(a_stack))
		return (0);
	sort(&a_stack, &b_stack);
	ft_lstclear(&a_stack, &del_item);
 	return (0);
}


/*	ERROR WITH 0 ENTRY
		- fails as argument or var, prompts error. 
		- posible issue with itoa
		- PROBLEM FIXED IN chk_dup

	ROUTE ERROR
		- route should be north, east instead.
		- stuck in first move rrb
	*/