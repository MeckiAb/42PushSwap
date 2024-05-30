/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:01:15 by labderra          #+#    #+#             */
/*   Updated: 2024/05/30 15:58:31 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chk_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (((t_item *)(stack->content))->value > 
			((t_item *)(stack->next->content))->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
/* 
static void	print_stack(void *content)
{
	ft_printf("%i\t", ((t_item *)content)->value);
}
 */
int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = chk_input(argc, argv, a_stack);
	if (!a_stack)
		return (0);
	if (chk_sorted(a_stack))
		return (ft_printf("ordenado\n"), 0);
/* 
	ft_printf("\nStack A :\t");
	ft_lstiter(a_stack, &print_stack);
	ft_printf("\nStack B :\t");
	ft_lstiter(b_stack, &print_stack);
	
	pb(&a_stack, &b_stack);
	pb(&a_stack, &b_stack);
	
	ft_printf("\nStack A :\t");
	ft_lstiter(a_stack, &print_stack);
	ft_printf("\nStack B :\t");
	ft_lstiter(b_stack, &print_stack);

	ss(a_stack, b_stack);
	
	ft_printf("\nStack A :\t");
	ft_lstiter(a_stack, &print_stack);
	ft_printf("\nStack B :\t");
	ft_lstiter(b_stack, &print_stack);
 */
	return (0);
}
